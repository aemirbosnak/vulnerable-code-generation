//FormAI DATASET v1.0 Category: Log analysis ; Style: enthusiastic
#include <stdio.h>
#define MAX_LINE_LENGTH 256
#define MAX_LOGS 1000

int main() {
    // Welcome message
    printf("Welcome to the Log Analysis Program!\n\n");
    printf("Please enter the file name of the log: ");

    // Get file name from user
    char file_name[50];
    scanf("%s", file_name);

    // Open log file
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", file_name);
        return 1;
    }

    // Initialize arrays to store logs
    char logs[MAX_LOGS][MAX_LINE_LENGTH];
    int count = 0;

    // Read logs from file and store in array
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        if (count < MAX_LOGS) {
            strcpy(logs[count], line);
            count++;
        }
    }

    // Close file
    fclose(fp);

    // Print number of logs found
    printf("\n%d logs found in %s\n\n", count, file_name);

    // Analyze logs
    int num_errors = 0;
    int num_warnings = 0;
    int num_infos = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(logs[i], "ERROR")) {
            num_errors++;
        } else if (strstr(logs[i], "WARNING")) {
            num_warnings++;
        } else if (strstr(logs[i], "INFO")) {
            num_infos++;
        }
    }

    // Print analysis results
    printf("Log Analysis Results:\n");
    printf("Number of Errors: %d\n", num_errors);
    printf("Number of Warnings: %d\n", num_warnings);
    printf("Number of Infos: %d\n", num_infos);

    // End of program message
    printf("\nThank you for using the Log Analysis Program!\n");

    return 0;
}