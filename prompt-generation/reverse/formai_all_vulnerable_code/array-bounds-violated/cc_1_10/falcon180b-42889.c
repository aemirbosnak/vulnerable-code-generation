//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_data[BUFFER_SIZE];
    char recv_data[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("socket failed");

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("connect failed");

    srand(time(NULL));
    int random_num = rand() % 100;

    sprintf(send_data, "GET /speedtest?random=%d HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", random_num, SERVER_IP);

    if (send(sockfd, send_data, strlen(send_data), 0) < 0)
        error("send failed");

    while ((n = recv(sockfd, recv_data, BUFFER_SIZE, 0)) > 0) {
        recv_data[n] = '\0';
        printf("%s", recv_data);
    }

    close(sockfd);
    return 0;
}