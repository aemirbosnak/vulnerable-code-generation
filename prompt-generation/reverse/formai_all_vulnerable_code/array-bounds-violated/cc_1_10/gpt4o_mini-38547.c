//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to log firewall activity
void log_activity(const char *message) {
    FILE *log_file = fopen("firewall_log.txt", "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        return;
    }
    fprintf(log_file, "%s\n", message);
    fclose(log_file);
}

// Function to block an IP address
void block_ip(const char *ip) {
    char command[150];
    snprintf(command, sizeof(command), "iptables -A INPUT -s %s -j DROP", ip);
    system(command);
    char log_msg[100];
    snprintf(log_msg, sizeof(log_msg), "Blocked IP: %s", ip);
    log_activity(log_msg);
}

// Function to check for unauthorized access attempts
void monitor_access() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // Creating socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting up server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding socket
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Firewall running, monitoring access on port %d...\n", PORT);

    while (1) {
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *)&client_addr, &addr_len);
        buffer[n] = '\0';
        
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));

        printf("Received packet from %s: %s\n", client_ip, buffer);

        // Simulate unauthorized access checking
        if (strstr(buffer, "UNAUTHORIZED_ACCESS") != NULL) {
            log_activity("Unauthorized access attempt detected!");
            block_ip(client_ip);
        }
    }
    
    close(sockfd);
}

int main() {
    monitor_access();
    return 0;
}