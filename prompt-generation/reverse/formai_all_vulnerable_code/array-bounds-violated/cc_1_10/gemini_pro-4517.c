//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: energetic
#include <stdio.h>  // For standard I/O
#include <stdlib.h> // For exit()
#include <string.h> // For strcpy(), strcmp()
#include <unistd.h> // For read(), write(), close()
#include <sys/socket.h> // For socket(), connect(), sendto(), recvfrom()
#include <sys/types.h> // For socket data types
#include <netinet/in.h> // For sockaddr_in
#include <arpa/inet.h> // For inet_addr()

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

// Define the client function
void client() {
    // 1. Create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // 2. Set up the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 3. Connect to the server
    int connection_status = connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (connection_status == -1) {
        perror("Error connecting to server");
        close(client_socket);
        exit(1);
    }

    // 4. Send a message to the server
    char message[] = "Hello from the client!";
    int sent_bytes = send(client_socket, message, strlen(message), 0);
    if (sent_bytes == -1) {
        perror("Error sending message to server");
        close(client_socket);
        exit(1);
    }

    // 5. Receive a message from the server
    char buffer[MAX_BUFFER_SIZE];
    int received_bytes = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    if (received_bytes == -1) {
        perror("Error receiving message from server");
        close(client_socket);
        exit(1);
    }

    // 6. Print the received message
    buffer[received_bytes] = '\0';
    printf("Message received from server: %s\n", buffer);

    // 7. Close the socket
    close(client_socket);
}

// Define the server function
void server() {
    // 1. Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // 2. Set up the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // 3. Bind the socket to the server address
    int bind_status = bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (bind_status == -1) {
        perror("Error binding socket to address");
        close(server_socket);
        exit(1);
    }

    // 4. Listen for incoming connections
    int listen_status = listen(server_socket, 5);
    if (listen_status == -1) {
        perror("Error listening for incoming connections");
        close(server_socket);
        exit(1);
    }

    // 5. Accept an incoming connection
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
    if (client_socket == -1) {
        perror("Error accepting incoming connection");
        close(server_socket);
        exit(1);
    }

    // 6. Receive a message from the client
    char buffer[MAX_BUFFER_SIZE];
    int received_bytes = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    if (received_bytes == -1) {
        perror("Error receiving message from client");
        close(client_socket);
        close(server_socket);
        exit(1);
    }

    // 7. Print the received message
    buffer[received_bytes] = '\0';
    printf("Message received from client: %s\n", buffer);

    // 8. Send a message back to the client
    char message[] = "Hello from the server!";
    int sent_bytes = send(client_socket, message, strlen(message), 0);
    if (sent_bytes == -1) {
        perror("Error sending message to client");
        close(client_socket);
        close(server_socket);
        exit(1);
    }

    // 9. Close the client socket
    close(client_socket);

    // 10. Close the server socket
    close(server_socket);
}

int main() {
    // Get the user's choice of being a client or a server
    char choice;
    printf("Enter 'c' to be a client or 's' to be a server: ");
    scanf(" %c", &choice);

    // Start the client or server based on the user's choice
    switch (choice) {
        case 'c':
            client();
            break;
        case 's':
            server();
            break;
        default:
            printf("Invalid choice. Please enter either 'c' or 's'.\n");
            break;
    }

    return 0;
}