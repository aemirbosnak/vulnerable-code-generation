//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_ADDR "1.1.1.1"
#define SERVER_PORT 53
#define REQUEST_SIZE 64
#define RESP_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char request[REQUEST_SIZE];
    char response[RESP_SIZE];
    struct timeval start, end;
    double elapsed;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_ADDR, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    // Send a request to the server
    memset(request, 0, REQUEST_SIZE);
    gettimeofday(&start, NULL);
    sendto(sockfd, request, REQUEST_SIZE, 0, (struct sockaddr *) &servaddr, sizeof(servaddr));

    // Receive the response from the server
    memset(response, 0, RESP_SIZE);
    recvfrom(sockfd, response, RESP_SIZE, 0, NULL, NULL);
    gettimeofday(&end, NULL);

    // Calculate the elapsed time
    elapsed = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

    // Print the results
    printf("Elapsed time: %f ms\n", elapsed);

    // Close the socket
    close(sockfd);

    return 0;
}