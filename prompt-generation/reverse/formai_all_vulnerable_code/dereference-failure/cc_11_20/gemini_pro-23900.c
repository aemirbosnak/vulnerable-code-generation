//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *host;
    char buffer[BUFSIZE];
    char username[100];
    char password[100];
    int port;

    if (argc < 5) {
        printf("Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[2]);
    strcpy(username, argv[3]);
    strcpy(password, argv[4]);

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: could not resolve hostname '%s'\n", argv[1]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: could not create socket");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error: could not connect to server");
        exit(1);
    }

    // Receive the welcome banner
    if (recv(sockfd, buffer, BUFSIZE, 0) < 0) {
        perror("Error: could not receive welcome banner");
        exit(1);
    }
    printf("%s", buffer);

    // Send the USER command
    sprintf(buffer, "USER %s\r\n", username);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error: could not send USER command");
        exit(1);
    }

    // Receive the USER response
    if (recv(sockfd, buffer, BUFSIZE, 0) < 0) {
        perror("Error: could not receive USER response");
        exit(1);
    }
    printf("%s", buffer);

    // Send the PASS command
    sprintf(buffer, "PASS %s\r\n", password);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error: could not send PASS command");
        exit(1);
    }

    // Receive the PASS response
    if (recv(sockfd, buffer, BUFSIZE, 0) < 0) {
        perror("Error: could not receive PASS response");
        exit(1);
    }
    printf("%s", buffer);

    // Send the STAT command
    sprintf(buffer, "STAT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error: could not send STAT command");
        exit(1);
    }

    // Receive the STAT response
    if (recv(sockfd, buffer, BUFSIZE, 0) < 0) {
        perror("Error: could not receive STAT response");
        exit(1);
    }
    printf("%s", buffer);

    // Send the LIST command
    sprintf(buffer, "LIST\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error: could not send LIST command");
        exit(1);
    }

    // Receive the LIST response
    while (true) {
        if (recv(sockfd, buffer, BUFSIZE, 0) < 0) {
            perror("Error: could not receive LIST response");
            exit(1);
        }

        printf("%s", buffer);

        if (strstr(buffer, ".\r\n") != NULL) {
            break;
        }
    }

    // Send the QUIT command
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error: could not send QUIT command");
        exit(1);
    }

    // Receive the QUIT response
    if (recv(sockfd, buffer, BUFSIZE, 0) < 0) {
        perror("Error: could not receive QUIT response");
        exit(1);
    }
    printf("%s", buffer);

    close(sockfd);

    return 0;
}