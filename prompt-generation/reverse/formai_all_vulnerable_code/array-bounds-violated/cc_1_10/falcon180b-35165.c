//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_REQUEST_SIZE 1024
#define MAX_RESPONSE_SIZE 4096
#define SERVER_PORT 8080
#define ROOT_DIRECTORY "./www"
#define INDEX_FILE "index.html"

void handle_request(int client_socket);

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 10) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Web server started on port %d\n", SERVER_PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        handle_request(client_socket);
        close(client_socket);
    }

    return 0;
}

void handle_request(int client_socket) {
    char request[MAX_REQUEST_SIZE];
    memset(request, 0, sizeof(request));

    int bytes_received = 0;
    while (bytes_received < MAX_REQUEST_SIZE && (bytes_received = recv(client_socket, request + bytes_received, MAX_REQUEST_SIZE - bytes_received, 0))!= 0) {
        if (bytes_received == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }
    }

    request[bytes_received] = '\0';
    printf("Received request: %s\n", request);

    char response[MAX_RESPONSE_SIZE];
    memset(response, 0, sizeof(response));

    strcat(response, "HTTP/1.1 200 OK\r\n");
    strcat(response, "Content-Type: text/html\r\n");
    strcat(response, "Connection: close\r\n");
    strcat(response, "\r\n");

    char file_path[1024];
    snprintf(file_path, sizeof(file_path), "%s/%s", ROOT_DIRECTORY, request);

    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        strcat(response, "File not found.\r\n");
        send(client_socket, response, strlen(response), 0);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        strcat(response, buffer);
    }

    fclose(file);

    send(client_socket, response, strlen(response), 0);
}