//GEMINI-pro DATASET v1.0 Category: Networking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// A custom data structure to represent a chat message
typedef struct {
    char username[20];
    char message[100];
} ChatMessage;

// Function to send a chat message to the server
void send_message(int sockfd, ChatMessage *message) {
    // Send the username
    int n = write(sockfd, message->username, sizeof(message->username));
    if (n < 0) {
        perror("Error sending username");
        exit(1);
    }

    // Send the message
    n = write(sockfd, message->message, sizeof(message->message));
    if (n < 0) {
        perror("Error sending message");
        exit(1);
    }
}

// Function to receive a chat message from the server
void receive_message(int sockfd, ChatMessage *message) {
    // Receive the username
    int n = read(sockfd, message->username, sizeof(message->username));
    if (n < 0) {
        perror("Error receiving username");
        exit(1);
    }

    // Receive the message
    n = read(sockfd, message->message, sizeof(message->message));
    if (n < 0) {
        perror("Error receiving message");
        exit(1);
    }
}

// Main function
int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(9000);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Create a chat message
    ChatMessage message;

    // Get the username from the user
    printf("Enter your username: ");
    scanf("%s", message.username);

    // Get the message from the user
    printf("Enter your message: ");
    scanf(" %[^\n]%*c", message.message);

    // Send the message to the server
    send_message(sockfd, &message);

    // Receive the message from the server
    receive_message(sockfd, &message);

    // Print the message to the user
    printf("Message from server: %s\n", message.message);

    // Close the socket
    close(sockfd);

    return 0;
}