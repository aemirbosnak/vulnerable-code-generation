//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define SERVER_PORT 80
#define SERVER_NAME "speedtest.net"
#define BUFFER_SIZE 4096
#define TIME_OUT 10

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;
    char *ip_addr = "8.8.8.8";
    char *hostname = SERVER_NAME;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    double start_time, end_time;
    double elapsed_time;
    double speed;

    if (argc!= 2)
    {
        printf("Usage:./speedtest <server_ip>\n");
        exit(1);
    }

    ip_addr = argv[1];

    if (inet_pton(AF_INET, ip_addr, &server_addr.sin_addr) <= 0)
    {
        printf("Invalid IP address\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
    {
        printf("Socket creation failed\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Connection failed\n");
        exit(1);
    }

    start_time = time(NULL);
    send(sockfd, "GET / HTTP/1.1\r\nHost: " SERVER_NAME "\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: " SERVER_NAME "\r\nConnection: close\r\n\r\n"), 0);

    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0)
    {
        fwrite(buffer, 1, bytes_received, stdout);
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    speed = (double)bytes_received / elapsed_time;

    printf("\n");
    printf("Speed: %lf bytes/second\n", speed);

    close(sockfd);

    return 0;
}