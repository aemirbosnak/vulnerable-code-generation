//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/time.h>

#define PORT 80
#define BUFFER_SIZE 1024

// Structure to hold packet information
typedef struct {
    struct timeval arrival_time;
    struct timeval send_time;
    double latency;
} packet_info;

// Function to get the current time in milliseconds
double get_current_time_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0);
}

// Function to calculate and print latency
void print_latency(packet_info *packet) {
    packet->latency = (packet->arrival_time.tv_sec - packet->send_time.tv_sec) * 1000.0;
    packet->latency += (packet->arrival_time.tv_usec - packet->send_time.tv_usec) / 1000.0;
    printf("Response Latency: %.2f ms\n", packet->latency);
}

// Function to create and send a simple TCP request
void send_tcp_request(const char *ip_address, packet_info *packet) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    
    // Record send time
    gettimeofday(&packet->send_time, NULL);
    
    // Connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Send HTTP GET request
    char *request = "GET / HTTP/1.1\r\nHost: ";
    strcat(request, ip_address);
    strcat(request, "\r\nConnection: close\r\n\r\n");

    send(sock, request, strlen(request), 0);
    
    // Receive response
    recv(sock, buffer, BUFFER_SIZE - 1, 0);
    close(sock);

    // Record arrival time
    gettimeofday(&packet->arrival_time, NULL);
    print_latency(packet);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    packet_info packet;
    send_tcp_request(argv[1], &packet);

    return 0;
}