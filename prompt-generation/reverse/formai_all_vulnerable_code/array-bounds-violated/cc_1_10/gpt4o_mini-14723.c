//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER "smtp.example.com" // Change this to your SMTP server
#define PORT 25
#define BUFFER_SIZE 1024

// Function prototypes
int create_socket();
void smtp_send_command(int socket, const char *command);
void smtp_send_email(int socket, const char *from, const char *to, const char *subject, const char *body);
void handle_response(int socket);
void close_connection(int socket);

int main() {
    int smtp_socket = create_socket();
    if (smtp_socket < 0) {
        printf("Error creating socket.\n");
        return EXIT_FAILURE;
    }

    handle_response(smtp_socket); // Handle server's initial response

    char *from = "sender@example.com"; // Change this to the sender's email
    char *to = "recipient@example.com"; // Change this to the recipient's email
    char *subject = "Hello from SMTP Client";
    char *body = "This is a test email sent from a C SMTP client.";

    smtp_send_email(smtp_socket, from, to, subject, body);
    close_connection(smtp_socket);

    return EXIT_SUCCESS;
}

// Create a socket for connecting to the SMTP server
int create_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with your SMTP server IP address

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        return -1;
    }
    
    return sock;
}

// Send a command to the SMTP server and print its response
void smtp_send_command(int socket, const char *command) {
    char buffer[BUFFER_SIZE];
    send(socket, command, strlen(command), 0);
    handle_response(socket);
}

// Handle the server's response
void handle_response(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(socket, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0'; // Null-terminate the buffer
    printf("Server response: %s", buffer);
}

// Send the complete email
void smtp_send_email(int socket, const char *from, const char *to, const char *subject, const char *body) {
    smtp_send_command(socket, "HELO localhost\r\n");
    
    char command[BUFFER_SIZE];
    sprintf(command, "MAIL FROM:<%s>\r\n", from);
    smtp_send_command(socket, command);

    sprintf(command, "RCPT TO:<%s>\r\n", to);
    smtp_send_command(socket, command);

    smtp_send_command(socket, "DATA\r\n");
    sprintf(command, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    smtp_send_command(socket, command);
}

// Close the socket connection
void close_connection(int socket) {
    smtp_send_command(socket, "QUIT\r\n");
    close(socket);
    printf("Disconnected from the SMTP server.\n");
}