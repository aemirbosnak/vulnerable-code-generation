//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function prototypes
void start_server();
void start_client();

int main() {
    int choice;

    printf("Welcome to the TCP Communication Program!\n");
    printf("1. Start Server\n");
    printf("2. Start Client\n");
    printf("Please select an option (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        start_server();
    } else if (choice == 2) {
        start_client();
    } else {
        printf("Invalid choice. Please restart the program.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int address_len = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to the specified PORT
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&address_len)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Communication with client
    while (1) {
        ssize_t valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread <= 0) {
            printf("Connection closed by client.\n");
            break;
        }
        
        printf("Received: %s\n", buffer);
        char *response = "Message received!";
        send(new_socket, response, strlen(response), 0);
        memset(buffer, 0, BUFFER_SIZE);  // Clear buffer for the next message
    }

    close(new_socket);
    close(server_fd);
}

void start_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char message[BUFFER_SIZE];

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported\n");
        return;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        return;
    }

    printf("Connected to the server! Type your message (type 'exit' to quit):\n");
    
    while (1) {
        printf("> ");
        fgets(message, BUFFER_SIZE, stdin);
        message[strcspn(message, "\n")] = 0;  // Remove newline character

        if (strcmp(message, "exit") == 0) {
            break;
        }

        send(sock, message, strlen(message), 0);
        ssize_t valread = read(sock, buffer, BUFFER_SIZE);
        if (valread > 0) {
            printf("Server: %s\n", buffer);
        }
        memset(buffer, 0, BUFFER_SIZE);  // Clear buffer for the next response
    }

    close(sock);
    printf("Connection closed. Goodbye!\n");
}