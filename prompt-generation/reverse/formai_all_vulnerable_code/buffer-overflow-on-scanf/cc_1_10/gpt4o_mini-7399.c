//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8888
#define MAX_BUFFER 1024

void start_server();
void start_client();

int main() {
    int choice;

    printf("🎉 Welcome to the Cheerful Chat Program! 🎉\n");
    printf("1. Start Server\n");
    printf("2. Start Client\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            start_server();
            break;
        case 2:
            start_client();
            break;
        default:
            printf("😄 Please choose a valid option! 😄\n");
            break;
    }
    return 0;
}

void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("🤖 Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("🤖 Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Setting up the address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("🤖 Binding failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("🤖 Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("😊 Server is listening on port %d ...\n", PORT);

    // Accept a new connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("🤖 Accept failed");
        exit(EXIT_FAILURE);
    }

    // Communicate with the client
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        read(new_socket, buffer, MAX_BUFFER);
        printf("📩 Client: %s", buffer);

        // Echo the message back
        send(new_socket, buffer, strlen(buffer), 0);
        printf("📪 Echoed back: %s", buffer);
        if (strncmp(buffer, "exit", 4) == 0) {
            printf("🛑 Server is shutting down...\n");
            break;
        }
    }

    // Clean up and close the socket
    close(new_socket);
    close(server_fd);
}

void start_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER] = {0};
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("🤖 Socket creation error\n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("🤖 Invalid address or Address not supported\n");
        return;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("🤖 Connection failed\n");
        return;
    }

    printf("😊 You are now connected to the server! Type your messages below. Type 'exit' to leave.\n");

    // Communicate with the server
    while (1) {
        printf("✍️ You: ");
        fgets(buffer, sizeof(buffer), stdin);
        send(sock, buffer, strlen(buffer), 0);
        
        if (strncmp(buffer, "exit", 4) == 0) {
            printf("👋 Goodbye!\n");
            break;
        }

        memset(buffer, 0, sizeof(buffer));
        read(sock, buffer, MAX_BUFFER);
        printf("📬 Server: %s", buffer);
    }

    // Clean up and close the socket
    close(sock);
}