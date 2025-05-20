//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

// Function to handle response from the server
void handle_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';  // Null-terminate the received data
    printf("%s", buffer);
}

// Function to send the SMTP command and handle response
void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    handle_response(sockfd);
}

// Function to create and connect the socket
int create_socket(const char *server) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Main function for sending email
int main() {
    char server[100], sender[100], recipient[100], subject[100], body[500];
    int sockfd;

    // Input details
    printf("Enter SMTP Server Address (e.g. smtp.example.com): ");
    scanf("%s", server);
    printf("Enter Sender Email Address: ");
    scanf("%s", sender);
    printf("Enter Recipient Email Address: ");
    scanf("%s", recipient);
    printf("Enter Subject: ");
    scanf(" %[^\n]s", subject);  // Read string with spaces
    printf("Enter Body (end with a single '.' on a new line):\n");
    
    char line[BUFFER_SIZE];
    strcpy(body, "");  // Initialize body as empty
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strcmp(line, ".\n") == 0) {
            break;  // End of body input
        }
        strcat(body, line);  // Append line to body
    }
    
    // Create connection to SMTP server
    sockfd = create_socket(server);
    
    // Prepare to communicate with the SMTP server
    handle_response(sockfd);  // Get server response

    // EHLO command
    char ehlo_command[BUFFER_SIZE];
    sprintf(ehlo_command, "EHLO %s\r\n", sender);
    send_command(sockfd, ehlo_command);

    // MAIL FROM command
    char mail_from_command[BUFFER_SIZE];
    sprintf(mail_from_command, "MAIL FROM:<%s>\r\n", sender);
    send_command(sockfd, mail_from_command);

    // RCPT TO command
    char rcpt_to_command[BUFFER_SIZE];
    sprintf(rcpt_to_command, "RCPT TO:<%s>\r\n", recipient);
    send_command(sockfd, rcpt_to_command);

    // DATA command
    send_command(sockfd, "DATA\r\n");

    // Compose the email
    char email[BUFFER_SIZE * 2];  // Prepare to hold email
    sprintf(email, "Subject: %s\r\nFrom: %s\r\nTo: %s\r\n\r\n%s\r\n.\r\n", subject, sender, recipient, body);
    
    // Send the email data
    send(sockfd, email, strlen(email), 0);
    handle_response(sockfd);  // Get final response

    // QUIT command
    send_command(sockfd, "QUIT\r\n");

    // Close the socket
    close(sockfd);
    
    printf("Email sent successfully!\n");
    return 0;
}