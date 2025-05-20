//Code Llama-13B DATASET v1.0 Category: Temperature monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[MAX_BUF_SIZE];
    char *message, *ip, *port;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;
    struct timeval tv;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP> <Port> <Message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ip = argv[1];
    port = argv[2];
    message = argv[3];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip);
    servaddr.sin_port = htons(atoi(port));

    if (sendto(sockfd, message, strlen(message), 0,
               (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("sendto failed");
        exit(EXIT_FAILURE);
    }

    close(sockfd);
    exit(EXIT_SUCCESS);
}