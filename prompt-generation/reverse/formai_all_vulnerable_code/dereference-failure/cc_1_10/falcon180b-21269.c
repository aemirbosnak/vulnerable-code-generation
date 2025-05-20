//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char send_buffer[BUFFER_SIZE], recv_buffer[BUFFER_SIZE];
    int opt = 1;
    int addrlen = sizeof(cli_addr);

    if (argc < 4) {
        printf("Usage:./ftp_client <IP> <port> <command>\n");
        exit(1);
    }

    strcpy(send_buffer, argv[2]);
    strcat(send_buffer, " ");
    strcat(send_buffer, argv[3]);
    send_buffer[strlen(send_buffer) - 1] = '\r';
    send_buffer[strlen(send_buffer) - 2] = '\n';

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("socket failed\n");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("connect failed\n");
        exit(1);
    }

    send(sockfd, send_buffer, strlen(send_buffer), 0);

    if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&addrlen)) < 0) {
        printf("accept failed\n");
        exit(1);
    }

    while (1) {
        memset(recv_buffer, '\0', BUFFER_SIZE);
        if (recv(newsockfd, recv_buffer, BUFFER_SIZE - 1, 0) <= 0) {
            printf("recv failed\n");
            exit(1);
        }
        printf("%s", recv_buffer);
    }

    close(sockfd);
    close(newsockfd);

    return 0;
}