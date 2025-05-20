//Falcon-180B DATASET v1.0 Category: System event logger ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 100
#define MAX_LOG_ENTRY_SIZE 512

typedef struct {
    char message[MAX_LOG_ENTRY_SIZE];
    time_t timestamp;
} log_entry_t;

log_entry_t log_entries[MAX_LOG_ENTRIES];
int num_log_entries = 0;

void log_message(char* message) {
    if (num_log_entries >= MAX_LOG_ENTRIES) {
        printf("Error: log is full\n");
        return;
    }

    time_t now = time(NULL);
    strncpy(log_entries[num_log_entries].message, message, MAX_LOG_ENTRY_SIZE);
    log_entries[num_log_entries].timestamp = now;
    num_log_entries++;
}

void print_log() {
    if (num_log_entries == 0) {
        printf("No log entries\n");
        return;
    }

    printf("Log:\n");
    for (int i = 0; i < num_log_entries; i++) {
        printf("%s (%ld)\n", log_entries[i].message, log_entries[i].timestamp);
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Log message\n2. Print log\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char message[MAX_LOG_ENTRY_SIZE];
                printf("Enter message: ");
                scanf("%s", message);
                log_message(message);
                break;
            }
            case 2: {
                print_log();
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }

    return 0;
}