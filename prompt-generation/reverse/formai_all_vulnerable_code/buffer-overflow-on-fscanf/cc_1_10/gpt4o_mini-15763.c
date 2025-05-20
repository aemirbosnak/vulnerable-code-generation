//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define LOG_FILE "/var/log/intrusion_detection.log"
#define BUF_SIZE 256
#define MAX_RULES 10
#define MAX_IP_SIZE 16

typedef struct {
    char ip_address[MAX_IP_SIZE];
    char timestamp[20];
    char message[BUF_SIZE];
} log_entry;

typedef struct {
    char rule_ip[MAX_IP_SIZE];
    char rule_message[BUF_SIZE];
} detection_rule;

detection_rule rules[MAX_RULES];
int rule_count = 0;

void load_rules(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open rule file");
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(file, "%15s %255[^\n]", rules[rule_count].rule_ip, rules[rule_count].rule_message) == 2) {
        rule_count++;
        if (rule_count >= MAX_RULES) {
            break;
        }
    }
    
    fclose(file);
}

void log_event(const char *ip_address, const char *message) {
    FILE *log = fopen(LOG_FILE, "a");
    if (log == NULL) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(log, "[%4d-%02d-%02d %02d:%02d:%02d] IP: %s - %s\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec, ip_address, message);
    
    fclose(log);
}

void check_rules(const log_entry *entry) {
    for (int i = 0; i < rule_count; i++) {
        if (strcmp(entry->ip_address, rules[i].rule_ip) == 0) {
            log_event(entry->ip_address, rules[i].rule_message);
            printf("Intrusion detected from IP: %s - %s\n", entry->ip_address, rules[i].rule_message);
        }
    }
}

void simulate_log_entry() {
    // Simulating log entry with random values for demonstration.
    log_entry new_entry;
    snprintf(new_entry.ip_address, MAX_IP_SIZE, "192.168.1.%d", rand() % 256);
    snprintf(new_entry.message, BUF_SIZE, "Failed login attempt.");

    check_rules(&new_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <rules_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_rules(argv[1]);

    // Simulate log entry every 3 seconds for demonstration purposes
    srand(time(NULL));
    while (1) {
        simulate_log_entry();
        sleep(3);
    }

    return EXIT_SUCCESS;
}