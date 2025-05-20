//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_ADDRESS "speedtest.net"
#define SERVER_PORT 8080

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_data[BUFFER_SIZE];
    char recv_data[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
    serv_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    time_t start_time, end_time;
    double elapsed_time;

    start_time = time(NULL);

    while (1) {
        send(sockfd, "GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n"), 0);

        n = recv(sockfd, recv_data, BUFFER_SIZE, 0);
        if (n <= 0) {
            break;
        }

        recv_data[n] = '\0';
        printf("%s", recv_data);
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("Elapsed time: %lf seconds\n", elapsed_time);

    close(sockfd);

    return 0;
}