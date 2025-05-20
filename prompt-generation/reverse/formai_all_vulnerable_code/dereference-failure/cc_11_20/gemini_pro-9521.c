//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define POP3_PORT 110

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() failed");
        exit(1);
    }

    struct hostent *host = gethostbyname("pop.example.com");
    if (host == NULL) {
        perror("gethostbyname() failed");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect() failed");
        exit(1);
    }

    char buf[1024];
    int n;

    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv() failed");
        exit(1);
    }

    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Unexpected response from server: %s", buf);
        exit(1);
    }

    printf("USER username\r\n");
    fflush(stdout);

    n = recv(sockfd, buf, sizeof(buf), 0);
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Unexpected response from server: %s", buf);
        exit(1);
    }

    printf("PASS password\r\n");
    fflush(stdout);

    n = recv(sockfd, buf, sizeof(buf), 0);
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Unexpected response from server: %s", buf);
        exit(1);
    }

    printf("STAT\r\n");
    fflush(stdout);

    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv() failed");
        exit(1);
    }

    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Unexpected response from server: %s", buf);
        exit(1);
    }

    int num_messages;
    int total_size;
    sscanf(buf, "+OK %d %d", &num_messages, &total_size);

    printf("LIST\r\n");
    fflush(stdout);

    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv() failed");
        exit(1);
    }

    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Unexpected response from server: %s", buf);
        exit(1);
    }

    int i;
    for (i = 0; i < num_messages; i++) {
        n = recv(sockfd, buf, sizeof(buf), 0);
        if (n == -1) {
            perror("recv() failed");
            exit(1);
        }

        int message_num;
        int message_size;
        sscanf(buf, "%d %d", &message_num, &message_size);

        printf("Message %d: %d bytes\n", message_num, message_size);
    }

    printf("QUIT\r\n");
    fflush(stdout);

    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv() failed");
        exit(1);
    }

    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Unexpected response from server: %s", buf);
        exit(1);
    }

    close(sockfd);

    return 0;
}