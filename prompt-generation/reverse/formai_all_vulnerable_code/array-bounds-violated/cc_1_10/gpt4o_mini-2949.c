//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <limits.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to create and bind the server socket
int create_server_socket() {
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    return server_fd;
}

// Function to handle client communication
void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Loop to receive messages from the client
    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the received data
        printf("Client: %s\n", buffer);

        // Echo the message back to the client
        if (send(client_socket, buffer, bytes_read, 0) == -1) {
            perror("send failed");
            break;
        }
    }

    if (bytes_read == 0) {
        printf("Client disconnected\n");
    } else if (bytes_read < 0) {
        perror("recv failed");
    }

    close(client_socket);
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = create_server_socket();

    printf("Server listening on port %d\n", PORT);

    // Accept incoming connections
    while (1) {
        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            continue; // Skip to the next iteration on accept failure
        }
        printf("New connection accepted\n");

        // Handle the client in a separate method (here we do not fork for simplicity)
        handle_client(client_socket);
    }

    close(server_fd);
    return 0;
}

// Simple TCP client
void TCPClient(const char* ip) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    // Client loop for sending messages
    while (1) {
        printf("Enter message: ");
        fgets(buffer, sizeof(buffer), stdin);
        if (send(sock, buffer, strlen(buffer), 0) == -1) {
            perror("send failed");
            break;
        }

        // Receiving echo from the server
        int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) {
            perror("recv failed or server disconnected");
            break;
        }
        buffer[bytes_received] = '\0';
        printf("Server: %s\n", buffer);
    }

    close(sock);
}