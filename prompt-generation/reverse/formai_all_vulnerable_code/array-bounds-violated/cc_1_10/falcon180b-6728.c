//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define BUF_LEN 1024

struct sockaddr_in server_addr;
int sockfd;

int main() {
    char *server_ip = "192.168.1.1";
    int server_port = 80;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);
    server_addr.sin_port = htons(server_port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    char send_buf[1024] = "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: close\r\n\r\n";
    send(sockfd, send_buf, strlen(send_buf), 0);

    char recv_buf[BUF_LEN];
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, recv_buf, BUF_LEN - 1, 0)) > 0) {
        recv_buf[bytes_received] = '\0';
        printf("%s", recv_buf);
    }

    close(sockfd);
    return 0;
}