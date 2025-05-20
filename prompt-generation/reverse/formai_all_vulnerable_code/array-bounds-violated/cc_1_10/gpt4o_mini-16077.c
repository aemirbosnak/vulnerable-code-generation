//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>

#define MAX_LOG_LENGTH 1024
#define MAX_DETECTED_IPS 100
#define PORT 8080

typedef struct {
    char ip[INET_ADDRSTRLEN];
    int count;
    time_t first_detected;
} IntrusionRecord;

IntrusionRecord logs[MAX_DETECTED_IPS];
int log_count = 0;

void log_ip(char *ip) {
    int i;
    for(i = 0; i < log_count; i++) {
        if(strcmp(logs[i].ip, ip) == 0) {  // IP already logged
            logs[i].count++;
            return;
        }
    }
    // New IP detected
    strcpy(logs[log_count].ip, ip);
    logs[log_count].count = 1;
    logs[log_count].first_detected = time(NULL);
    log_count++;
}

void display_logs() {
    printf("=== Detected Intrusions ===\n");
    for(int i = 0; i < log_count; i++) {
        printf("IP: %s | Count: %d | First Detected: %s", 
               logs[i].ip, logs[i].count, ctime(&logs[i].first_detected));
    }
}

void analyze_packet(const char *buffer, size_t size) {
    // This function will analyze the packet content
    // For demonstration purposes, let's say we detect an intrusion based on
    // the presence of "Attack" in the packet
    if (strstr(buffer, "Attack") != NULL) {
        char src_ip[INET_ADDRSTRLEN] = "192.168.1.1";  // Replace with actual source IP extraction logic
        log_ip(src_ip);
    }
}

void run_detection_system() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    socklen_t addr_len = sizeof(client_addr);

    // Create UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind Failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Start receiving packets
    while(1) {
        ssize_t n = recvfrom(sockfd, (char *)buffer, sizeof(buffer), MSG_WAITALL,
                             (struct sockaddr *) &client_addr, &addr_len);
        buffer[n] = '\0';
        analyze_packet(buffer, n);
        display_logs();  // Display logs after processing each packet
    }

    close(sockfd);
}

int main() {
    printf("Starting Intrusion Detection System...\n");
    run_detection_system();
    return 0;
}