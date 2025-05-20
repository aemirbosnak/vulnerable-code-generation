//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define PORT 8080

// Function to recursively perform QoS monitoring
int monitorQoS(int sockfd, struct sockaddr_in *servaddr, socklen_t servaddrlen) {
    int n, i;
    char buffer[1024];
    struct timeval start, end;
    double elapsed_time;

    // Send a request to the server
    sendto(sockfd, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n"), 0, (const struct sockaddr *)servaddr, servaddrlen);
    
    // Start timer
    gettimeofday(&start, NULL);

    // Receive response from server
    n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)servaddr, &servaddrlen);

    // Stop timer
    gettimeofday(&end, NULL);

    // Calculate elapsed time
    elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

    printf("Received %d bytes of data in %.3f ms\n", n, elapsed_time);

    // Recursively call the function to continue monitoring QoS
    monitorQoS(sockfd, servaddr, servaddrlen);
    
    return 0;
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Start monitoring QoS
    monitorQoS(sockfd, &servaddr, sizeof(servaddr));
    
    return 0;
}