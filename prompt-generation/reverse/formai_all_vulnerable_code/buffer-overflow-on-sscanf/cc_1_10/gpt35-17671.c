//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void proxy(int client_socket) {
    char buffer[BUFFER_SIZE], request[BUFFER_SIZE], response[BUFFER_SIZE];
    int server_socket, read_size, total_size;
    bool end_of_header = false;

    memset(&buffer, '\0', sizeof(buffer));
    read_size = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (read_size == -1) {
        perror("recv failed");
        return;
    }

    sscanf(buffer, "%s", request); // get the request method
    if (strcasecmp(request, "GET")) { // only proxy GET request for now
        perror("Unsupported request method");
        return;
    }

    printf("\n\nProxying request:\n\n%s\n\n", buffer);
    
    // Open connection to server
    struct sockaddr_in server_addr;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create server socket");
        close(client_socket);
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) != 0) {
        perror("Failed to connect to server");
        close(client_socket);
        return;
    }
    
    printf("Connected to server\n\n");

    // Send request to server
    if (send(server_socket, buffer, strlen(buffer), 0) == -1) {
        perror("Failed to send request to server");
        close(client_socket);
        return;
    }
    
    // Read response from server and send it to client
    total_size = 0;
    memset(&buffer, '\0', sizeof(buffer));
    while ((read_size = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        if (!end_of_header) {
            char *end_of_header_position = strstr(buffer, "\r\n\r\n");
            if (end_of_header_position != NULL) {
                end_of_header = true;
                int header_size = end_of_header_position - buffer;
                memcpy(response, buffer, header_size);
                total_size = header_size;
                printf("Received response header:\n\n%s\n\n", response);
            }
        }

        total_size += read_size;
        if (send(client_socket, buffer, read_size, 0) == -1) {
            perror("Failed to send response to client");
            close(client_socket);
            return;
        }

        memset(&buffer, '\0', sizeof(buffer));
    }

    printf("Received %d bytes of response\n\n", total_size);

    close(client_socket);
    close(server_socket);
}

int main() {
    int server_socket, client_socket, status;
    struct sockaddr_in server_addr, client_addr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create server socket");
        return EXIT_FAILURE;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    status = bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (status == -1) {
        perror("Failed to bind server socket");
        return EXIT_FAILURE;
    }

    status = listen(server_socket, 10);
    if (status == -1) {
        perror("Failed to listen to server socket");
        return EXIT_FAILURE;
    }

    while (true) {
        socklen_t client_addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);

        if (client_socket == -1) {
            perror("Failed to accept client connection");
            continue;
        }

        printf("Accepted new client connection\n");

        pid_t pid = fork();

        if (pid == -1) {
            perror("Failed to fork");
            return EXIT_FAILURE;
        }
        else if (pid == 0) {
            close(server_socket);
            proxy(client_socket);
            return EXIT_SUCCESS;
        }
        else {
            close(client_socket);
        }
    }

    return EXIT_SUCCESS;
}