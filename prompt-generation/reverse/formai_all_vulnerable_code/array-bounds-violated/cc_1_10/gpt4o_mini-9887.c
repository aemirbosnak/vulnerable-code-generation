//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024
#define LOG_FILE "intrusion_log.txt"

typedef struct {
    char rule[256];
} Rule;

Rule* rules = NULL;
int rule_count = 0;

void load_rules(const char *filename);
void log_intrusion(const char *ip_address, const char *message);
int analyze_packet(const char *packet, const char *ip_address);
void start_sniffer(int port);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <rules_file> <port>\n", argv[0]);
        return 1;
    }
    
    load_rules(argv[1]);
    start_sniffer(atoi(argv[2]));

    free(rules);
    return 0;
}

void load_rules(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open rules file");
        exit(EXIT_FAILURE);
    }
    
    rules = malloc(sizeof(Rule) * 100);
    
    while (fgets(rules[rule_count].rule, sizeof(rules[rule_count].rule), file) != NULL) {
        rules[rule_count].rule[strcspn(rules[rule_count].rule, "\n")] = '\0'; // Remove newline character
        rule_count++;
    }
    
    fclose(file);
}

void log_intrusion(const char *ip_address, const char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (!log_file) {
        perror("Could not open log file");
        return;
    }
    
    fprintf(log_file, "Intrusion detected from %s: %s\n", ip_address, message);
    fclose(log_file);
}

int analyze_packet(const char *packet, const char *ip_address) {
    for (int i = 0; i < rule_count; i++) {
        if (strstr(packet, rules[i].rule) != NULL) {
            log_intrusion(ip_address, rules[i].rule);
            return 1;
        }
    }
    return 0;
}

void start_sniffer(int port) {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    printf("Listening for packets on port %d...\n", port);
    
    char buffer[MAX_BUFFER_SIZE];
    while (1) {
        int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr, &addr_len);
        if (n < 0) {
            perror("Receive failed");
            break;
        }
        
        buffer[n] = '\0';
        char ip_address[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, ip_address, sizeof(ip_address));
        
        printf("Received packet from %s: %s\n", ip_address, buffer);
        if (analyze_packet(buffer, ip_address)) {
            printf("Intrusion detected from %s!\n", ip_address);
        }
    }
    
    close(sockfd);
}