//Code Llama-13B DATASET v1.0 Category: Firewall ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <stdarg.h>

#define BUF_SIZE 1024
#define PORT 8080
#define TIMEOUT 5
#define MAX_CONN 5

void handle_client(int connfd);
void send_response(int connfd, const char *msg);
void log_message(const char *msg, ...);

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listenfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listenfd, MAX_CONN) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        connfd = accept(listenfd, (struct sockaddr *)&client_addr, &client_len);
        if (connfd < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        handle_client(connfd);
    }

    return 0;
}

void handle_client(int connfd) {
    char buf[BUF_SIZE];
    memset(buf, 0, BUF_SIZE);

    int n = recv(connfd, buf, BUF_SIZE, 0);
    if (n < 0) {
        perror("Recv failed");
        return;
    }

    char *req = strtok(buf, " ");
    if (strcmp(req, "GET") != 0) {
        send_response(connfd, "HTTP/1.1 405 Method Not Allowed\r\n\r\n");
        return;
    }

    char *path = strtok(NULL, " ");
    if (strcmp(path, "/") != 0) {
        send_response(connfd, "HTTP/1.1 404 Not Found\r\n\r\n");
        return;
    }

    send_response(connfd, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Welcome to my server!</h1></body></html>\r\n");
}

void send_response(int connfd, const char *msg) {
    send(connfd, msg, strlen(msg), 0);
}

void log_message(const char *msg, ...) {
    va_list args;
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    va_end(args);
}