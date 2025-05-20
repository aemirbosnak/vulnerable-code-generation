//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: secure
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/uio.h>
#include <sys/time.h>

#define PORT "80"
#define HOST "www.google.com"
#define REQUEST "GET / HTTP/1.0\r\n\r\n"

#define BUF_SIZE 1024

int main(void)
{
    struct addrinfo hints, *res;
    int sockfd;
    char buffer[BUF_SIZE];
    struct timeval start, end;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo(HOST, PORT, &hints, &res);

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    gettimeofday(&start, NULL);
    connect(sockfd, res->ai_addr, res->ai_addrlen);
    gettimeofday(&end, NULL);

    double time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;

    printf("Time taken to establish connection: %f sec.\n", time_taken);

    send(sockfd, REQUEST, strlen(REQUEST), 0);

    gettimeofday(&start, NULL);

    while (recv(sockfd, buffer, BUF_SIZE, 0) > 0)
    {
    }

    gettimeofday(&end, NULL);

    time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;

    printf("Time taken to download data: %f sec.\n", time_taken);

    close(sockfd);

    return 0;
}