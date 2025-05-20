//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    char *port = argv[2];

    // Resolve IP address
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    int error = getaddrinfo(hostname, port, &hints, &result);
    if (error != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(error));
        exit(EXIT_FAILURE);
    }

    // Create socket
    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    error = connect(sockfd, result->ai_addr, result->ai_addrlen);
    if (error == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Receive greeting message from server
    char buf[MAX_BUF_SIZE];
    ssize_t n = recv(sockfd, buf, MAX_BUF_SIZE, 0);
    if (n == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buf[n] = '\0';
    printf("%s", buf);

    // Send username
    char username[MAX_BUF_SIZE];
    printf("Username: ");
    scanf("%s", username);
    sprintf(buf, "USER %s\r\n", username);
    error = send(sockfd, buf, strlen(buf), 0);
    if (error == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    n = recv(sockfd, buf, MAX_BUF_SIZE, 0);
    if (n == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buf[n] = '\0';
    printf("%s", buf);

    // Send password
    char password[MAX_BUF_SIZE];
    printf("Password: ");
    scanf("%s", password);
    sprintf(buf, "PASS %s\r\n", password);
    error = send(sockfd, buf, strlen(buf), 0);
    if (error == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    n = recv(sockfd, buf, MAX_BUF_SIZE, 0);
    if (n == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buf[n] = '\0';
    printf("%s", buf);

    // Send LIST command
    sprintf(buf, "LIST\r\n");
    error = send(sockfd, buf, strlen(buf), 0);
    if (error == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive list of messages from server
    while (1) {
        n = recv(sockfd, buf, MAX_BUF_SIZE, 0);
        if (n == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }
        buf[n] = '\0';
        printf("%s", buf);
        if (strcmp(buf, ".\r\n") == 0) {
            break;
        }
    }

    // Quit
    sprintf(buf, "QUIT\r\n");
    error = send(sockfd, buf, strlen(buf), 0);
    if (error == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive farewell message from server
    n = recv(sockfd, buf, MAX_BUF_SIZE, 0);
    if (n == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buf[n] = '\0';
    printf("%s", buf);

    // Clean up
    close(sockfd);
    freeaddrinfo(result);

    return 0;
}