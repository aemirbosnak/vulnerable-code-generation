//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

// Configuration variables
#define MAX_LOG_LEVEL 4
#define MAX_LOG_FILE_NAME 100
#define ANALYSIS_INTERVAL 60 // seconds

// Structure to hold log message information
typedef struct {
    int level;
    char *message;
} log_message_t;

// Array to hold log messages
log_message_t logs[100];

// Function to read log file and add messages to the array
void read_log_file(char *log_file_name) {
    FILE *log_file = fopen(log_file_name, "r");
    char line[1024];

    while (fgets(line, 1024, log_file) != NULL) {
        // Ignore empty lines and lines starting with "#"
        if (strlen(line) > 0 && line[0] != '#') {
            int log_level = atoi(line);
            char *message = strtok(line, ":");
            logs[log_level].message = message;
            logs[log_level].level = log_level;
        }
    }

    fclose(log_file);
}

// Function to perform analysis and display results
void analyze_logs(char *log_file_name) {
    int i, j;
    int count[MAX_LOG_LEVEL];
    char *level_names[MAX_LOG_LEVEL] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    // Initialize counts
    for (i = 0; i < MAX_LOG_LEVEL; i++) {
        count[i] = 0;
    }

    // Add log messages to the array
    read_log_file(log_file_name);

    // Calculate the number of log messages at each level
    for (i = 0; i < MAX_LOG_LEVEL; i++) {
        count[i] = 0;
        for (j = 0; j < 100; j++) {
            if (logs[j].level == i) {
                count[i]++;
            }
        }
    }

    // Display the results
    for (i = 0; i < MAX_LOG_LEVEL; i++) {
        printf("%s: %d\n", level_names[i], count[i]);
    }

    // Display the top 10 log messages for each level
    for (i = 0; i < MAX_LOG_LEVEL; i++) {
        int j = 0;
        while (j < 10 && logs[j].level == i) {
            printf("%s\n", logs[j].message);
            j++;
        }
    }
}

int main(int argc, char *argv[]) {
    // Check if the program was given a log file name
    if (argc < 2) {
        printf("Usage: %s <log_file_name>\n", argv[0]);
        return 1;
    }

    // Set the log file name
    char *log_file_name = argv[1];

    // Set the analysis interval
    clock_t start_time = clock();
    clock_t end_time = start_time + ANALYSIS_INTERVAL * CLOCKS_PER_SEC;

    while (clock() < end_time) {
        // Perform analysis and display results
        analyze_logs(log_file_name);

        // Sleep for the analysis interval
        sleep(ANALYSIS_INTERVAL);
    }

    return 0;
}