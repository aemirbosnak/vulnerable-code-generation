//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define SUSPICIOUS_KEYWORD "failed"

typedef struct {
    char timestamp[20];
    char message[256];
} LogEntry;

LogEntry logs[MAX_LOG_ENTRIES];
int log_count = 0;

void load_logs(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open log file");
        exit(EXIT_FAILURE);
    }

    while (log_count < MAX_LOG_ENTRIES && fscanf(file, "%[^ ] %[^\\n]\n", logs[log_count].timestamp, logs[log_count].message) == 2) {
        log_count++;
    }

    fclose(file);
}

void analyze_logs() {
    printf("***** Intrusion Detection Analysis *****\n");
    for (int i = 0; i < log_count; i++) {
        if (strstr(logs[i].message, SUSPICIOUS_KEYWORD) != NULL) {
            printf("Suspicious activity detected:\n");
            printf("Timestamp: %s\nMessage: %s\n", logs[i].timestamp, logs[i].message);
            printf("---------------------------------\n");
        }
    }
}

void display_log_summary() {
    printf("Total log entries: %d\n", log_count);
    int suspicious_count = 0;
    for (int i = 0; i < log_count; i++) {
        if (strstr(logs[i].message, SUSPICIOUS_KEYWORD) != NULL) {
            suspicious_count++;
        }
    }
    printf("Total suspicious entries found: %d\n", suspicious_count);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_logs(argv[1]);
    analyze_logs();
    display_log_summary();

    return EXIT_SUCCESS;
}