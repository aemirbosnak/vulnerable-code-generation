//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER "speedtest.net"
#define PORT 80
#define BUFFER_SIZE 1024
#define DATA_SIZE 1024*1024

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_data[BUFFER_SIZE];
    char recv_data[BUFFER_SIZE];
    unsigned long int start_time, end_time;
    double elapsed_time;
    double speed;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    start_time = time(NULL);
    send(sockfd, "GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n"), 0);

    while ((n = recv(sockfd, recv_data, BUFFER_SIZE, 0)) > 0) {
        recv_data[n] = '\0';
        printf("%s", recv_data);
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    speed = DATA_SIZE / (elapsed_time * 1024);

    printf("\nInternet speed: %.2f Mbps\n", speed);

    close(sockfd);
    return 0;
}