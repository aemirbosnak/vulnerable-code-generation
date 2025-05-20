//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in servaddr;

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Socket creation failed\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "Connection failed\n");
        exit(1);
    }

    char buffer[1024];
    int n;

    while (1) {
        printf("ftp> ");
        scanf("%s", buffer);

        if (strcmp(buffer, "quit") == 0) {
            break;
        }

        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            fprintf(stderr, "Write failed\n");
            exit(1);
        }

        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
            fprintf(stderr, "Read failed\n");
            exit(1);
        }

        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}