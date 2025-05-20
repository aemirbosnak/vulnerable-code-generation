//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define IMAP_PORT 993
#define SERVER "imap.example.com"
#define BUFFER_SIZE 1024

// Function to create a TCP connection to the IMAP server
int create_connection(const char *server, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to IMAP server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send a command to the IMAP server
void send_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%s\r\n", command);
    send(sockfd, buffer, strlen(buffer), 0);
}

// Function to receive a response from the IMAP server
void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        // Simulating breaking the response reception on a complete message
        if (strstr(buffer, "OK") || strstr(buffer, "NO") || strstr(buffer, "BAD")) {
            break;
        }
    }
}

// Function to login to the IMAP server using the given username and password
void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A001 LOGIN %s %s", username, password);
    
    send_command(sockfd, command);
    receive_response(sockfd);
}

// Function to list the mailboxes on the IMAP server
void list_mailboxes(int sockfd) {
    send_command(sockfd, "A002 LIST \"\" \"*\"");
    receive_response(sockfd);
}

// Function to fetch emails from a specific mailbox
void fetch_emails(int sockfd, const char *mailbox) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A003 SELECT \"%s\"", mailbox);
    
    send_command(sockfd, command);
    receive_response(sockfd);

    // Assuming we want to fetch the emails after selecting the mailbox
    send_command(sockfd, "A004 FETCH 1:* (ENVELOPE)");
    receive_response(sockfd);
}

// Main function
int main() {
    int sockfd = create_connection(SERVER, IMAP_PORT);
    
    // User's credentials
    const char *username = "yourusername@example.com"; // Example username
    const char *password = "yourpassword"; // Example password

    // Login to the IMAP server
    login(sockfd, username, password);

    // List mailboxes
    printf("Mailboxes:\n");
    list_mailboxes(sockfd);

    // Fetch emails from inbox
    printf("\nFetching emails from the inbox:\n");
    fetch_emails(sockfd, "INBOX");

    // Close the socket
    close(sockfd);
    return 0;
}