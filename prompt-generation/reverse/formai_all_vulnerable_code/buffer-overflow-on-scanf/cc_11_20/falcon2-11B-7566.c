//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Resolve server address
    server = gethostbyname("smtp.example.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(25);  // SMTP port

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    char buffer[1024];
    bzero(buffer, sizeof(buffer));

    printf("Enter your email address: ");
    scanf("%s", buffer);
    send(sockfd, buffer, strlen(buffer), 0);

    printf("Enter your message: ");
    scanf("%s", buffer);
    send(sockfd, buffer, strlen(buffer), 0);

    printf("Sending email...\n");

    // Send email command
    n = send(sockfd, "MAIL FROM:<youremail@example.com>\r\n", 30, 0);
    if (n < 0) {
        perror("ERROR sending email command");
        exit(1);
    }

    // Send recipient
    n = send(sockfd, "RCPT TO:<recipient@example.com>\r\n", 30, 0);
    if (n < 0) {
        perror("ERROR sending recipient");
        exit(1);
    }

    // Send data
    n = send(sockfd, "DATA\r\n", 8, 0);
    if (n < 0) {
        perror("ERROR sending data");
        exit(1);
    }

    // Send message data
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("ERROR sending message data");
        exit(1);
    }

    // Send end of message
    n = send(sockfd, ".\r\n", 4, 0);
    if (n < 0) {
        perror("ERROR sending end of message");
        exit(1);
    }

    // Send quit command
    n = send(sockfd, "QUIT\r\n", 10, 0);
    if (n < 0) {
        perror("ERROR sending quit command");
        exit(1);
    }

    // Receive server response
    bzero(buffer, sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("ERROR receiving server response");
        exit(1);
    }

    printf("Server response: %s\n", buffer);

    close(sockfd);

    return 0;
}