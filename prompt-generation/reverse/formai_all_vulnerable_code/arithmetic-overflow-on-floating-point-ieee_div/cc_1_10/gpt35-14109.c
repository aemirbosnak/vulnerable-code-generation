//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 50000

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *server_ip;
    time_t start_time, end_time;
    double total_time;
    int sent_bytes, rcvd_bytes;
    
    if (argc < 2) {
        printf("Usage: %s <server-ip>\n", argv[0]);
        return 1;
    }
    
    server_ip = argv[1];
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() error");
        return 1;
    }
    
    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(PORT);
    
    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() error");
        return 1;
    }
    
    // Send data to server
    start_time = time(NULL);
    sent_bytes = send(sockfd, "hello", 5, 0);
    if (sent_bytes < 0) {
        perror("send() error");
        return 1;
    }
    
    // Receive data from server
    char buffer[1024];
    rcvd_bytes = recv(sockfd, buffer, 1024, 0);
    if (rcvd_bytes < 0) {
        perror("recv() error");
        return 1;
    }
    
    // Calculate time taken for round-trip
    end_time = time(NULL);
    total_time = difftime(end_time, start_time);
    
    // Calculate speed in Mbps
    double speed = ((double)sent_bytes + (double)rcvd_bytes) * 8 / 1000000 / total_time;
    
    printf("Round-trip time: %.2f seconds\n", total_time);
    printf("Speed: %.2f Mbps\n", speed);
    
    // Close socket
    close(sockfd);
    
    return 0;
}