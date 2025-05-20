//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int proxy_socket, client_socket, remote_socket;
    struct sockaddr_in server_addr, client_addr, remote_addr;
    char buffer[BUFFER_SIZE];
    char *http_request;
    char *remote_address;
    int server_port, client_len, remote_len, bytes;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_address> <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    remote_address = argv[1];
    server_port = atoi(argv[2]);

    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket == -1) {
        perror("Failed to open socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(server_port);

    if (bind(proxy_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind");
        exit(EXIT_FAILURE);
    }

    if (listen(proxy_socket, 3) == -1) {
        perror("Failed to listen");
        exit(EXIT_FAILURE);
    }

    printf("HTTP-proxy running on port %d...\n\n", server_port);

    client_len = sizeof(client_addr);
    while (true) {
        client_socket = accept(proxy_socket, (struct sockaddr*)&client_addr, &client_len);
        if (client_socket == -1) {
            perror("Failed to accept connection");
            exit(EXIT_FAILURE);
        }

        printf("Connected with client %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        http_request = (char*)malloc(BUFFER_SIZE);
        bytes = recv(client_socket, http_request, BUFFER_SIZE, 0);
        if (bytes == -1) {
            perror("Failed to receive data");
            exit(EXIT_FAILURE);
        }

        http_request[bytes] = '\0';

        printf("HTTP Request:\n%s\n\n", http_request);

        const char *protocol = strtok(http_request, " ");
        const char *url = strtok(NULL, " ");
        strtok(NULL, " ");

        char *temp = strtok(NULL, "\r\n");

        while(temp != NULL && temp[0] != '\r' && temp[1] != '\n') {
            const char *header_name = strtok(temp, ":");
            const char *header_value = strtok(NULL, "\r\n");
            temp = strtok(NULL, "\r\n");
        }

        int remote_port = 80;
        char *remote_path = "/";
        char *http_version = "HTTP/1.0";

        char *url_parts = strtok(url, "/");
        char *domain = url_parts;

        while (url_parts != NULL) {
            remote_path = url_parts;
            url_parts = strtok(NULL, "/");
        }

        struct hostent* host_info;
        host_info = gethostbyname(domain);
        if (host_info == NULL) {
            fprintf(stderr, "Failed to resolve host: %s\n", domain);
            exit(EXIT_FAILURE);
        }

        remote_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (remote_socket == -1) {
            perror("Failed to open socket");
            exit(EXIT_FAILURE);
        }

        memset(&remote_addr, 0, sizeof(remote_addr));
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_addr = *((struct in_addr*)host_info->h_addr);
        remote_addr.sin_port = htons(remote_port);

        remote_len = sizeof(remote_addr);
        if (connect(remote_socket, (struct sockaddr*)&remote_addr, remote_len) == -1) {
            perror("Failed to connect to remote server");
            exit(EXIT_FAILURE);
        }

        char remote_request[BUFFER_SIZE];
        snprintf(remote_request, BUFFER_SIZE, "GET /%s %s\r\nHost: %s\r\nConnection: close\r\n\r\n", remote_path, http_version, domain);

        printf("Forwarding request to remote server...\n%s\n", remote_request);

        if (send(remote_socket, remote_request, strlen(remote_request), 0) == -1) {
            perror("Failed to send request to remote server");
            exit(EXIT_FAILURE);
        }

        printf("Waiting for response from remote server...\n");

        while (true) {
            bytes = recv(remote_socket, buffer, BUFFER_SIZE, 0);
            if (bytes == -1) {
                perror("Failed to receive data from remote server");
                exit(EXIT_FAILURE);
            }

            if (bytes == 0) {
                break;
            }

            if (send(client_socket, buffer, bytes, 0) == -1) {
                perror("Failed to forward data to client");
                exit(EXIT_FAILURE);
            }
        }

        printf("Finished processing request.\n\n");

        free(http_request);
        close(client_socket);
        close(remote_socket);
    }

    return 0;
}