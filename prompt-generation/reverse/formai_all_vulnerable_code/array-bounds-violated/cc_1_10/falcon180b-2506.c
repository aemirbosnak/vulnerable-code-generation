//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

// Function to send an HTTP response to the client
void send_response(int client_socket) {
    char response_header[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n";
    char response_body[] = "<html><body><h1>Welcome to the Simple Web Server!</h1></body></html>";

    send(client_socket, response_header, strlen(response_header), 0);
    send(client_socket, response_body, strlen(response_body), 0);
}

// Function to handle a client request
void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    int bytes_received = 0;
    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received request: %s\n", buffer);

        // Check if the request is for the root page
        if (strcasecmp(buffer, "GET / HTTP/1.1") == 0) {
            send_response(client_socket);
        }
    }

    close(client_socket);
}

// Main function to start the server
int main(int argc, char *argv[]) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        close(server_socket);
        return 1;
    }

    if (listen(server_socket, 10) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        close(server_socket);
        return 1;
    }

    printf("Server started on port 8080\n");

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
        } else {
            printf("New client connected\n");
            handle_client(client_socket);
        }
    }

    close(server_socket);
    return 0;
}