//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Server code
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    const char *welcome_message = "Welcome to the TCP Server!\n";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Configure address struct
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the specified address and port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    printf("Server is listening on port %d...\n", PORT);

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Send a welcome message to the client
    send(new_socket, welcome_message, strlen(welcome_message), 0);
    printf("Welcome message sent\n");

    // Communicate with client
    while (1) {
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread <= 0) {
            perror("Read failed");
            break;
        }
        printf("Client: %s\n", buffer);
        send(new_socket, buffer, valread, 0);
    }

    // Cleanup
    close(new_socket);
    close(server_fd);
}

// Client code
void start_client() {
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char *message = "Hello, Server!";

    // Create socket
    int sock = 0;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return;
    }

    // Configure the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return;
    }

    // Read welcome message from server
    read(sock, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // Send message and echo back response
    send(sock, message, strlen(message), 0);
    printf("Message sent to server: %s\n", message);

    // Wait for a response
    int valread = read(sock, buffer, BUFFER_SIZE);
    if (valread > 0) {
        buffer[valread] = '\0';  // Null terminate the received message
        printf("Echo from server: %s\n", buffer);
    }

    // Cleanup
    close(sock);
}

int main() {
    int choice;
    printf("Select mode:\n1. Server\n2. Client\n");
    scanf("%d", &choice);
    
    if (choice == 1) {
        start_server();
    } else if (choice == 2) {
        start_client();
    } else {
        printf("Invalid choice. Please select 1 or 2.\n");
    }
    
    return 0;
}