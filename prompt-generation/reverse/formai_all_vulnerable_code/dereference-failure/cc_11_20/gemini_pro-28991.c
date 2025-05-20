//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {

    // Create a socket.
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set up the server address.
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the server address.
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections.
    if (listen(server_socket, 5) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept incoming connections.
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Handle the client request.
        char request[1024];
        memset(request, 0, sizeof(request));
        if (recv(client_socket, request, sizeof(request), 0) == -1) {
            perror("recv");
            close(client_socket);
            continue;
        }

        // Parse the request.
        char *method = strtok(request, " ");
        char *path = strtok(NULL, " ");
        char *version = strtok(NULL, "\r\n");

        // Check if the request is valid.
        if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
            char *response = "HTTP/1.1 400 Bad Request\r\n\r\n";
            if (send(client_socket, response, strlen(response), 0) == -1) {
                perror("send");
            }
            close(client_socket);
            continue;
        }

        // Send the response.
        char *body = "<html><body><h1>Hello, world!</h1></body></html>";
        char *response = "HTTP/1.1 200 OK\r\nContent-Length: ";
        char *content_length = malloc(strlen(body) + 20);
        sprintf(content_length, "%lu", strlen(body));
        strcat(response, content_length);
        strcat(response, "\r\nContent-Type: text/html\r\n\r\n");
        strcat(response, body);
        free(content_length);
        if (send(client_socket, response, strlen(response), 0) == -1) {
            perror("send");
        }

        // Close the client socket.
        close(client_socket);
    }

    // Close the server socket.
    close(server_socket);

    return EXIT_SUCCESS;
}