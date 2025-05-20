//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void handle_request(int client_fd) {
    struct sockaddr_in web_addr;
    int web_fd, num_bytes;
    char buffer[BUFFER_SIZE], *p, request[BUFFER_SIZE], response[BUFFER_SIZE];
    
    // Read client request
    if ((num_bytes = recv(client_fd, buffer, BUFFER_SIZE, 0)) == -1) {
        perror("Error reading client request");
        exit(EXIT_FAILURE);
    }

    buffer[num_bytes] = '\0';
    printf("Request received from client: %s\n", buffer);

    // Parse client request
    sscanf(buffer, "GET %s HTTP/1.0", request);

    // Open socket to web server
    if ((web_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket to web server");
        exit(EXIT_FAILURE);
    }

    web_addr.sin_family = AF_INET;
    web_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    web_addr.sin_port = htons(80);

    if ((connect(web_fd, (struct sockaddr*)&web_addr, sizeof(web_addr))) == -1) {
        perror("Error connecting to web server");
        exit(EXIT_FAILURE);
    }

    // Send request to web server
    send(web_fd, buffer, strlen(buffer), 0);

    // Receive response from web server
    if ((num_bytes = recv(web_fd, response, BUFFER_SIZE, 0)) == -1) {
        perror("Error receiving response from web server");
        exit(EXIT_FAILURE);
    }

    response[num_bytes] = '\0';
    printf("Response received from server: %s\n", response);

    // Strip HTTP headers
    p = strstr(response, "\r\n\r\n");
    if (p != NULL) {
        p += 4;
        num_bytes = strlen(p);
    }

    // Send response to client
    send(client_fd, p, num_bytes, 0);

    // Close web socket
    close(web_fd);
}

int main(int argc, char* argv[]) {
    int server_fd, client_fd, sin_size, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    
    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind server socket to port
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding server socket to port");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) == -1) {
        perror("Error listening for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server is listening on port 8080...\n");

    while (1) {
        sin_size = sizeof(struct sockaddr_in);

        // Accept incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &sin_size)) == -1) {
            perror("Error accepting incoming connection");
            continue;
        }

        printf("Received incoming connection from client %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Fork process to handle request
        if (fork() == 0) {
            close(server_fd);
            handle_request(client_fd);
            printf("Closing connection from client %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            close(client_fd);
            exit(EXIT_SUCCESS);
        }

        close(client_fd);
    }

    return 0;
}