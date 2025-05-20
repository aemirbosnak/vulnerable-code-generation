//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define MAX 1024
#define PORT 21

int main(int argc, char *argv[]) {
    int fd, sockfd, bytes_recv;
    struct sockaddr_in server_addr;
    char command[MAX], server_reply[MAX];

    if(argc < 2) {
        printf("Usage: %s server_address\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr))) {
        perror("connect failed");
        exit(1);
    }

    bytes_recv = recv(sockfd, server_reply, MAX-1, 0);
    server_reply[bytes_recv] = '\0';
    printf("Server message: %s", server_reply);

    while(1) {
        printf("ftp> ");
        fgets(command, MAX, stdin);
        if(strncmp(command, "QUIT", 4) == 0) {
            send(sockfd, command, strlen(command), 0);
            recv(sockfd, server_reply, MAX-1, 0);
            server_reply[bytes_recv] = '\0';
            printf("%s", server_reply);
            break;
        }
        else {
            send(sockfd, command, strlen(command), 0);
            bytes_recv = recv(sockfd, server_reply, MAX-1, 0);
            server_reply[bytes_recv] = '\0';
            printf("%s", server_reply);
        }
    }

    close(sockfd);
    return 0;
}