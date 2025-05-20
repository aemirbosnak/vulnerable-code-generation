//Code Llama-13B DATASET v1.0 Category: Data recovery tool ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, new_fd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    char buffer[BUF_SIZE];
    char *ip_addr, *port_num;
    int port;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip_addr> <port_num>\n", argv[0]);
        exit(1);
    }

    ip_addr = argv[1];
    port_num = argv[2];
    port = atoi(port_num);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_addr);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    while (1) {
        bzero(buffer, BUF_SIZE);
        fgets(buffer, BUF_SIZE, stdin);
        if (buffer[strlen(buffer) - 1] == '\n')
            buffer[strlen(buffer) - 1] = '\0';

        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("send failed");
            exit(1);
        }

        if ((new_fd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_len)) < 0) {
            perror("accept failed");
            exit(1);
        }

        if (recv(new_fd, buffer, BUF_SIZE, 0) < 0) {
            perror("recv failed");
            exit(1);
        }

        printf("Received data: %s\n", buffer);
    }

    return 0;
}