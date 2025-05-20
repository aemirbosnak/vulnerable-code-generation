//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LOG_SIZE 1024
#define MAX_LINE_LENGTH 256

typedef struct {
    char *message;
    int timestamp;
} log_entry_t;

static void log_entry_print(log_entry_t *entry) {
    printf("[%d] %s\n", entry->timestamp, entry->message);
}

int main() {
    char log_file[] = "example.log";
    FILE *log_file_ptr = fopen(log_file, "r");
    if (!log_file_ptr) {
        perror("Failed to open log file");
        return 1;
    }

    // Read log file line by line
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file_ptr) != NULL) {
        // Parse log line and extract timestamp and message
        log_entry_t *entry = (log_entry_t *) malloc(sizeof(log_entry_t));
        sscanf(line, "%d %s", &entry->timestamp, entry->message);

        // Print log entry
        log_entry_print(entry);

        // Generate random noise
        int random_noise = (rand() % 100) - 50;
        entry->message[strcspn(entry->message, "\n")] = (char)('A' + random_noise);

        // Append random noise to message
        entry->message[strlen(entry->message)] = (char)('A' + random_noise);

        // Print modified log entry
        log_entry_print(entry);
    }

    fclose(log_file_ptr);

    return 0;
}