//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

char* get_request(int client_sock) {
    char buffer[BUFFER_SIZE], *request = NULL;
    ssize_t nread;
    while ((nread = recv(client_sock, buffer, BUFFER_SIZE, 0)) > 0) {
        request = realloc(request, nread+1);
        strncat(request, buffer, nread);
        if (strcmp(buffer+nread-4, "\r\n\r\n") == 0) break;
    }
    return request;
}

void forward_request(int server_sock, char* request) {
    send(server_sock, request, strlen(request), 0);
}

void forward_response(int client_sock, int server_sock) {
    char buffer[BUFFER_SIZE];
    ssize_t nread;
    while ((nread = recv(server_sock, buffer, BUFFER_SIZE, 0)) > 0) {
        send(client_sock, buffer, nread, 0);
    }
}

void handle_client(int client_sock, struct sockaddr_in server_address) {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(server_sock, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Connect() failed");
        exit(1);
    }
    char* request = get_request(client_sock);
    forward_request(server_sock, request);
    forward_response(client_sock, server_sock);
    close(client_sock);
    close(server_sock);
    free(request);
}

void start_server(int proxy_port, char* server_ip, int server_port) {
    struct sockaddr_in proxy_address, server_address;
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Socket() failed");
        exit(1);
    }
    memset(&proxy_address, 0, sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_address.sin_port = htons(proxy_port);
    if (bind(server_sock, (struct sockaddr*) &proxy_address, sizeof(proxy_address)) < 0) {
        perror("Bind() failed");
        exit(1);
    }
    if (listen(server_sock, SOMAXCONN) < 0) {
        perror("Listen() failed");
        exit(1);
    }
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(server_port);
    printf("Proxy server started on port %d, forwarding requests to %s:%d\n", proxy_port, server_ip, server_port);
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_sock = accept(server_sock, (struct sockaddr*) &client_address, &client_address_len);
        if (client_sock < 0) {
            perror("Accept() failed");
            continue;
        }
        if (fork() == 0) {
            handle_client(client_sock, server_address);
            exit(0);
        }
        close(client_sock);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s proxy_port server_ip server_port\n", argv[0]);
        exit(1);
    }
    int proxy_port = atoi(argv[1]);
    char* server_ip = argv[2];
    int server_port = atoi(argv[3]);
    start_server(proxy_port, server_ip, server_port);
    return 0;
}