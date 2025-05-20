//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define LISTEN_PORT 8080
#define DOCUMENT_ROOT "./"

char *response_headers = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n";
char *not_found_response = "<html><head><title>404 Not Found</title></head><body><h1>404 Not Found</h1></body></html>";

void send_response(int client_socket) {
    char *response = response_headers;
    send(client_socket, response, strlen(response), 0);
}

void send_file_response(int client_socket, char *filename) {
    char *response = response_headers;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        response = not_found_response;
    } else {
        char buffer[BUFFER_SIZE];
        while (fgets(buffer, BUFFER_SIZE, file)!= NULL) {
            send(client_socket, buffer, strlen(buffer), 0);
        }
        fclose(file);
    }
    send(client_socket, response, strlen(response), 0);
}

void handle_request(int client_socket) {
    char request_buffer[BUFFER_SIZE];
    recv(client_socket, request_buffer, BUFFER_SIZE, 0);

    char *request_line = strtok(request_buffer, "\r\n");
    char *method = strtok(request_line, " ");
    char *path = strtok(NULL, " ");

    if (strcmp(method, "GET")!= 0) {
        send_response(client_socket);
        return;
    }

    char *filename = (char *) malloc(strlen(DOCUMENT_ROOT) + strlen(path) + 2);
    strcpy(filename, DOCUMENT_ROOT);
    strcat(filename, path);
    send_file_response(client_socket, filename);

    free(filename);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(LISTEN_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started on port %d\n", LISTEN_PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket!= -1) {
            printf("Client connected\n");
            handle_request(client_socket);
            close(client_socket);
        }
    }

    return 0;
}