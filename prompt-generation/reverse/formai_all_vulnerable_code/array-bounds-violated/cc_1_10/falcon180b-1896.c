//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_DATA_SIZE 1024
#define PORT "80"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    int addrlen;
    char recv_buff[MAX_DATA_SIZE];
    char send_buff[MAX_DATA_SIZE];
    int bytes_recv;
    int bytes_sent;
    int opt = 1;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <Port number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket creation failed\n");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(PORT));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    addrlen = sizeof(server_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, addrlen) == -1) {
        printf("Error: connection failed\n");
        exit(1);
    }

    printf("Connected to %s:%s\n", argv[1], PORT);

    while (1) {
        memset(send_buff, 0, MAX_DATA_SIZE);
        memset(recv_buff, 0, MAX_DATA_SIZE);

        sprintf(send_buff, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);

        bytes_sent = send(sockfd, send_buff, strlen(send_buff), 0);
        if (bytes_sent == -1) {
            printf("Error: send failed\n");
            exit(1);
        }

        bytes_recv = recv(sockfd, recv_buff, MAX_DATA_SIZE, 0);
        if (bytes_recv == -1) {
            printf("Error: recv failed\n");
            exit(1);
        } else if (bytes_recv == 0) {
            printf("Connection closed by server\n");
            exit(1);
        }

        recv_buff[bytes_recv] = '\0';
        printf("%s", recv_buff);
    }

    close(sockfd);
    return 0;
}