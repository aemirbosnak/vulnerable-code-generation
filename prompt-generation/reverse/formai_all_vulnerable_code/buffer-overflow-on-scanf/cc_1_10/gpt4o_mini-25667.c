//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function declarations
void start_server();
void start_client();

int main() {
    int choice;

    printf("Choose an option:\n");
    printf("1. Start Server\n");
    printf("2. Start Client\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // consume newline

    if (choice == 1) {
        start_server();
    } else if (choice == 2) {
        start_client();
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d\n", PORT);

    // Accept an incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Read and echo back messages
    while (1) {
        int bytes_read = read(new_socket, buffer, BUFFER_SIZE);
        if(bytes_read <= 0) {
            printf("Client disconnected or error in reading.\n");
            break;
        }

        printf("Message from client: %s\n", buffer);
        send(new_socket, buffer, bytes_read, 0);
        printf("Echoed message sent back to client.\n");
        memset(buffer, 0, BUFFER_SIZE); // Clear the buffer
    }

    close(new_socket);
    close(server_fd);
}

void start_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from Client!";
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
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

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    // Send messages to the server
    while (1) {
        printf("Send a message to server: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(sock, buffer, strlen(buffer), 0);
        printf("Message sent\n");

        // Receive echoed message from server
        int bytes_read = read(sock, buffer, BUFFER_SIZE);
        if(bytes_read > 0) {
            printf("Message from server: %s\n", buffer);
        }
        
        if (strncmp(buffer, "exit", 4) == 0) {
            printf("Exiting client...\n");
            break;
        }
        memset(buffer, 0, BUFFER_SIZE);
    }

    close(sock);
}