//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define LINE_SIZE 80
#define PORT 8080

int main(int argc, char *argv[]) {
    int server_socket, client_socket, bytes_received;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE], request[LINE_SIZE];
    char *token;
    char *method, *uri, *version;

    if(argc!= 2) {
        printf("Usage:./proxy <IP_Address>\n");
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if(connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server at %s:%d\n", inet_ntoa(server_addr.sin_addr), PORT);

    while(1) {
        bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0);

        if(bytes_received <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        buffer[bytes_received] = '\0';

        printf("Received data: %s", buffer);

        token = strtok(buffer, " ");

        if(token == NULL) {
            continue;
        }

        method = strtok(NULL, " ");
        uri = strtok(NULL, " ");
        version = strtok(NULL, " ");

        if(method == NULL || uri == NULL) {
            continue;
        }

        sprintf(request, "%s %s HTTP/%s\r\n", method, uri, version);

        printf("Request: %s", request);

        send(server_socket, request, strlen(request), 0);
    }

    close(server_socket);
    exit(0);
}