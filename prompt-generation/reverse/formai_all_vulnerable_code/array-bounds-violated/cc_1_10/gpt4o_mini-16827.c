//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <signal.h>

#define PORT 8080
#define BUFFER_SIZE 4096
#define PROTOCOL_VERSION "NeonMetrics v1.0"

void handle_signal(int signal) {
    if (signal == SIGINT) {
        printf("\nShutting down NeonMetrics... Goodbye, cyber traveler!\n");
        exit(0);
    }
}

void process_packet(char *buffer, ssize_t size) {
    // Modifying the incoming packet (for demonstration purposes)
    if (strstr(buffer, "futuristic") != NULL) {
        strcpy(buffer, "Access Denied: You are too advanced; stay grounded!");
    } else {
        strcat(buffer, " - Registered by NeonMetrics");
    }
}

void log_event(const char *event) {
    FILE *logfile = fopen("neonmetrics.log", "a");
    if (logfile) {
        fprintf(logfile, "%s\n", event);
        fclose(logfile);
    }
}

int main(int argc, char *argv[]) {
    signal(SIGINT, handle_signal);
    
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed! Connection to the Net lost...");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed! The grids are frail...");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("[%s] Listening on port %d... Awaken and adapt!\n", PROTOCOL_VERSION, PORT);

    while (1) {
        ssize_t recv_size = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &addr_len);
        if (recv_size < 0) {
            perror("Packet reception failed! Disruption in the Matrix...");
            continue;
        }
        
        buffer[recv_size] = '\0'; // Null-terminate the received data
        printf("[RECEIVED] %s\n", buffer);
        log_event(buffer);
        
        process_packet(buffer, recv_size);
        
        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&client_addr, addr_len);
        printf("[SENT] %s\n", buffer);
    }

    close(sockfd);
    return 0;
}