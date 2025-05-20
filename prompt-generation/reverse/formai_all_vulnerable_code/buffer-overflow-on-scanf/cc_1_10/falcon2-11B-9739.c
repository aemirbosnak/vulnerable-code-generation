//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024], command[256], response[256];
    int num_bytes_read;

    printf("Enter the server hostname or IP address: ");
    scanf("%s", &command);

    memset(buffer, 0, sizeof(buffer));
    memset(response, 0, sizeof(response));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(25); // SMTP port
    serv_addr.sin_addr.s_addr = inet_addr(command); // Convert hostname to IP address
    bzero((char *) &(serv_addr.sin_zero), 8);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s.\n", inet_ntoa(serv_addr.sin_addr));

    printf("Enter the email address to send the email to: ");
    scanf("%s", &command);

    memset(buffer, 0, sizeof(buffer));
    memset(response, 0, sizeof(response));

    snprintf(buffer, sizeof(buffer), "HELO localhost\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", command);
    send(sockfd, buffer, strlen(buffer), 0);

    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", command);
    send(sockfd, buffer, strlen(buffer), 0);

    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    snprintf(buffer, sizeof(buffer), "From: %s\r\n", command);
    send(sockfd, buffer, strlen(buffer), 0);

    snprintf(buffer, sizeof(buffer), "To: %s\r\n", command);
    send(sockfd, buffer, strlen(buffer), 0);

    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n", "Test Email");
    send(sockfd, buffer, strlen(buffer), 0);

    snprintf(buffer, sizeof(buffer), "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    snprintf(buffer, sizeof(buffer), "This is a test email.\r\n.\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    num_bytes_read = recv(sockfd, response, sizeof(response), 0);
    if (num_bytes_read == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    printf("Server response: %s\n", response);

    close(sockfd);
    return 0;
}