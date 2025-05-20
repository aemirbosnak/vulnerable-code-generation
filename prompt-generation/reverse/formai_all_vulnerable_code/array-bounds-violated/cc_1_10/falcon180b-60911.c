//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to send a command to the SMTP server and receive a response
int send_command(int sock, char *command) {
    char response[BUFFER_SIZE];
    int bytes_sent = send(sock, command, strlen(command), 0);
    if (bytes_sent <= 0) {
        printf("Error sending command\n");
        return -1;
    }

    int bytes_received = recv(sock, response, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving response\n");
        return -1;
    }

    response[bytes_received] = '\0';
    printf("Response: %s\n", response);

    return 0;
}

// Function to send an email using the SMTP protocol
int send_email(int sock, char *from, char *to, char *subject, char *body) {
    char command[BUFFER_SIZE];

    sprintf(command, "MAIL FROM:<%s>\r\n", from);
    send_command(sock, command);

    sprintf(command, "RCPT TO:<%s>\r\n", to);
    send_command(sock, command);

    sprintf(command, "DATA\r\n");
    send_command(sock, command);

    sprintf(command, "Subject: %s\r\n", subject);
    send_command(sock, command);

    sprintf(command, "\r\n%s\r\n.\r\n", body);
    send_command(sock, command);

    return 0;
}

// Main function
int main() {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    inet_pton(AF_INET, "smtp.example.com", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return -1;
    }

    char *from = "sender@example.com";
    char *to = "recipient@example.com";
    char *subject = "Test Email";
    char *body = "This is a test email sent using the SMTP protocol in C.";

    send_email(sock, from, to, subject, body);

    close(sock);

    return 0;
}