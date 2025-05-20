//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_LOG_SIZE 1024
#define BUFFER_SIZE 2048
#define PORT 8888
#define CONFIG_FILE "config.txt"

typedef struct {
    char ip_address[16];
    int port;
    char alert_message[MAX_LOG_SIZE];
} Config;

Config load_config(const char* filename) {
    Config config;
    FILE *file = fopen(filename, "r");
    if (file) {
        fscanf(file, "ip_address=%15s\n", config.ip_address);
        fscanf(file, "port=%d\n", &config.port);
        fgetc(file); // to consume newline
        fgets(config.alert_message, MAX_LOG_SIZE, file);
        fclose(file);
    } else {
        perror("Failed to open config file");
        exit(EXIT_FAILURE);
    }
    return config;
}

void log_event(const char* message) {
    FILE *log_file = fopen("intrusion_log.txt", "a");
    if (log_file) {
        fprintf(log_file, "%s\n", message);
        fclose(log_file);
    } else {
        perror("Failed to open log file");
    }
}

void monitor_network_traffic(Config config) {
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(config.port);

    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind Failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Monitoring network traffic on port %d...\n", config.port);

    while (1) {
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, MSG_WAITALL,
                         (struct sockaddr *) &client_addr, &addr_len);
        buffer[n] = '\0';

        // Simple intrusion detection logic
        if (strstr(buffer, "intrusion") != NULL) {
            char log_msg[MAX_LOG_SIZE];
            snprintf(log_msg, sizeof(log_msg), "Intrusion detected: %s", buffer);
            log_event(log_msg);
            printf("%s\n", config.alert_message);
        }
    }
    
    close(sockfd);
}

int main() {
    Config config = load_config(CONFIG_FILE);
    monitor_network_traffic(config);
    return 0;
}