//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAXLINE 1024
#define POP3_PORT 110

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s server username\n", argv[0]);
        exit(1);
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password;

    printf("Enter password: ");
    fflush(stdout);
    password = getpass("");

    // Start connection
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    struct hostent *he = gethostbyname(server);
    if (he == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    struct sockaddr_in servaddr = {0};
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);
    bcopy(he->h_addr_list[0], &servaddr.sin_addr, he->h_length);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    char buffer[MAXLINE] = {0};
    int n = recv(sockfd, buffer, MAXLINE, 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }
    printf("Server message: %s", buffer);

    // Send authentication
    char auth[MAXLINE] = {0};
    sprintf(auth, "USER %s\r\n", username);
    if (send(sockfd, auth, strlen(auth), 0) < 0) {
        perror("send");
        exit(1);
    }

    n = recv(sockfd, buffer, MAXLINE, 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }
    printf("Server message: %s", buffer);

    sprintf(auth, "PASS %s\r\n", password);
    if (send(sockfd, auth, strlen(auth), 0) < 0) {
        perror("send");
        exit(1);
    }

    n = recv(sockfd, buffer, MAXLINE, 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }
    printf("Server message: %s", buffer);

    // List messages
    char list[MAXLINE] = {0};
    sprintf(list, "LIST\r\n");
    if (send(sockfd, list, strlen(list), 0) < 0) {
        perror("send");
        exit(1);
    }

    n = recv(sockfd, buffer, MAXLINE, 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }
    printf("Server message: %s", buffer);

    // Close connection
    close(sockfd);

    return 0;
}