//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_MESSAGE_SIZE 1024
#define PORT 8080

// Structure to hold user information
typedef struct {
    char *username;
    char *message;
} user_info_t;

// Function to create a socket
int create_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to connect to a server
int connect_to_server(int sock) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to send a message
int send_message(int sock, char *message) {
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("message sending failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to receive a message
int receive_message(int sock) {
    char buffer[1024];
    int len = recv(sock, buffer, 1024, 0);
    if (len < 0) {
        perror("message receiving failed");
        exit(EXIT_FAILURE);
    }
    return buffer;
}

// Function to handle user input
void handle_input(int sock) {
    char *username, *message;
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your message: ");
    gets(message);
    user_info_t user_info = {username, message};
    send_message(sock, user_info.message);
}

// Function to handle server communication
void handle_server(int sock) {
    char buffer[1024];
    int len = recv(sock, buffer, 1024, 0);
    if (len < 0) {
        perror("server communication failed");
        exit(EXIT_FAILURE);
    }
    printf("Received message from client: %s\n", buffer);
    // Handle the received message here
}

int main() {
    int sock1, sock2;
    sock1 = create_socket();
    sock2 = create_socket();

    // Connect to the server
    if (connect_to_server(sock1) < 0) {
        exit(EXIT_FAILURE);
    }

    // Handle client communication
    handle_input(sock1);

    // Connect to the second client
    sock2 = create_socket();
    if (connect_to_server(sock2) < 0) {
        exit(EXIT_FAILURE);
    }

    // Handle server communication
    handle_server(sock2);

    // Close the sockets
    close(sock1);
    close(sock2);
    return 0;
}