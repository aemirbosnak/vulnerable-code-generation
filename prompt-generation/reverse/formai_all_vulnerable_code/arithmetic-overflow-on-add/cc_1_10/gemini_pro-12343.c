//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    char *host;
    int port;
} connection_t;

connection_t *create_connection(char *host, int port) {
    connection_t *conn = malloc(sizeof(connection_t));
    if (!conn) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    conn->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (conn->sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    conn->addr.sin_family = AF_INET;
    conn->addr.sin_port = htons(port);
    conn->addr.sin_addr.s_addr = inet_addr(host);

    conn->host = strdup(host);
    conn->port = port;

    return conn;
}

void close_connection(connection_t *conn) {
    close(conn->sockfd);
    free(conn->host);
    free(conn);
}

int send_request(connection_t *conn, char *request) {
    int len = strlen(request);
    int sent = 0;

    while (sent < len) {
        int n = send(conn->sockfd, request + sent, len - sent, 0);
        if (n < 0) {
            perror("send");
            return -1;
        }
        sent += n;
    }

    return 0;
}

char *recv_response(connection_t *conn) {
    char *buffer = malloc(MAX_BUFFER_SIZE);
    if (!buffer) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    int len = 0;

    while ((len = recv(conn->sockfd, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        char *new_buffer = realloc(buffer, len + MAX_BUFFER_SIZE);
        if (!new_buffer) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        buffer = new_buffer;
    }

    if (len < 0) {
        perror("recv");
        free(buffer);
        return NULL;
    }

    return buffer;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    connection_t *conn = create_connection(host, port);

    char request[MAX_BUFFER_SIZE];
    printf("Enter your request:\n");
    fgets(request, MAX_BUFFER_SIZE, stdin);

    if (send_request(conn, request) < 0) {
        perror("send_request");
        close_connection(conn);
        exit(EXIT_FAILURE);
    }

    char *response = recv_response(conn);
    if (!response) {
        perror("recv_response");
        close_connection(conn);
        exit(EXIT_FAILURE);
    }

    printf("Response:\n%s", response);

    close_connection(conn);

    return EXIT_SUCCESS;
}