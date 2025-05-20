#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024

void error_exit(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP> <Port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
        error_exit("Socket creation failed");

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    while (1) {
        n = recvfrom(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *)&cli_addr, NULL);
        if (n < 0)
            error_exit("Error reading packet");

        printf("Received packet from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
        fgets(buffer, BUF_SIZE, stdin); // vulnerability: potential buffer overflow in fgets
        sendto(sockfd, buffer, n, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    }

    close(sockfd);
    return 0;
}
