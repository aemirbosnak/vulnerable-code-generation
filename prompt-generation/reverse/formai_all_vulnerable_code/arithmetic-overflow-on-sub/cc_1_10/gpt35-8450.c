//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFFER_SIZE 5242880 // 5 MB buffer size

int main() {
    // Creating socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Error creating socket!\n");
        return 1;
    }

    // Setting up server address
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("8.8.8.8"); // Google DNS server IP address
    serv_addr.sin_port = htons(80);

    // Connecting to server
    if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server!\n");
        return 1;
    }

    // Sending GET request
    char* request = "GET /speedtest/random5x5.jpg HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n";
    int bytes_sent = send(sockfd, request, strlen(request), 0);
    if(bytes_sent < 0) {
        printf("Error sending request!\n");
        return 1;
    }

    // Receiving response
    char buffer[BUFFER_SIZE];
    int bytes_received, total_bytes_received = 0;
    struct timeval start, end;
    gettimeofday(&start, NULL); // Start timing
    while((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        total_bytes_received += bytes_received;
    }
    gettimeofday(&end, NULL); // Stop timing

    // Calculating download speed
    double time_taken = (double)(end.tv_sec - start.tv_sec) + ((double)(end.tv_usec - start.tv_usec) / 1000000);
    double download_speed = (double)total_bytes_received / (1024 * 1024 * time_taken);

    printf("Your internet speed is: %.2f Mbps\n", download_speed);

    // Closing socket
    close(sockfd);

    return 0;
}