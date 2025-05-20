//FormAI DATASET v1.0 Category: Log analysis ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_FILES 1000 // Maximum number of log files allowed
#define MAX_LOG_SIZE 1000 // Maximum size of each log file

int main() {
    // Prompt user for log file inputs
    printf("Enter the number of log files to analyze (max %d): ", MAX_LOG_FILES);
    int num_files;
    scanf("%d", &num_files);

    if (num_files > MAX_LOG_FILES) {
        printf("Error: Maximum number of log files exceeded. Please try again.\n");
        return 1;
    }

    char log_filenames[MAX_LOG_FILES][100]; // Array to store log file names

    for (int i = 0; i < num_files; i++) {
        printf("Enter the name of log file %d: ", i+1);
        scanf("%s", log_filenames[i]);
    }

    // Analyze log files
    for (int i = 0; i < num_files; i++) {
        FILE *log_file = fopen(log_filenames[i], "r"); // Open log file in read mode

        if (log_file == NULL) {
            printf("Error: Could not open log file %s. Skipping to next file.\n", log_filenames[i]);
            continue;
        }

        char log_data[MAX_LOG_SIZE]; // Array to store log data
        int line_num = 1; // Initialize line number count

        while(fgets(log_data, MAX_LOG_SIZE, log_file) != NULL) {
            char *token = strtok(log_data, " []"); // Get first word/token in log line

            if (strcmp(token, "ERROR") == 0) { // If first word is "ERROR", print line number and log line
                printf("[%s] [Line %d]: %s", log_filenames[i], line_num, log_data); // Format: [filename] [Line number]: [Log line]
            }

            line_num++;
        }

        fclose(log_file); // Close log file
    }

    printf("Log analysis complete!\n");

    return 0;
}