//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: accurate
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "192.168.1.1"

int main() {
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct timeval start, end;
    long long int start_time, end_time;
    double elapsed_time, download_speed;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    inet_aton(SERVER_IP, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    gettimeofday(&start, NULL);
    send(sockfd, "GET /largefile.bin HTTP/1.1\r\nHost: localhost\r\n\r\n", 28, 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);

    gettimeofday(&end, NULL);
    start_time = start.tv_sec * 1000 + start.tv_usec / 1000;
    end_time = end.tv_sec * 1000 + end.tv_usec / 1000;
    elapsed_time = (end_time - start_time) / 1000.0;
    download_speed = (double)n / elapsed_time;

    printf("Download speed: %.2f KB/s\n", download_speed / 1024.0);

    close(sockfd);
    return EXIT_SUCCESS;
}