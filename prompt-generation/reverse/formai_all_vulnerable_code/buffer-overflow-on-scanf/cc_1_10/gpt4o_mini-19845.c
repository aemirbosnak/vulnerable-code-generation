//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void start_server();
void start_client();

int main() {
    int choice;
    
    printf("Welcome to the Energetic TCP/IP Program!\n");
    printf("Choose your adventure:\n");
    printf("1. Start Server\n");
    printf("2. Start Client\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        start_server();
    } else if (choice == 2) {
        start_client();
    } else {
        printf("Invalid choice! Please run the program again and choose 1 or 2.\n");
    }

    return 0;
}

void start_server() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Initialize server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Binding
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for clients
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is up! Waiting for clients to connect...\n");

    // Accepting a client connection
    if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Communicating with the client
    read(client_fd, buffer, BUFFER_SIZE);
    printf("Client says: %s\n", buffer);

    // Closing the connection
    close(client_fd);
    close(server_fd);
    printf("Server shutting down. Goodbye!\n");
}

void start_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from the Client! 🎉";
    
    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }

    // Connecting to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    // Sending a message to the server
    send(sock, hello, strlen(hello), 0);
    printf("Message sent to the server!\n");

    // Closing the socket
    close(sock);
    printf("Client connection closed. Happy to have chatted! 😄\n");
}