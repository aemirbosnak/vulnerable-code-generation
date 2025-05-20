//FormAI DATASET v1.0 Category: Log analysis ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10000   // Maximum number of lines to read from the log file
#define MAX_LOG_LEN 5000  // Maximum length of each line in the log file

int main(int argc, char **argv) {
    char log_file_name[256];
    char log_lines[MAX_LINES][MAX_LOG_LEN];
    int lines_count = 0;
    int i, j, k;

    // Check if log file name is provided as command line argument
    if (argc < 2) {
        printf("Please provide log file name as command line argument.\n");
        return 0;
    }

    // Copy log file name from command line argument
    strcpy(log_file_name, argv[1]);

    // Open log file for reading
    FILE *log_file = fopen(log_file_name, "r");
    if (log_file == NULL) {
        printf("Failed to open log file %s.\n", log_file_name);
        return 0;
    }

    // Read all the log lines into memory
    while (fgets(log_lines[lines_count], MAX_LOG_LEN, log_file) != NULL) {
        lines_count++;
        if (lines_count >= MAX_LINES) {
            // We have reached the maximum number of lines to read from the log file
            break;
        }
    }
    fclose(log_file);

    // Loop through all the log lines and look for patterns
    for (i = 0; i < lines_count; i++) {
        char *current_line = log_lines[i];

        if (strstr(current_line, "Error") != NULL || strstr(current_line, "error") != NULL) {
            // This line has an error log level
            printf("Line %d: %s", i+1, current_line);
        }

        // Check if this line has a timestamp
        if (strlen(current_line) > 19 && current_line[4] == '-' && current_line[7] == '-' && current_line[10] == 'T') {
            // This line has a timestamp
            char timestamp_str[20];
            strncpy(timestamp_str, current_line, 19);
            timestamp_str[19] = '\0';

            // Print all the lines that have the same timestamp
            for (j = i+1; j < lines_count; j++) {
                char *next_line = log_lines[j];
                if (strlen(next_line) > 19 && strncmp(next_line, timestamp_str, 19) == 0) {
                    printf("Line %d: %s", j+1, next_line);
                }
            }
        }

        // Check if this line has a stack trace
        if (strstr(current_line, "stack trace:") != NULL) {
            // This line has a stack trace
            printf("Line %d: %s", i+1, current_line);

            // Print the next 5 lines after the stack trace line
            for (j = i+1, k = 0; j < lines_count && k < 5; j++, k++) {
                printf("Line %d: %s", j+1, log_lines[j]);
            }
        }
    }

    return 0;
}