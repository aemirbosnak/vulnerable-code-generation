//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char buf[1024];
    int n;

    while (1) {
        n = recv(sockfd, buf, sizeof(buf), 0);
        if (n < 0) {
            perror("recv");
            break;
        } else if (n == 0) {
            printf("Connection closed by server.\n");
            break;
        }

        buf[n] = '\0';
        printf("%s", buf);

        if (strstr(buf, "+OK") != NULL) {
            printf("USER user@example.com\r\n");
        } else if (strstr(buf, "+OK USER") != NULL) {
            printf("PASS password\r\n");
        } else if (strstr(buf, "+OK PASS") != NULL) {
            printf("LIST\r\n");
        } else if (strstr(buf, "+OK LIST") != NULL) {
            while (1) {
                n = recv(sockfd, buf, sizeof(buf), 0);
                if (n < 0) {
                    perror("recv");
                    break;
                } else if (n == 0) {
                    printf("Connection closed by server.\n");
                    break;
                }

                buf[n] = '\0';
                printf("%s", buf);

                if (strstr(buf, ".") != NULL) {
                    break;
                }
            }
        } else {
            printf("Unknown response from server: %s\n", buf);
        }
    }

    close(sockfd);

    return EXIT_SUCCESS;
}