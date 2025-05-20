//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFF_SIZE 1024

int main() {
    int sockfd, n;
    char buffer[BUFF_SIZE];
    struct sockaddr_in servaddr;
    struct timeval start, end;
    double elapsed_time;

    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the server address and port
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("8.8.8.8");
    servaddr.sin_port = htons(53);

    // Send a DNS query to the server
    memset(buffer, 0, BUFF_SIZE);
    strcpy(buffer, "google.com");
    if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("sendto");
        exit(1);
    }

    // Start the timer
    gettimeofday(&start, NULL);

    // Receive the response from the server
    memset(buffer, 0, BUFF_SIZE);
    n = recvfrom(sockfd, buffer, BUFF_SIZE, 0, NULL, NULL);
    if (n == -1) {
        perror("recvfrom");
        exit(1);
    }

    // Stop the timer
    gettimeofday(&end, NULL);
    elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

    // Calculate the download speed
    double download_speed = (n * 8) / elapsed_time;
    printf("Download speed: %.2f Kbps\n", download_speed);

    // Close the socket
    close(sockfd);
    return 0;
}