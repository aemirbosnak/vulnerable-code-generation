//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: dynamic
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define PORT 80
#define HOST "www.example.com"

int main(int argc, char *argv[]) {
    struct sockaddr_in server_address;
    struct hostent *server;
    int sockfd;
    int opt = 1;
    char buffer[1024];
    time_t start_time, end_time;
    int num_retries = 3;

    if (argc!= 2) {
        printf("Usage: %s URL\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect");
        exit(1);
    }

    start_time = time(NULL);
    for (int i = 0; i < num_retries; i++) {
        if (send(sockfd, "GET / HTTP/1.1\r\n\r\n", strlen("GET / HTTP/1.1\r\n\r\n"), 0) < 0) {
            perror("send");
            exit(1);
        }

        if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
            perror("recv");
            exit(1);
        }

        end_time = time(NULL);
        if (i == num_retries - 1) {
            printf("Uptime: %ld seconds\n", (end_time - start_time));
            exit(0);
        } else {
            printf("Retry %d: %s\n", i + 1, buffer);
        }
    }

    close(sockfd);
    return 0;
}