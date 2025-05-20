//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define TEST_SIZE 1048576

double measure_speed(char *hostname) {
    int sock;
    struct sockaddr_in server_address;
    char message[BUFFER_SIZE], buffer[BUFFER_SIZE];
    int i, read_size, total_bytes = 0;
    double start_time, end_time, speed;
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }
    printf("Socket created\n");
    
    server_address.sin_addr.s_addr = inet_addr(hostname);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    
    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect failed. Error");
        return -1;
    }
    
    printf("Connected successfully to %s on port %d\n", hostname, 80);
    
    sprintf(message, "GET /%dMB.bin HTTP/1.1\r\nHost: %s\r\n\r\n", TEST_SIZE / (1024 * 1024), hostname);
    // Send HTTP request
    if (send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return -1;
    }
    printf("HTTP request sent\n");
    // Start timer
    start_time = (double)clock() / CLOCKS_PER_SEC;
    
    // Receive response from server
    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        total_bytes += read_size;
    }
    
    // End timer
    end_time = (double)clock() / CLOCKS_PER_SEC;
    
    close(sock);
    printf("Connection closed\n");
    
    // Calculate speed
    speed = (double)total_bytes / (double)(end_time - start_time);
    
    return speed;
}

int main(int argc, char *argv[]) {
    char *hostname;
    double speed;
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [hostname]\n", argv[0]);
        return -1;
    }
    
    hostname = argv[1];
    
    speed = measure_speed(hostname);
    
    if (speed == -1) {
        fprintf(stderr, "Could not measure internet speed\n");
        return -1;
    }
    
    printf("Internet speed: %.2f bytes/second\n", speed);
    
    return 0;
}