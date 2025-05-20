//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main() {
    // Get the hostname of the SMTP server
    char hostname[100];
    printf("Enter the hostname of the SMTP server: ");
    scanf("%s", hostname);

    // Get the port number of the SMTP server
    int port;
    printf("Enter the port number of the SMTP server: ");
    scanf("%d", &port);

    // Create a socket for communicating with the SMTP server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the IP address of the SMTP server
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *) host->h_addr;

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the HELO command to the SMTP server
    char helo_command[100];
    sprintf(helo_command, "HELO %s\r\n", hostname);
    if (send(sock, helo_command, strlen(helo_command), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Get the response from the SMTP server
    char response[100];
    if (recv(sock, response, sizeof(response), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the SMTP server
    printf("%s", response);

    // Send the MAIL FROM command to the SMTP server
    char mail_from_command[100];
    sprintf(mail_from_command, "MAIL FROM: <sender@example.com>\r\n");
    if (send(sock, mail_from_command, strlen(mail_from_command), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Get the response from the SMTP server
    if (recv(sock, response, sizeof(response), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the SMTP server
    printf("%s", response);

    // Send the RCPT TO command to the SMTP server
    char rcpt_to_command[100];
    sprintf(rcpt_to_command, "RCPT TO: <recipient@example.com>\r\n");
    if (send(sock, rcpt_to_command, strlen(rcpt_to_command), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Get the response from the SMTP server
    if (recv(sock, response, sizeof(response), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the SMTP server
    printf("%s", response);

    // Send the DATA command to the SMTP server
    char data_command[100];
    sprintf(data_command, "DATA\r\n");
    if (send(sock, data_command, strlen(data_command), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Get the response from the SMTP server
    if (recv(sock, response, sizeof(response), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the SMTP server
    printf("%s", response);

    // Send the email message to the SMTP server
    char email_message[1000];
    sprintf(email_message, "From: sender@example.com\nTo: recipient@example.com\nSubject: Test Email\n\nThis is a test email.\n\n");
    if (send(sock, email_message, strlen(email_message), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Send the dot command to the SMTP server to indicate the end of the email message
    char dot_command[100];
    sprintf(dot_command, ".\r\n");
    if (send(sock, dot_command, strlen(dot_command), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Get the response from the SMTP server
    if (recv(sock, response, sizeof(response), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the SMTP server
    printf("%s", response);

    // Send the QUIT command to the SMTP server to close the connection
    char quit_command[100];
    sprintf(quit_command, "QUIT\r\n");
    if (send(sock, quit_command, strlen(quit_command), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sock);

    return EXIT_SUCCESS;
}