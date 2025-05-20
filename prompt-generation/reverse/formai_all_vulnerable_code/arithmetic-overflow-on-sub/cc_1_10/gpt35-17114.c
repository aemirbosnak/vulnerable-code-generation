//FormAI DATASET v1.0 Category: Network Ping Test ; Style: introspective
// This C program tests network connectivity using PING command, and demonstrates basic socket programming in Linux environment
// Author: An AI chatbot programmed to generate code
// Date: August 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <time.h>

#define BUFFER_SIZE 1024  // Define buffer size for receiving data

int sock_fd;  // Define global socket file descriptor
struct sockaddr_in server;  // Define server address information

// Function to handle CTRL+C signal
void handle_signal(int signal) {
    close(sock_fd);  // Close socket
    printf("\nPing Test halted by user\n");
    exit(0);  // Exit program
}

// Function to send ping request to server
void send_ping_request() {
    
    // Define variables
    struct timeval start_time, end_time;  // Start and end time of ping request
    double rtt_milliseconds;  // Round-trip time in milliseconds
    char buffer[BUFFER_SIZE] = "Ping Request";  // Ping request message
    int bytes_sent, bytes_received; // Bytes sent and received
    socklen_t server_size;  // Size of server address struct
    
    // Record start time
    gettimeofday(&start_time, NULL);
    
    // Send ping request message to server
    bytes_sent = sendto(sock_fd, buffer, strlen(buffer), 0, (struct sockaddr *)&server, sizeof(server));
    if (bytes_sent < 0) {
        perror("ERROR sending message");  // Error checking
        exit(1);
    }
    
    // Receive response from server
    char response[BUFFER_SIZE];
    memset(response, '\0', BUFFER_SIZE);
    server_size = sizeof(server);
    bytes_received = recvfrom(sock_fd, response, BUFFER_SIZE, 0, (struct sockaddr *)&server, &server_size);
    if (bytes_received < 0) {
        perror("ERROR receiving message");  // Error checking
        exit(1);
    }
    
    // Record end time
    gettimeofday(&end_time, NULL);
    
    // Calculate round-trip time in milliseconds
    rtt_milliseconds = (double) (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (double) (end_time.tv_usec - start_time.tv_usec) / 1000.0;
    
    // Print ping request response
    printf("Received %d bytes from %s: icmp_seq=1 ttl=64 time=%.2f ms\n", bytes_received, inet_ntoa(server.sin_addr), rtt_milliseconds);
}

int main(int argc, char *argv[]) {
    
    if (argc != 2) {  // Error checking
        fprintf(stderr, "Syntax: %s <IP address>\n", argv[0]);
        exit(1);
    }
    
    // Create UDP socket
    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("ERROR opening socket");  // Error checking
        exit(1);
    }
    
    // Set server address information
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(0);  // Use any available port number
    if (inet_aton(argv[1], &server.sin_addr) == 0) {
        fprintf(stderr, "ERROR invalid address\n");  // Error checking
        exit(1);
    }
    
    // Register signal handler for CTRL+C signal
    signal(SIGINT, handle_signal);
    
    // Start infinite loop to send ping requests
    printf("PING %s: icmp_seq=1 ttl=64\n", argv[1]);  // Print initial message
    while (1) {
        send_ping_request();  // Send ping request
        sleep(1);  // Wait 1 second before next request
    }
    
    return 0;
}