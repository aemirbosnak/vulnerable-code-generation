//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    // Initialize variables.
    int sockfd, port;
    struct sockaddr_in serv_addr;
    char *hostname, *username, *password, *to_email, *from_email, *subject, *body;
    char buffer[1024];

    // Get user input.
    printf("Enter the hostname of the SMTP server: ");
    scanf("%s", hostname);
    printf("Enter the port number of the SMTP server (default: 25): ");
    scanf("%d", &port);
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    printf("Enter the recipient's email address: ");
    scanf("%s", to_email);
    printf("Enter your email address: ");
    scanf("%s", from_email);
    printf("Enter the subject of the email: ");
    scanf(" %[^\n]", subject);
    printf("Enter the body of the email: ");
    scanf(" %[^\n]", body);

    // Create a socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Connect to the server.
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(hostname);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send the HELO command.
    sprintf(buffer, "HELO %s\r\n", hostname);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    // Send the AUTH LOGIN command.
    sprintf(buffer, "AUTH LOGIN\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    // Send the username.
    sprintf(buffer, "%s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    // Send the password.
    sprintf(buffer, "%s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    // Send the MAIL FROM command.
    sprintf(buffer, "MAIL FROM: <%s>\r\n", from_email);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    // Send the RCPT TO command.
    sprintf(buffer, "RCPT TO: <%s>\r\n", to_email);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    // Send the DATA command.
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    // Send the email.
    sprintf(buffer, "From: <%s>\r\n", from_email);
    send(sockfd, buffer, strlen(buffer), 0);
    sprintf(buffer, "To: <%s>\r\n", to_email);
    send(sockfd, buffer, strlen(buffer), 0);
    sprintf(buffer, "Subject: %s\r\n", subject);
    send(sockfd, buffer, strlen(buffer), 0);
    sprintf(buffer, "\r\n%s\r\n", body);
    send(sockfd, buffer, strlen(buffer), 0);

    // Send the QUIT command.
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    // Close the socket.
    close(sockfd);

    return 0;
}