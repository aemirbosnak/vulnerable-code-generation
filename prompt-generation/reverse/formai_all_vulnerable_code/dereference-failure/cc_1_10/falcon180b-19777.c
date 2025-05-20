//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define BUF_SIZE 1024
#define TIME_OUT 5

struct sockaddr_in server_addr;
int sockfd;
int port;
char send_buf[BUF_SIZE];
char recv_buf[BUF_SIZE];

void error_handling(char *message) {
    perror(message);
    exit(0);
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        printf("Usage: %s <IP address> <port number> <filename>\n", argv[0]);
        exit(0);
    }

    strcpy(send_buf, argv[3]);
    port = atoi(argv[2]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        error_handling("socket failed");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0)
        error_handling("Invalid address/Address not supported");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error_handling("connect failed");

    printf("Connected to server\n");

    while (1) {
        if (send(sockfd, send_buf, strlen(send_buf), 0) < 0)
            error_handling("send failed");

        memset(recv_buf, 0, sizeof(recv_buf));
        if ((recv(sockfd, recv_buf, sizeof(recv_buf), 0)) <= 0)
            error_handling("recv failed");

        printf("Received from server: %s\n", recv_buf);

        usleep(500000); // sleep for 500ms
    }

    close(sockfd);
    return 0;
}