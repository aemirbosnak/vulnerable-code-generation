//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <server> <from> <to> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *server = argv[1];
    char *from = argv[2];
    char *to = argv[3];
    char *message = argv[4];

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);

    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", server);
        return EXIT_FAILURE;
    }

    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: could not create socket");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error: could not connect to server");
        return EXIT_FAILURE;
    }

    char buffer[1024];
    int n;

    // Receive the server's greeting
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n == -1) {
        perror("Error: could not receive server greeting");
        return EXIT_FAILURE;
    }

    // Send the HELO command
    sprintf(buffer, "HELO %s\r\n", "localhost");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n == -1) {
        perror("Error: could not send HELO command");
        return EXIT_FAILURE;
    }

    // Receive the server's response
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n == -1) {
        perror("Error: could not receive server response");
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command
    sprintf(buffer, "MAIL FROM: <%s>\r\n", from);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n == -1) {
        perror("Error: could not send MAIL FROM command");
        return EXIT_FAILURE;
    }

    // Receive the server's response
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n == -1) {
        perror("Error: could not receive server response");
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command
    sprintf(buffer, "RCPT TO: <%s>\r\n", to);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n == -1) {
        perror("Error: could not send RCPT TO command");
        return EXIT_FAILURE;
    }

    // Receive the server's response
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n == -1) {
        perror("Error: could not receive server response");
        return EXIT_FAILURE;
    }

    // Send the DATA command
    n = send(sockfd, "DATA\r\n", 6, 0);
    if (n == -1) {
        perror("Error: could not send DATA command");
        return EXIT_FAILURE;
    }

    // Receive the server's response
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n == -1) {
        perror("Error: could not receive server response");
        return EXIT_FAILURE;
    }

    // Send the message
    sprintf(buffer, "%s\r\n.\r\n", message);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n == -1) {
        perror("Error: could not send message");
        return EXIT_FAILURE;
    }

    // Receive the server's response
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n == -1) {
        perror("Error: could not receive server response");
        return EXIT_FAILURE;
    }

    // Send the QUIT command
    n = send(sockfd, "QUIT\r\n", 6, 0);
    if (n == -1) {
        perror("Error: could not send QUIT command");
        return EXIT_FAILURE;
    }

    // Receive the server's response
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n == -1) {
        perror("Error: could not receive server response");
        return EXIT_FAILURE;
    }

    close(sockfd);

    return EXIT_SUCCESS;
}