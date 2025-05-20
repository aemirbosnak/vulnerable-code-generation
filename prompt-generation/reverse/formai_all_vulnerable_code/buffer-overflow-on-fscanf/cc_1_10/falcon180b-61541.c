//Falcon-180B DATASET v1.0 Category: System event logger ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_SIZE 100
#define LOG_FILE "event_log.txt"

typedef struct {
    char* message;
    time_t timestamp;
} log_entry;

FILE* log_file;
int log_count = 0;

void init_log() {
    log_file = fopen(LOG_FILE, "w");
    if (log_file == NULL) {
        printf("Error: Failed to open log file.\n");
        exit(1);
    }
}

void log_event(const char* message) {
    if (log_count >= MAX_LOG_SIZE) {
        printf("Warning: Log is full. Oldest entry will be overwritten.\n");
        rewind(log_file);
        ftruncate(fileno(log_file), 0);
        log_count = 0;
    }

    time_t now = time(NULL);
    struct tm* tm_now = localtime(&now);
    char timestamp_str[32];
    strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", tm_now);

    log_entry entry = {message, now};
    fprintf(log_file, "%s - %s\n", timestamp_str, message);
    log_count++;
}

void print_log() {
    if (log_file == NULL) {
        printf("Error: Log file not initialized.\n");
        return;
    }

    rewind(log_file);
    while (!feof(log_file)) {
        log_entry entry;
        fscanf(log_file, "%s - %s\n", entry.message, entry.timestamp);
        printf("%s - %s\n", ctime(&entry.timestamp), entry.message);
    }
}

int main() {
    init_log();

    log_event("Program started.");

    int choice;
    while (1) {
        printf("\n");
        printf("1. Log an event\n");
        printf("2. Print log\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char message[256];
                printf("Enter your message: ");
                scanf("%s", message);
                log_event(message);
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
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}