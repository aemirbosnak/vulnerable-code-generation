//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define MAX_URL_LENGTH 2048

void parse_url(const char *url, char *host, char *path) {
    const char *http = "http://";
    if (strncmp(url, http, strlen(http)) != 0) {
        fprintf(stderr, "URL must start with 'http://'\n");
        exit(EXIT_FAILURE);
    }

    const char *start = url + strlen(http);
    const char *end = strchr(start, '/');
    if (end == NULL) {
        strcpy(host, start);
        strcpy(path, "/");
    } else {
        strncpy(host, start, end - start);
        host[end - start] = '\0';
        strcpy(path, end);
    }
}

int create_socket(const char *host, int port) {
    struct sockaddr_in server_addr;
    struct hostent *host_entry;
    
    host_entry = gethostbyname(host);
    if (host_entry == NULL) {
        fprintf(stderr, "Could not resolve host: %s\n", host);
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host_entry->h_addr, host_entry->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void send_request(int sockfd, const char *host, const char *path) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
    send(sockfd, request, strlen(request), 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    while (1) {
        ssize_t bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <http://url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char host[MAX_URL_LENGTH];
    char path[MAX_URL_LENGTH];

    parse_url(argv[1], host, path);
    int sockfd = create_socket(host, 80);

    send_request(sockfd, host, path);
    receive_response(sockfd);

    close(sockfd);
    return EXIT_SUCCESS;
}