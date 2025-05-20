//FormAI DATASET v1.0 Category: Log analysis ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the data from the logs
typedef struct {
    char timestamp[20];
    int log_level;
    char message[100];
} log_data;

int main() {
    FILE *log_file;
    char filename[20];
    char line[120];
    int num_logs = 0;

    printf("Enter the filename of the log file you want to analyze: ");
    scanf("%s", filename);

    log_file = fopen(filename, "r");

    // Check if file exists
    if (log_file == NULL) {
        printf("Error: file \"%s\" not found\n", filename);
        exit(1);
    }

    // Count the number of logs in the file
    while (fgets(line, sizeof(line), log_file)) {
        num_logs++;
    }

    // Reset the file pointer to the beginning of the file
    rewind(log_file);

    // Allocate memory for the log_data array based on the number of logs in the file
    log_data *logs = malloc(num_logs * sizeof(log_data));

    // Read the data from the log file
    int i = 0;
    while (fgets(line, sizeof(line), log_file)) {
        sscanf(line, "%s %d %s", logs[i].timestamp, &logs[i].log_level, logs[i].message);
        i++;
    }

    // Close the file
    fclose(log_file);

    // Analyze the log data
    int num_debug_logs = 0;
    int num_info_logs = 0;
    int num_warn_logs = 0;
    int num_error_logs = 0;

    for (i = 0; i < num_logs; i++) {
        switch (logs[i].log_level) {
            case 1:
                num_debug_logs++;
                break;
            case 2:
                num_info_logs++;
                break;
            case 3:
                num_warn_logs++;
                break;
            case 4:
                num_error_logs++;
                break;
            default:
                printf("Error: invalid log level\n");
        }
    }

    // Print out the results of the analysis
    printf("Log Analysis Report\n");
    printf("====================\n\n");
    printf("Total number of logs: %d\n", num_logs);
    printf("Number of debug logs: %d\n", num_debug_logs);
    printf("Number of info logs: %d\n", num_info_logs);
    printf("Number of warn logs: %d\n", num_warn_logs);
    printf("Number of error logs: %d\n\n", num_error_logs);
    printf("Log Details\n");
    printf("============\n\n");

    for (i = 0; i < num_logs; i++) {
        printf("Timestamp: %s\n", logs[i].timestamp);
        printf("Log Level: ");
        switch (logs[i].log_level) {
            case 1:
                printf("DEBUG\n");
                break;
            case 2:
                printf("INFO\n");
                break;
            case 3:
                printf("WARN\n");
                break;
            case 4:
                printf("ERROR\n");
                break;
        }
        printf("Message: %s\n\n", logs[i].message);
    }

    // Free the memory allocated for the log_data array
    free(logs);

    return 0;
}