//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Connect to the POP3 server
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(POP3_PORT);
    addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send the initial greeting
    char buf[1024];
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Send the username
    snprintf(buf, sizeof(buf), "USER %s\r\n", username);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Send the password
    char password[1024];
    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    strtok(password, "\n");
    snprintf(buf, sizeof(buf), "PASS %s\r\n", password);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Send the STAT command
    snprintf(buf, sizeof(buf), "STAT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Send the LIST command
    snprintf(buf, sizeof(buf), "LIST\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Send the RETR command
    snprintf(buf, sizeof(buf), "RETR 1\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Send the DELE command
    snprintf(buf, sizeof(buf), "DELE 1\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Send the QUIT command
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}