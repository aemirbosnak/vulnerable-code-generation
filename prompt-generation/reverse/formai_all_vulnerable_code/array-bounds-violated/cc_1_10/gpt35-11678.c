//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

#define MAX_BUF_SIZE 1024

// Function to create a socket and connect to the SMTP server.
int connect_to_server(char *server_addr, int server_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_addr);
    server.sin_port = htons(server_port);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("connection to server failed");
        exit(EXIT_FAILURE);
    }

    return sock;
}

// Function to check the server response code.
void check_response(char *response) {
    if (response[0] != '2' && response[0] != '3') {
        printf("%s\n", response);
        exit(EXIT_FAILURE);
    }
}

int main() {
    char server_addr[MAX_BUF_SIZE];
    int server_port;
    char sender_addr[MAX_BUF_SIZE];
    char recipient_addr[MAX_BUF_SIZE];
    char user[MAX_BUF_SIZE];
    char pass[MAX_BUF_SIZE];

    printf("Welcome to my SMTP Client program!\n");

    printf("\nEnter the SMTP server address: ");
    fgets(server_addr, sizeof(server_addr), stdin);
    server_addr[strcspn(server_addr, "\n")] = 0;

    printf("Enter the SMTP server port: ");
    scanf("%d", &server_port);
    getchar(); // clear stdin

    printf("Enter your email address: ");
    fgets(sender_addr, sizeof(sender_addr), stdin);
    sender_addr[strcspn(sender_addr, "\n")] = 0;

    printf("Enter the recipient email address: ");
    fgets(recipient_addr, sizeof(recipient_addr), stdin);
    recipient_addr[strcspn(recipient_addr, "\n")] = 0;

    printf("Enter your SMTP username: ");
    fgets(user, sizeof(user), stdin);
    user[strcspn(user, "\n")] = 0;

    printf("Enter your SMTP password: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = 0;

    int sock = connect_to_server(server_addr, server_port);

    char buffer[MAX_BUF_SIZE];
    int bytes_read = recv(sock, buffer, sizeof(buffer), 0);
    buffer[bytes_read] = '\0';
    printf("%s\n", buffer);
    check_response(buffer);

    // Send the HELO command.
    sprintf(buffer, "EHLO %s\r\n", server_addr);
    send(sock, buffer, strlen(buffer), 0);
    bytes_read = recv(sock, buffer, sizeof(buffer), 0);
    buffer[bytes_read] = '\0';
    printf("%s\n", buffer);
    check_response(buffer);

    // Send the AUTH LOGIN command.
    sprintf(buffer, "AUTH LOGIN\r\n");
    send(sock, buffer, strlen(buffer), 0);
    bytes_read = recv(sock, buffer, sizeof(buffer), 0);
    buffer[bytes_read] = '\0';
    printf("%s\n", buffer);
    check_response(buffer);

    // Send the SMTP username in base64 encoding.
    sprintf(buffer, "%s\r\n", user);
    send(sock, buffer, strlen(buffer), 0);
    bytes_read = recv(sock, buffer, sizeof(buffer), 0);
    buffer[bytes_read] = '\0';
    printf("%s\n", buffer);
    check_response(buffer);

    // Send the SMTP password in base64 encoding.
    sprintf(buffer, "%s\r\n", pass);
    send(sock, buffer, strlen(buffer), 0);
    bytes_read = recv(sock, buffer, sizeof(buffer), 0);
    buffer[bytes_read] = '\0';
    printf("%s\n", buffer);
    check_response(buffer);

    // Send the MAIL FROM command.
    sprintf(buffer, "MAIL FROM: <%s>\r\n", sender_addr);
    send(sock, buffer, strlen(buffer), 0);
    bytes_read = recv(sock, buffer, sizeof(buffer), 0);
    buffer[bytes_read] = '\0';
    printf("%s\n", buffer);
    check_response(buffer);

    // Send the RCPT TO command.
    sprintf(buffer, "RCPT TO: <%s>\r\n", recipient_addr);
    send(sock, buffer, strlen(buffer), 0);
    bytes_read = recv(sock, buffer, sizeof(buffer), 0);
    buffer[bytes_read] = '\0';
    printf("%s\n", buffer);
    check_response(buffer);

    // Send the DATA command.
    sprintf(buffer, "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);
    bytes_read = recv(sock, buffer, sizeof(buffer), 0);
    buffer[bytes_read] = '\0';
    printf("%s\n", buffer);
    check_response(buffer);

    // Send the message body.
    printf("Enter your message (press Ctrl+D when finished):\n");
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        send(sock, buffer, strlen(buffer), 0);
    }

    // Send the terminating sequence.
    sprintf(buffer, "\r\n.\r\n");
    send(sock, buffer, strlen(buffer), 0);
    bytes_read = recv(sock, buffer, sizeof(buffer), 0);
    buffer[bytes_read] = '\0';
    printf("%s\n", buffer);
    check_response(buffer);

    // Send the QUIT command.
    sprintf(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    bytes_read = recv(sock, buffer, sizeof(buffer), 0);
    buffer[bytes_read] = '\0';
    printf("%s\n", buffer);

    // Close the socket.
    close(sock);

    printf("\nMessage sent!\n");

    return 0;
}