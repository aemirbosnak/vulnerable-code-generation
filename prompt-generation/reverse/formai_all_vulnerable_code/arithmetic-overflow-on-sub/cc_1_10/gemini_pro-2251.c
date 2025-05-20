//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

// Socket operations
int create_socket(char *host, char *port) {
    struct addrinfo hints, *res;
    int sockfd;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, port, &hints, &res) != 0) {
        perror("getaddrinfo");
        return -1;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) != 0) {
        perror("connect");
        return -1;
    }

    freeaddrinfo(res);
    return sockfd;
}

void close_socket(int sockfd) {
    if (sockfd != -1) {
        close(sockfd);
    }
}

// String operations
char *read_line(int sockfd) {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    do {
        nread = getline(&line, &len, stdin);
        if (nread == -1) {
            perror("getline");
            return NULL;
        }

        if (line[nread - 1] == '\n') {
            line[nread - 1] = '\0';
        }
    } while (strcmp(line, "") == 0);

    return line;
}

void write_line(int sockfd, char *line) {
    if (write(sockfd, line, strlen(line)) == -1) {
        perror("write");
    }
}

// HTTP operations
char *create_request(char *host, char *path, char *method) {
    char *request = NULL;
    size_t len = 0;

    len = strlen(method) + strlen(path) + strlen(host) + 200;
    request = malloc(len);
    if (request == NULL) {
        perror("malloc");
        return NULL;
    }

    snprintf(request, len, "%s %s HTTP/1.1\r\nHost: %s\r\n\r\n", method, path, host);
    return request;
}

void forward_request(int sockfd_client, int sockfd_server) {
    char *line;

    line = read_line(sockfd_client);
    while (line != NULL) {
        write_line(sockfd_server, line);
        free(line);
        line = read_line(sockfd_client);
    }
}

void forward_response(int sockfd_client, int sockfd_server) {
    char buffer[1024];
    ssize_t nread;

    while ((nread = read(sockfd_server, buffer, sizeof(buffer))) > 0) {
        if (write(sockfd_client, buffer, nread) == -1) {
            perror("write");
            break;
        }
    }

    if (nread == -1) {
        perror("read");
    }
}

// Main program
int main(int argc, char *argv[]) {
    int sockfd_client, sockfd_server;
    char *host, *port, *path, *method;

    if (argc != 5) {
        fprintf(stderr, "Usage: %s host port path method\n", argv[0]);
        return EXIT_FAILURE;
    }

    host = argv[1];
    port = argv[2];
    path = argv[3];
    method = argv[4];

    sockfd_client = create_socket(NULL, "0");
    if (sockfd_client == -1) {
        return EXIT_FAILURE;
    }

    sockfd_server = create_socket(host, port);
    if (sockfd_server == -1) {
        close_socket(sockfd_client);
        return EXIT_FAILURE;
    }

    write_line(sockfd_server, create_request(host, path, method));
    forward_request(sockfd_client, sockfd_server);
    forward_response(sockfd_client, sockfd_server);

    close_socket(sockfd_client);
    close_socket(sockfd_server);
    return EXIT_SUCCESS;
}