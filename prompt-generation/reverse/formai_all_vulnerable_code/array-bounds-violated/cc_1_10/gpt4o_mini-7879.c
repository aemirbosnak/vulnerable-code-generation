//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 8080

// Struct to hold information about detected intrusions
typedef struct {
    char src_ip[INET_ADDRSTRLEN];
    int port;
    char time[25];
} Intrusion;

Intrusion detected_intruions[100]; // Array to store detected intrusions
int intrusion_count = 0;

// Function to log intrusion details
void log_intrusion(const char *src_ip, int port) {
    if (intrusion_count < 100) {
        strcpy(detected_intruions[intrusion_count].src_ip, src_ip);
        detected_intruions[intrusion_count].port = port;
        time_t now = time(NULL);
        strftime(detected_intruions[intrusion_count].time, sizeof(detected_intruions[intrusion_count].time), "%Y-%m-%d %H:%M:%S", localtime(&now));
        intrusion_count++;
    }
}

// Function to check port activity for potential intrusions
void check_port_activity(int sockfd) {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);

    while (1) {
        ssize_t bytes_received = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &addr_len);
        if (bytes_received < 0) {
            perror("recvfrom");
            continue;
        }

        buffer[bytes_received] = '\0'; // Null-terminate the received data
        char src_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, src_ip, sizeof(src_ip));

        // Simulating intrusion detection logic based on certain criteria
        if (bytes_received > 500) { // Example criterion: large packet size
            log_intrusion(src_ip, ntohs(client_addr.sin_port));
            printf("Suspicious activity detected from %s:%d\n", src_ip, ntohs(client_addr.sin_port));
        }
    }
}

// Function to display logged intrusions
void display_log() {
    printf("\nDetected Intrusions:\n");
    printf("--------------------------------------------------------\n");
    printf("%-15s %-6s %s\n", "Source IP", "Port", "Time");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < intrusion_count; i++) {
        printf("%-15s %-6d %s\n", detected_intruions[i].src_ip, detected_intruions[i].port, detected_intruions[i].time);
    }
    printf("--------------------------------------------------------\n");
}

// Main function to create socket and initiate monitoring
int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Bind to any available interface
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming packets on port %d...\n", PORT);
    
    // Start monitoring for intrusions
    check_port_activity(sockfd);

    // This point will never be reached unless modified since check_port_activity runs indefinitely
    close(sockfd);
    return 0;
}