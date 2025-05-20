//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define BACKLOG 10
#define PORT 8080
#define MAX_REQUEST_SIZE 1024
#define DOCUMENT_ROOT "./www"
#define INDEX_FILE "index.html"

// Function to send a response to the client
void send_response(int client_socket, char* response) {
    send(client_socket, response, strlen(response), 0);
}

// Function to handle a client request
void handle_client(int client_socket) {
    char request[MAX_REQUEST_SIZE];
    char path[MAX_REQUEST_SIZE];
    char *ptr;
    FILE *fp;
    char buffer[MAX_REQUEST_SIZE];
    int bytes_read;

    // Read the client request
    bytes_read = recv(client_socket, request, MAX_REQUEST_SIZE, 0);
    if (bytes_read <= 0) {
        return;
    }
    request[bytes_read] = '\0';

    // Parse the request path
    ptr = strtok(request, " ");
    strcpy(path, ptr);
    strcat(path, "/");

    // Check if the requested file exists
    strcat(path, DOCUMENT_ROOT);
    fp = fopen(path, "r");
    if (fp == NULL) {
        send_response(client_socket, "404 Not Found");
        return;
    }

    // Send the file contents to the client
    while ((bytes_read = fread(buffer, 1, MAX_REQUEST_SIZE, fp)) > 0) {
        send(client_socket, buffer, bytes_read, 0);
    }
    fclose(fp);
}

// Main function
int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int addrlen;
    int opt = 1;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options on the socket
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind the socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (TRUE) {
        // Accept a new connection
        addrlen = sizeof(client_addr);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Handle the client request
        handle_client(client_socket);

        // Close the client socket
        close(client_socket);
    }

    return 0;
}