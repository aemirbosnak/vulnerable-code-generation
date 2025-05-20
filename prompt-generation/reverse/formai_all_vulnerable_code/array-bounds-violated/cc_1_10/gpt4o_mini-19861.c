//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <time.h>

#define BUFFER_SIZE 2048
#define INET_PORT 8080
#define LOG_FILE "ids_log.txt"

typedef struct {
    char timestamp[30];
    char source_ip[INET_ADDRSTRLEN];
    char destination_ip[INET_ADDRSTRLEN];
    int source_port;
    int destination_port;
    char alert[512];
} LogEntry;

void log_alert(const LogEntry *entry) {
    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        perror("Unable to open log file");
        return;
    }
    fprintf(fp, "%s | From: %s:%d To: %s:%d | Alert: %s\n", entry->timestamp, 
            entry->source_ip, entry->source_port, 
            entry->destination_ip, entry->destination_port, 
            entry->alert);
    fclose(fp);
}

void create_entry(LogEntry *entry, const char *source_ip, int source_port, 
                  const char *destination_ip, int destination_port, 
                  const char *alert) {
    time_t now = time(NULL);
    strftime(entry->timestamp, sizeof(entry->timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));
    strncpy(entry->source_ip, source_ip, sizeof(entry->source_ip) - 1);
    strncpy(entry->destination_ip, destination_ip, sizeof(entry->destination_ip) - 1);
    entry->source_port = source_port;
    entry->destination_port = destination_port;
    strncpy(entry->alert, alert, sizeof(entry->alert) - 1);
}

int check_for_intrusion(const char *data) {
    // Simple heuristic: alert for incoming packets with 'malicious' keyword
    if (strstr(data, "malicious") != NULL) {
        return 1;
    }
    return 0;
}

void signal_handler(int signal) {
    if (signal == SIGINT) {
        printf("\nShutting down IDS gracefully...\n");
        exit(0);
    }
}

void start_ids() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    LogEntry entry;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(INET_PORT);

    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("IDS listening on port %d...\n", INET_PORT);
    
    while (1) {
        ssize_t n = recvfrom(sockfd, buffer, BUFFER_SIZE, MSG_WAITALL,
                             (struct sockaddr *) &client_addr, &addr_len);
        buffer[n] = '\0';
        
        char source_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, source_ip, sizeof(source_ip));

        int source_port = ntohs(client_addr.sin_port);
        
        if (check_for_intrusion(buffer)) {
            create_entry(&entry, source_ip, source_port, "localhost", INET_PORT, "Possible intrusion detected");
            log_alert(&entry);
            printf("Intrusion detected from %s:%d\n", source_ip, source_port);
        }
    }

    close(sockfd);
}

int main() {
    signal(SIGINT, signal_handler);
    start_ids();
    return 0;
}