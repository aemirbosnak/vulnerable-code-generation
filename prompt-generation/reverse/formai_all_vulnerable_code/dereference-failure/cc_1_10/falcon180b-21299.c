//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_buff[1024];
    char recv_buff[1024];

    if (argc!= 3) {
        printf("Usage:./client <IP_Address> <Port_Number>\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Socket creation failed\n");
        exit(0);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Connection failed\n");
        exit(0);
    }

    printf("Connection established with server\n");

    while (1) {
        memset(send_buff, 0, sizeof(send_buff));
        memset(recv_buff, 0, sizeof(recv_buff));

        sprintf(send_buff, "GET / HTTP/1.1\r\nHost: %s:%d\r\nConnection: close\r\n\r\n", argv[1], atoi(argv[2]));

        if (send(sockfd, send_buff, strlen(send_buff), 0) == -1) {
            printf("Data send failed\n");
            exit(0);
        }

        if (recv(sockfd, recv_buff, sizeof(recv_buff), 0) == -1) {
            printf("Data receive failed\n");
            exit(0);
        }

        printf("Received data: %s", recv_buff);
    }

    close(sockfd);

    return 0;
}