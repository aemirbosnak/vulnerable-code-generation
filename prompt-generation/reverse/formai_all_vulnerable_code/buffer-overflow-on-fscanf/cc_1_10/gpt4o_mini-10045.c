//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_RULES 100
#define IP_SIZE 16
#define LOG_FILE "firewall.log"

typedef struct {
    char src_ip[IP_SIZE];
    int src_port;
    int action; // 1: allow, 0: deny
} FirewallRule;

FirewallRule rules[MAX_RULES];
int rule_count = 0;

void load_rules(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open rules file");
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(file, "%15s %d %d", rules[rule_count].src_ip, &rules[rule_count].src_port, &rules[rule_count].action) == 3) {
        rule_count++;
        if (rule_count >= MAX_RULES) {
            break;
        }
    }
    
    fclose(file);
}

void log_action(const char *action, const char *src_ip, int src_port) {
    FILE *logfile = fopen(LOG_FILE, "a");
    if (logfile == NULL) {
        perror("Could not open log file");
        return;
    }
    
    fprintf(logfile, "Action: %s | Source IP: %s | Source Port: %d\n", action, src_ip, src_port);
    fclose(logfile);
}

int apply_rules(const char *src_ip, int src_port) {
    for (int i = 0; i < rule_count; i++) {
        if (strcmp(rules[i].src_ip, src_ip) == 0 && rules[i].src_port == src_port) {
            return rules[i].action; // Return action: 1 or 0
        }
    }
    return 1; // Default action is allow
}

void simulate_packet(const char *src_ip, int src_port) {
    int action = apply_rules(src_ip, src_port);
    
    if (action) {
        printf("Packet allowed: %s:%d\n", src_ip, src_port);
        log_action("Allowed", src_ip, src_port);
    } else {
        printf("Packet denied: %s:%d\n", src_ip, src_port);
        log_action("Denied", src_ip, src_port);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <rules_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_rules(argv[1]);

    // Simulate incoming packets
    simulate_packet("192.168.1.10", 80);
    simulate_packet("192.168.1.20", 443);
    simulate_packet("192.168.1.30", 22);
    simulate_packet("192.168.1.10", 22); // An allowed packet
    simulate_packet("192.168.1.99", 8080); // Default allowed

    return EXIT_SUCCESS;
}