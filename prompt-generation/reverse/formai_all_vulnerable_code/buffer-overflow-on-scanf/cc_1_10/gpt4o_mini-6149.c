//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// Size definitions
#define PORT 993
#define BUFFER_SIZE 2048
#define MAX_EMAILS 100

// Email structure
typedef struct {
    int id;
    char subject[256];
    char sender[256];
    char date[128];
} Email;

// Function to connect to an email server
int connect_to_email_server(const char *hostname) {
    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the email server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send and receive data from the server
void communicate_with_server(int sockfd, const char *message) {
    char buffer[BUFFER_SIZE];
    send(sockfd, message, strlen(message), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);
}

// Function to fetch emails
void fetch_emails(int sockfd) {
    Email emails[MAX_EMAILS];
    char command[BUFFER_SIZE];

    strcpy(command, "001 SELECT INBOX\r\n");
    communicate_with_server(sockfd, command);

    for (int i = 1; i <= MAX_EMAILS; i++) {
        sprintf(command, "002 FETCH %d BODY[HEADER]\r\n", i);
        communicate_with_server(sockfd, command);
        // Add logic to fill the emails array from server responses
        // This is simplified; proper parsing of the email headers is needed
        Email email = { .id = i, .subject = "Sample Subject", .sender = "user@example.com", .date = "Date: Today" };
        emails[i-1] = email;
        // Print to show emails fetched
        printf("Email #%d: %s\n", email.id, email.subject);
    }
}

// Main function
int main() {
    const char *hostname = "127.0.0.1"; // Change this to your mail server
    printf("🚀 Welcome to the Exciting Email Client! 🚀\n");

    int sockfd = connect_to_email_server(hostname);

    char username[128], password[128];
    printf("💌 Enter your email username: ");
    scanf("%s", username);
    printf("🔑 Enter your password: ");
    scanf("%s", password); // In a real app, prefer secure input methods

    char login_command[BUFFER_SIZE];
    sprintf(login_command, "001 LOGIN %s %s\r\n", username, password);
    communicate_with_server(sockfd, login_command);

    printf("📥 Fetching your emails...\n");
    fetch_emails(sockfd);
    
    // Add functionality here to read more details
    // Note: Remember to implement error checks as needed

    // Closing the socket connection
    close(sockfd);
    printf("🙌 Thank you for using the Email Client! Goodbye! 👋\n");
    return 0;
}