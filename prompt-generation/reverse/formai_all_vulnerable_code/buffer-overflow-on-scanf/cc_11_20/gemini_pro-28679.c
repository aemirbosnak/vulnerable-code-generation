//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define POP3_PORT 110
#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <server> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *server = argv[1];
    char *username = argv[2];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, server, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Receive the welcome message
    char buf[MAX_BUF_SIZE];
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the username
    snprintf(buf, sizeof(buf), "USER %s\r\n", username);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the OK message
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the password
    char *password = getpass("Password: ");
    snprintf(buf, sizeof(buf), "PASS %s\r\n", password);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the OK message
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // List the messages
    snprintf(buf, sizeof(buf), "LIST\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the message list
    while (1) {
        if (recv(sockfd, buf, MAX_BUF_SIZE, 0) == -1) {
            perror("recv");
            return EXIT_FAILURE;
        }
        printf("%s", buf);
        if (strstr(buf, "\r\n.\r\n") != NULL) {
            break;
        }
    }

    // Retrieve a message
    char msg_num[10];
    printf("Enter message number: ");
    scanf("%s", msg_num);

    snprintf(buf, sizeof(buf), "RETR %s\r\n", msg_num);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the message
    while (1) {
        if (recv(sockfd, buf, MAX_BUF_SIZE, 0) == -1) {
            perror("recv");
            return EXIT_FAILURE;
        }
        printf("%s", buf);
        if (strstr(buf, "\r\n.\r\n") != NULL) {
            break;
        }
    }

    // Quit
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}