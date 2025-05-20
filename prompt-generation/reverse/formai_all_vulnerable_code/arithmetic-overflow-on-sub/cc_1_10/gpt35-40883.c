//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>
#include <string.h>

#define PORT 80
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./speedtest <URL>\n");
        return 1;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        fprintf(stderr, "Error: Invalid URL.\n");
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Could not create socket.\n");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    memcpy(&server.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        fprintf(stderr, "Error: Could not connect to server.\n");
        return 1;
    }

    char request[BUFFER_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        fprintf(stderr, "Error: Could not send request.\n");
        return 1;
    }

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    
    char response[BUFFER_SIZE];
    int bytes_received = 0;
    int total_bytes_received = 0;
    
    while ((bytes_received = recv(sockfd, response, BUFFER_SIZE, 0)) > 0) {
        total_bytes_received += bytes_received;
    }

    gettimeofday(&end_time, NULL);
    close(sockfd);

    printf("Download speed: %f Mbps\n", ((float) total_bytes_received / 1000000) / 
            ((float) (end_time.tv_sec - start_time.tv_sec) + 
            (float) (end_time.tv_usec - start_time.tv_usec) / 1000000));

    return 0;
}