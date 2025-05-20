//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

// IMAP commands to be used
#define IMAP_LOGIN "a001 LOGIN "
#define IMAP_SELECT "a002 SELECT "
#define IMAP_FETCH "a003 FETCH "
#define IMAP_LOGOUT "a004 LOGOUT "

// Function prototypes
void imap_send(int sockfd, const char *command);
void imap_receive(int sockfd);

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char *host = "imap.example.com"; // Your IMAP server here
    int port = 993;                   // IMAPs port
    char username[100], password[100];
    char command[BUFFER_SIZE];

    // Prompt for user credentials
    printf("Enter your IMAP username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline

    printf("Enter your IMAP password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline

    // Create socket for connection
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr); // Convert address

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive server greeting
    imap_receive(sockfd);

    // Send login command
    snprintf(command, sizeof(command), "%s \"%s\" \"%s\"\r\n", IMAP_LOGIN, username, password);
    imap_send(sockfd, command);
    imap_receive(sockfd);

    // Select the inbox
    imap_send(sockfd, IMAP_SELECT "INBOX\r\n");
    imap_receive(sockfd);

    // Fetch email list
    imap_send(sockfd, IMAP_FETCH "1:* (UID SUBJECT)\r\n");
    imap_receive(sockfd);

    // Send logout command
    imap_send(sockfd, IMAP_LOGOUT);
    imap_receive(sockfd);

    // Close the socket
    close(sockfd);
    return EXIT_SUCCESS;
}

// Function to send IMAP command
void imap_send(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    printf("Sent: %s", command);
}

// Function to receive IMAP response
void imap_receive(int sockfd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("Error receiving data");
        return;
    }

    buffer[bytes_received] = '\0'; // Null-terminate the string
    printf("Received: %s\n", buffer);
}