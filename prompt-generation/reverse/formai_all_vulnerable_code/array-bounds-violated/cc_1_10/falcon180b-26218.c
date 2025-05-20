//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 1024
#define POP3_PORT 110
#define POP3_USER "username"
#define POP3_PASS "password"
#define POP3_QUIT "QUIT\r\n"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char response[MAX_LINE];
    char buffer[MAX_LINE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr("localhost");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to POP3 server\n");

    send(sockfd, POP3_USER, strlen(POP3_USER), 0);
    send(sockfd, POP3_PASS, strlen(POP3_PASS), 0);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        n = recv(sockfd, buffer, MAX_LINE, 0);
        if (n <= 0) {
            printf("Disconnected from POP3 server\n");
            break;
        }
        buffer[n] = '\0';
        printf("Received: %s", buffer);
        if (strstr(buffer, "+OK")!= NULL) {
            printf("Authentication successful\n");
        } else if (strstr(buffer, "-ERR")!= NULL) {
            printf("Authentication failed\n");
        }
    }

    send(sockfd, POP3_QUIT, strlen(POP3_QUIT), 0);

    close(sockfd);

    return 0;
}