//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ERROR_COUNT 100

// Structure to store log data
typedef struct {
    int error_count;
    int warning_count;
    int info_count;
    char *error_messages[MAX_ERROR_COUNT];
} log_data_t;

// Function to parse log file and fill log data structure
void parse_log(const char *log_file, log_data_t *log_data) {
    FILE *file = fopen(log_file, "r");
    if (!file) {
        fprintf(stderr, "Error: Unable to open log file %s\n", log_file);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // Check if line is empty or contains only whitespace
        if (strchr(line, '\0') == NULL || strchr(line, '\n') == NULL) {
            continue;
        }

        // Extract log level and message
        char *log_level = strtok(line, ":");
        char *message = strtok(NULL, "\n");

        // Determine log level
        if (strcmp(log_level, "E") == 0) {
            // Error message
            log_data->error_count++;
            log_data->error_messages[log_data->error_count - 1] = message;
        } else if (strcmp(log_level, "W") == 0) {
            // Warning message
            log_data->warning_count++;
        } else {
            // Info message
            log_data->info_count++;
        }
    }

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s log_file\n", argv[0]);
        return 1;
    }

    log_data_t log_data;
    parse_log(argv[1], &log_data);

    // Print log data
    printf("Log Data:\n");
    printf("  Error Count: %d\n", log_data.error_count);
    printf("  Warning Count: %d\n", log_data.warning_count);
    printf("  Info Count: %d\n", log_data.info_count);

    // Print error messages
    for (int i = 0; i < log_data.error_count; i++) {
        printf("  Error Message %d: %s\n", i + 1, log_data.error_messages[i]);
    }

    return 0;
}