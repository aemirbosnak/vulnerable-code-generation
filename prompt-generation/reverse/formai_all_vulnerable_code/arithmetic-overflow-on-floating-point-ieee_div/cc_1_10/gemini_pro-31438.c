//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 102400

int main() {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[BUFSIZE];
    struct timeval start, end;

    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5000);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Send a test message to the server
    gettimeofday(&start, NULL);
    n = sendto(sockfd, buf, BUFSIZE, 0, (struct sockaddr *) &servaddr, sizeof(servaddr));
    if (n == -1) {
        perror("sendto");
        exit(1);
    }

    // Receive the response from the server
    n = recvfrom(sockfd, buf, BUFSIZE, 0, NULL, NULL);
    if (n == -1) {
        perror("recvfrom");
        exit(1);
    }
    gettimeofday(&end, NULL);

    // Calculate the time taken for the round trip
    double elapsed = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    // Calculate the bandwidth
    double bandwidth = (double) BUFSIZE * 8.0 / elapsed;

    // Print the results
    printf("Round trip time: %lf microseconds\n", elapsed);
    printf("Bandwidth: %lf Mbps\n", bandwidth);

    // Close the socket
    close(sockfd);

    return 0;
}