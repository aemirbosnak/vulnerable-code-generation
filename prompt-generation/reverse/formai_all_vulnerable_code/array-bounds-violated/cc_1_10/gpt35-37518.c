//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Function to print error message and exit
void die(char *error_message) {
    perror(error_message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in smtp_server;
    char buffer[BUFFER_SIZE];
    size_t read_len;
    char *mail_body = "From: <sender@example.com>\r\nTo: <recipient@example.com>\r\nSubject: Test email\r\n\r\nHello,\r\nThis is a test email.\r\n";

    // Check for command line argument
    if(argc != 3) {
        printf("Usage: %s <smtp_server> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket == -1) {
        die("Failed to create socket");
    }

    // Set up address for SMTP server
    smtp_server.sin_family = AF_INET;
    smtp_server.sin_addr.s_addr = inet_addr(argv[1]);
    smtp_server.sin_port = htons(atoi(argv[2]));

    // Connect to SMTP server
    if(connect(client_socket, (struct sockaddr *)&smtp_server, sizeof(smtp_server)) == -1) {
        die("Failed to connect to server");
    }

    // Read response from SMTP server
    read_len = recv(client_socket, buffer, BUFFER_SIZE, 0);
    buffer[read_len] = '\0'; // Terminate buffer with null character
    printf("%s", buffer);

    // Send HELO message
    if(send(client_socket, "HELO example.com\r\n", strlen("HELO example.com\r\n"), 0) == -1) {
        die("Failed to send HELO message");
    }

    // Read response from SMTP server
    read_len = recv(client_socket, buffer, BUFFER_SIZE, 0);
    buffer[read_len] = '\0'; // Terminate buffer with null character
    printf("%s", buffer);

    // Send MAIL FROM message
    if(send(client_socket, "MAIL FROM:<sender@example.com>\r\n", strlen("MAIL FROM:<sender@example.com>\r\n"), 0) == -1) {
        die("Failed to send MAIL FROM message");
    }

    // Read response from SMTP server
    read_len = recv(client_socket, buffer, BUFFER_SIZE, 0);
    buffer[read_len] = '\0'; // Terminate buffer with null character
    printf("%s", buffer);

    // Send RCPT TO message
    if(send(client_socket, "RCPT TO:<recipient@example.com>\r\n", strlen("RCPT TO:<recipient@example.com>\r\n"), 0) == -1) {
        die("Failed to send RCPT TO message");
    }

    // Read response from SMTP server
    read_len = recv(client_socket, buffer, BUFFER_SIZE, 0);
    buffer[read_len] = '\0'; // Terminate buffer with null character
    printf("%s", buffer);

    // Send DATA message
    if(send(client_socket, "DATA\r\n", strlen("DATA\r\n"), 0) == -1) {
        die("Failed to send DATA message");
    }

    // Read response from SMTP server
    read_len = recv(client_socket, buffer, BUFFER_SIZE, 0);
    buffer[read_len] = '\0'; // Terminate buffer with null character
    printf("%s", buffer);

    // Send mail body
    if(send(client_socket, mail_body, strlen(mail_body), 0) == -1) {
        die("Failed to send mail body");
    }

    // Send "." to end DATA
    if(send(client_socket, ".\r\n", strlen(".\r\n"), 0) == -1) {
        die("Failed to send end of DATA message");
    }

    // Read response from SMTP server
    read_len = recv(client_socket, buffer, BUFFER_SIZE, 0);
    buffer[read_len] = '\0'; // Terminate buffer with null character
    printf("%s", buffer);

    // Send QUIT message
    if(send(client_socket, "QUIT\r\n", strlen("QUIT\r\n"), 0) == -1) {
        die("Failed to send QUIT message");
    }

    // Read response from SMTP server
    read_len = recv(client_socket, buffer, BUFFER_SIZE, 0);
    buffer[read_len] = '\0'; // Terminate buffer with null character
    printf("%s", buffer);

    // Close client socket
    close(client_socket);

    return 0;
}