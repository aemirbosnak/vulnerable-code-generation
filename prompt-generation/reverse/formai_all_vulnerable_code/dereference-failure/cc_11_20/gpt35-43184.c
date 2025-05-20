//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_LEN 1024
#define MAX_CMD_LEN 100
#define MAX_RESP_LEN 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "USAGE: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct hostent *he = gethostbyname(argv[1]);
    if (he == NULL) {
        herror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    server_addr.sin_port = htons(110);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char buf[MAX_BUF_LEN] = "";
    char cmd[MAX_CMD_LEN] = "";
    char resp[MAX_RESP_LEN] = "";

    sprintf(buf, "USER %s\r\n", argv[2]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send USER");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, resp, MAX_RESP_LEN, 0) == -1) {
        perror("recv USER");
        exit(EXIT_FAILURE);
    }

    sprintf(buf, "PASS %s\r\n", argv[3]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send PASS");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, resp, MAX_RESP_LEN, 0) == -1) {
        perror("recv PASS");
        exit(EXIT_FAILURE);
    }

    sprintf(buf, "STAT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send STAT");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, resp, MAX_RESP_LEN, 0) == -1) {
        perror("recv STAT");
        exit(EXIT_FAILURE);
    }

    int num_messages = 0;
    sscanf(resp, "+OK %d %*d", &num_messages);
    if (num_messages == 0) {
        printf("No new messages\n");
    } else {
        printf("You have %d new messages\n", num_messages);

        for (int i = 1; i <= num_messages; i++) {
            sprintf(buf, "RETR %d\r\n", i);
            if (send(sockfd, buf, strlen(buf), 0) == -1) {
                perror("send RETR");
                exit(EXIT_FAILURE);
            }

            if (recv(sockfd, resp, MAX_RESP_LEN, 0) == -1) {
                perror("recv RETR");
                exit(EXIT_FAILURE);
            }

            printf("Message %d:\n%s\n", i, resp);
        }
    }

    sprintf(buf, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send QUIT");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, resp, MAX_RESP_LEN, 0) == -1) {
        perror("recv QUIT");
        exit(EXIT_FAILURE);
    }

    printf("%s", resp);

    close(sockfd);

    return EXIT_SUCCESS;
}