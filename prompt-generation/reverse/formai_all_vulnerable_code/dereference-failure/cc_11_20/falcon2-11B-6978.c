//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 25
#define MAX_BUFF 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFF];
    char command[MAX_BUFF];
    char message[MAX_BUFF];
    char reply[MAX_BUFF];

    if (argc!= 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    strcpy(command, "HELO");
    strcpy(message, argv[1]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        return 1;
    }

    strcpy(buffer, "MAIL FROM: ");
    strcat(buffer, argv[1]);
    strcat(buffer, "\r\n");

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message");
        return 1;
    }

    strcpy(buffer, "RCPT TO: ");
    strcat(buffer, argv[1]);
    strcat(buffer, "\r\n");

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message");
        return 1;
    }

    strcpy(buffer, "DATA\r\n");

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message");
        return 1;
    }

    strcpy(buffer, "Subject: ");
    strcat(buffer, argv[1]);
    strcat(buffer, "\r\n");

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message");
        return 1;
    }

    strcpy(buffer, "From: ");
    strcat(buffer, argv[1]);
    strcat(buffer, "\r\n");

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message");
        return 1;
    }

    strcpy(buffer, "To: ");
    strcat(buffer, argv[1]);
    strcat(buffer, "\r\n");

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message");
        return 1;
    }

    strcpy(buffer, "Subject: ");
    strcat(buffer, argv[1]);
    strcat(buffer, "\r\n");

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message");
        return 1;
    }

    strcpy(buffer, "From: ");
    strcat(buffer, argv[1]);
    strcat(buffer, "\r\n");

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message");
        return 1;
    }

    strcpy(buffer, "To: ");
    strcat(buffer, argv[1]);
    strcat(buffer, "\r\n");

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message");
        return 1;
    }

    strcpy(buffer, "\r\n.");

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message");
        return 1;
    }

    memset(buffer, '\0', sizeof(buffer));

    if ((n = recv(sockfd, buffer, MAX_BUFF, 0)) < 0) {
        perror("Error receiving message");
        return 1;
    }

    printf("%s", buffer);

    close(sockfd);

    return 0;
}