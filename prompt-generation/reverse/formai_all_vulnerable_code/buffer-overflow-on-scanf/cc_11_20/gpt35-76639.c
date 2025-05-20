//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    int sock_desc, port_no, num_chars_sent;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[256];

    printf("Welcome to the SMTP Client program! Let's send some emails!\n\n");

    // Ask for the server name and port number
    char server_name[50];
    printf("Enter the server name: ");
    scanf("%s", server_name);
    printf("Enter the port number: ");
    scanf("%d", &port_no);

    // Get the server details
    server = gethostbyname(server_name);
    if (server == NULL) {
        printf("\nCould not connect to host. Please try again later.\n");
        exit(0);
    }

    // Create the socket
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_desc < 0) {
        printf("\nCould not create socket. Please try again later.\n");
        exit(0);
    }

    // Set the server address
    memset(&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_no);
    inet_pton(AF_INET, server->h_addr, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sock_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("\nCould not connect to server. Please try again later.\n");
        exit(0);
    }

    // Receive the helo message from the server
    memset(buffer, '\0', sizeof(buffer));
    if (read(sock_desc, buffer, sizeof(buffer)) < 0) {
        printf("\nError reading from server.\n");
        exit(0);
    }
    printf("%s\n", buffer);

    // Send the mail from command
    char mail_from[50];
    printf("\nEnter your email address: ");
    scanf("%s", mail_from);
    sprintf(buffer, "mail from: %s\n", mail_from);
    num_chars_sent = write(sock_desc, buffer, strlen(buffer));
    if (num_chars_sent < 0) {
        printf("\nError sending mail from command.\n");
        exit(0);
    }

    // Receive the server response
    memset(buffer, '\0', sizeof(buffer));
    if (read(sock_desc, buffer, sizeof(buffer)) < 0) {
        printf("\nError reading from server.\n");
        exit(0);
    }
    printf("%s\n", buffer);

    // Send the rcpt to command
    char mail_to[50];
    printf("\nEnter the recipient's email address: ");
    scanf("%s", mail_to);
    sprintf(buffer, "rcpt to: %s\n", mail_to);
    num_chars_sent = write(sock_desc, buffer, strlen(buffer));
    if (num_chars_sent < 0) {
        printf("\nError sending rcpt to command.\n");
        exit(0);
    }

    // Receive the server response
    memset(buffer, '\0', sizeof(buffer));
    if (read(sock_desc, buffer, sizeof(buffer)) < 0) {
        printf("\nError reading from server.\n");
        exit(0);
    }
    printf("%s\n", buffer);

    // Send the data command
    sprintf(buffer, "data\n");
    num_chars_sent = write(sock_desc, buffer, strlen(buffer));
    if (num_chars_sent < 0) {
        printf("\nError sending data command.\n");
        exit(0);
    }

    // Receive the server response
    memset(buffer, '\0', sizeof(buffer));
    if (read(sock_desc, buffer, sizeof(buffer)) < 0) {
        printf("\nError reading from server.\n");
        exit(0);
    }
    printf("%s\n", buffer);

    // Send the message body
    char message_body[500];
    printf("\nEnter the message body: ");
    scanf("%s", message_body);
    num_chars_sent = write(sock_desc, message_body, strlen(message_body));
    if (num_chars_sent < 0) {
        printf("\nError sending message body.\n");
        exit(0);
    }

    // Send the period character to end the message
    sprintf(buffer, ".\n");
    num_chars_sent = write(sock_desc, buffer, strlen(buffer));
    if (num_chars_sent < 0) {
        printf("\nError sending period character.\n");
        exit(0);
    }

    // Receive the server response
    memset(buffer, '\0', sizeof(buffer));
    if (read(sock_desc, buffer, sizeof(buffer)) < 0) {
        printf("\nError reading from server.\n");
        exit(0);
    }
    printf("%s\n", buffer);

    // Send the quit command to end the session
    sprintf(buffer, "quit\n");
    num_chars_sent = write(sock_desc, buffer, strlen(buffer));
    if (num_chars_sent < 0) {
        printf("\nError sending quit command.\n");
        exit(0);
    }

    // Receive the server response
    memset(buffer, '\0', sizeof(buffer));
    if (read(sock_desc, buffer, sizeof(buffer)) < 0) {
        printf("\nError reading from server.\n");
        exit(0);
    }
    printf("%s\n", buffer);

    // Close the socket
    close(sock_desc);
    printf("\nEmail sent successfully! Thanks for using the SMTP Client program!\n");

    return 0;
}