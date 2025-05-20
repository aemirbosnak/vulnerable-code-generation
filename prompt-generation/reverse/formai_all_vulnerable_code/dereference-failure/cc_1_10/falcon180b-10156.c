//Falcon-180B DATASET v1.0 Category: Networking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>

#define MAX 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[MAX];
    int n, sd;
    time_t ticks;

    if (argc < 3) {
        fprintf(stderr, "usage: %s <IP address> <port number>\n", argv[0]);
        exit(0);
    }

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd == 0) {
        perror("socket failed");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(0);
    }

    printf("Connected to %s:%d\n", argv[1], atoi(argv[2]));

    while (1) {
        bzero(buffer, MAX);
        n = read(sd, buffer, MAX);
        if (n < 0) {
            perror("read failed");
            exit(0);
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sd);
    return 0;
}