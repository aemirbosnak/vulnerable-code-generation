//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// Constants for SMTP protocol
#define SMTP_SERVER "smtp.example.com"
#define SMTP_PORT 587

// Function to handle errors
void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

// Function to send data to the server
void send_data(int sockfd, const char *data) {
    if (send(sockfd, data, strlen(data), 0) < 0) {
        handle_error("Failed to send data");
    }
}

// Function to receive data from the server
void receive_data(int sockfd) {
    char buffer[1024];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        handle_error("Failed to receive data");
    }
    buffer[bytes_received] = '\0'; // Null terminate the received data
    printf("%s", buffer);
}

// Function to create a TCP socket
int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Cannot create socket");
    }
    return sockfd;
}

// Function to setup server address structure
struct sockaddr_in setup_server_address() {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to your server's IP address
    return server_addr;
}

// Function to send an email
void send_email(const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = create_socket();
    server_addr = setup_server_address();

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection failed");
    }

    receive_data(sockfd); // Welcome message from the SMTP server

    // EHLO command
    send_data(sockfd, "EHLO localhost\r\n");
    receive_data(sockfd);

    // AUTH LOGIN (You may need to implement base64 encoding for credentials)
    send_data(sockfd, "AUTH LOGIN\r\n");
    receive_data(sockfd);
    
    // Send username and password (base64 encoded)
    send_data(sockfd, "dXNlcm5hbWU=\r\n"); // Base64 for 'username'
    receive_data(sockfd);
    send_data(sockfd, "cGFzc3dvcmQ=\r\n"); // Base64 for 'password'
    receive_data(sockfd);

    // MAIL FROM
    char command[256];
    snprintf(command, sizeof(command), "MAIL FROM: <%s>\r\n", from);
    send_data(sockfd, command);
    receive_data(sockfd);

    // RCPT TO
    snprintf(command, sizeof(command), "RCPT TO: <%s>\r\n", to);
    send_data(sockfd, command);
    receive_data(sockfd);

    // DATA
    send_data(sockfd, "DATA\r\n");
    receive_data(sockfd);
    
    // Email headers and body
    snprintf(command, sizeof(command), "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", from, to, subject, body);
    send_data(sockfd, command);
    receive_data(sockfd);
    
    // QUIT
    send_data(sockfd, "QUIT\r\n");
    receive_data(sockfd);

    close(sockfd); // Close the socket
}

// Main function
int main() {
    const char *from = "your_email@example.com";
    const char *to = "recipient@example.com";
    const char *subject = "Test Email";
    const char *body = "This is a test email sent from a C program!";

    send_email(from, to, subject, body);
    printf("Email sent successfully!\n");
    return 0;
}