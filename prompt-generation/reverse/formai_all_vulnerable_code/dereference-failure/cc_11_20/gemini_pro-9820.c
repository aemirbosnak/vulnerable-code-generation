//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    // The hostname of the SMTP server we want to connect to.
    char *hostname = "smtp.example.com";

    // The port number of the SMTP server.
    int port = 25;

    // The sender's email address.
    char *sender = "sender@example.com";

    // The recipient's email address.
    char *recipient = "recipient@example.com";

    // The subject of the email.
    char *subject = "Hello World!";

    // The body of the email.
    char *body = "This is a test email.\n\nPlease ignore.";

    // The socket we will use to connect to the SMTP server.
    int sockfd;

    // The buffer we will use to store the data we send and receive.
    char buffer[1024];

    // The number of bytes we have sent or received.
    int nbytes;

    // Create a socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the IP address of the SMTP server.
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Receive the welcome message from the SMTP server.
    nbytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (nbytes == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the HELO command.
    sprintf(buffer, "HELO %s\r\n", hostname);
    nbytes = send(sockfd, buffer, strlen(buffer), 0);
    if (nbytes == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response to the HELO command.
    nbytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (nbytes == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command.
    sprintf(buffer, "MAIL FROM: %s\r\n", sender);
    nbytes = send(sockfd, buffer, strlen(buffer), 0);
    if (nbytes == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response to the MAIL FROM command.
    nbytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (nbytes == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command.
    sprintf(buffer, "RCPT TO: %s\r\n", recipient);
    nbytes = send(sockfd, buffer, strlen(buffer), 0);
    if (nbytes == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response to the RCPT TO command.
    nbytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (nbytes == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the DATA command.
    sprintf(buffer, "DATA\r\n");
    nbytes = send(sockfd, buffer, strlen(buffer), 0);
    if (nbytes == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response to the DATA command.
    nbytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (nbytes == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the email headers.
    sprintf(buffer, "From: %s\r\n", sender);
    nbytes = send(sockfd, buffer, strlen(buffer), 0);
    if (nbytes == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    sprintf(buffer, "To: %s\r\n", recipient);
    nbytes = send(sockfd, buffer, strlen(buffer), 0);
    if (nbytes == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    sprintf(buffer, "Subject: %s\r\n", subject);
    nbytes = send(sockfd, buffer, strlen(buffer), 0);
    if (nbytes == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Send the email body.
    nbytes = send(sockfd, body, strlen(body), 0);
    if (nbytes == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Send the end of the email.
    sprintf(buffer, "\r\n.\r\n");
    nbytes = send(sockfd, buffer, strlen(buffer), 0);
    if (nbytes == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response to the end of the email.
    nbytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (nbytes == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the QUIT command.
    sprintf(buffer, "QUIT\r\n");
    nbytes = send(sockfd, buffer, strlen(buffer), 0);
    if (nbytes == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}