//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER];
    int portno = 25;
    char *hostname = "smtp.gmail.com";
    char *username = "your_email_here@gmail.com";
    char *password = "your_password_here";
    char *to = "recipient_email_here@gmail.com";
    char *from = "your_email_here@gmail.com";
    char *subject = "Test email from SMTP Client";
    char *message = "Hello, this is a test email from SMTP Client.\n";

    // Resolve hostname
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname.\n");
        exit(EXIT_FAILURE);
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
        handle_error("Error creating socket.");

    // Set server address and port
    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portno);
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    // Connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
        handle_error("Error connecting to server.");

    // Receive server greeting
    memset(buffer, '\0', MAX_BUFFER);
    if (recv(sock, buffer, MAX_BUFFER, 0) < 0)
        handle_error("Error receiving server greeting.");

    printf("Server greeting: %s\n", buffer);

    // Send EHLO command
    memset(buffer, '\0', MAX_BUFFER);
    sprintf(buffer, "EHLO %s\r\n", hostname);
    if (send(sock, buffer, strlen(buffer), 0) < 0)
        handle_error("Error sending EHLO command.");

    // Receive EHLO response
    memset(buffer, '\0', MAX_BUFFER);
    if (recv(sock, buffer, MAX_BUFFER, 0) < 0)
        handle_error("Error receiving EHLO response.");

    printf("EHLO response: %s\n", buffer);

    // Send AUTH LOGIN command
    memset(buffer, '\0', MAX_BUFFER);
    sprintf(buffer, "AUTH LOGIN\r\n");
    if (send(sock, buffer, strlen(buffer), 0) < 0)
        handle_error("Error sending AUTH LOGIN command.");

    // Receive AUTH LOGIN response
    memset(buffer, '\0', MAX_BUFFER);
    if (recv(sock, buffer, MAX_BUFFER, 0) < 0)
        handle_error("Error receiving AUTH LOGIN response.");

    printf("AUTH LOGIN response: %s\n", buffer);

    // Send username
    memset(buffer, '\0', MAX_BUFFER);
    sprintf(buffer, "%s\r\n", username);
    if (send(sock, buffer, strlen(buffer), 0) < 0)
        handle_error("Error sending username.");

    // Receive username response
    memset(buffer, '\0', MAX_BUFFER);
    if (recv(sock, buffer, MAX_BUFFER, 0) < 0)
        handle_error("Error receiving username response.");

    printf("Username response: %s\n", buffer);

    // Send password
    memset(buffer, '\0', MAX_BUFFER);
    sprintf(buffer, "%s\r\n", password);
    if (send(sock, buffer, strlen(buffer), 0) < 0)
        handle_error("Error sending password.");

    // Receive password response
    memset(buffer, '\0', MAX_BUFFER);
    if (recv(sock, buffer, MAX_BUFFER, 0) < 0)
        handle_error("Error receiving password response.");

    printf("Password response: %s\n", buffer);

    // Send MAIL FROM command
    memset(buffer, '\0', MAX_BUFFER);
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    if (send(sock, buffer, strlen(buffer), 0) < 0)
        handle_error("Error sending MAIL FROM command.");

    // Receive MAIL FROM response
    memset(buffer, '\0', MAX_BUFFER);
    if (recv(sock, buffer, MAX_BUFFER, 0) < 0)
        handle_error("Error receiving MAIL FROM response.");

    printf("MAIL FROM response: %s\n", buffer);

    // Send RCPT TO command
    memset(buffer, '\0', MAX_BUFFER);
    sprintf(buffer, "RCPT TO:<%s>\r\n", to);
    if (send(sock, buffer, strlen(buffer), 0) < 0)
        handle_error("Error sending RCPT TO command.");

    // Receive RCPT TO response
    memset(buffer, '\0', MAX_BUFFER);
    if (recv(sock, buffer, MAX_BUFFER, 0) < 0)
        handle_error("Error receiving RCPT TO response.");

    printf("RCPT TO response: %s\n", buffer);

    // Send DATA command
    memset(buffer, '\0', MAX_BUFFER);
    sprintf(buffer, "DATA\r\n");
    if (send(sock, buffer, strlen(buffer), 0) < 0)
        handle_error("Error sending DATA command.");

    // Receive DATA response
    memset(buffer, '\0', MAX_BUFFER);
    if (recv(sock, buffer, MAX_BUFFER, 0) < 0)
        handle_error("Error receiving DATA response.");

    printf("DATA response: %s\n", buffer);

    // Send email headers and message
    memset(buffer, '\0', MAX_BUFFER);
    sprintf(buffer, "From: <%s>\r\n", from);
    if (send(sock, buffer, strlen(buffer), 0) < 0)
        handle_error("Error sending email headers.");

    memset(buffer, '\0', MAX_BUFFER);
    sprintf(buffer, "To: <%s>\r\n", to);
    if (send(sock, buffer, strlen(buffer), 0) < 0)
        handle_error("Error sending email headers.");

    memset(buffer, '\0', MAX_BUFFER);
    sprintf(buffer, "Subject: %s\r\n", subject);
    if (send(sock, buffer, strlen(buffer), 0) < 0)
        handle_error("Error sending email headers.");

    memset(buffer, '\0', MAX_BUFFER);
    sprintf(buffer, "\r\n%s", message);
    if (send(sock, buffer, strlen(buffer), 0) < 0)
        handle_error("Error sending email message.");

    // Send QUIT command
    memset(buffer, '\0', MAX_BUFFER);
    sprintf(buffer, "QUIT\r\n");
    if (send(sock, buffer, strlen(buffer), 0) < 0)
        handle_error("Error sending QUIT command.");

    // Receive QUIT response
    memset(buffer, '\0', MAX_BUFFER);
    if (recv(sock, buffer, MAX_BUFFER, 0) < 0)
        handle_error("Error receiving QUIT response.");

    printf("QUIT response: %s\n", buffer);

    // Close socket
    close(sock);

    return 0;
}