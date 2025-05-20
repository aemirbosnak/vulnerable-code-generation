//FormAI DATASET v1.0 Category: Log analysis ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Greet the user
    printf("Hello there! Welcome to Log Analyzer 3000!\n");

    // Prompt the user for the log file name
    printf("Please enter the name of the log file you wish to analyze: ");
    char filename[50];
    scanf("%s", filename);

    // Open the log file
    FILE *file = fopen(filename, "r");

    // Check if the file is valid
    if (file == NULL) {
        printf("Oops! The file you entered (%s) does not exist.\n", filename);
        return 0;
    }

    // Declare some variables
    int infoCount = 0;
    int warningCount = 0;
    int errorCount = 0;

    // Read each line in the file until we reach the end
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        // Check if the line contains the word 'info'
        if (strstr(line, "info")) {
            // Increase the info count
            infoCount++;
        }

        // Check if the line contains the word 'warning'
        if (strstr(line, "warning")) {
            // Increase the warning count
            warningCount++;
        }

        // Check if the line contains the word 'error'
        if (strstr(line, "error")) {
            // Increase the error count
            errorCount++;
        }
    }

    // Close the file
    fclose(file);

    // Display the results to the user
    printf("\nResults:\n");
    printf("Total number of info logs: %d\n", infoCount);
    printf("Total number of warning logs: %d\n", warningCount);
    printf("Total number of error logs: %d\n", errorCount);

    // Say goodbye to the user
    printf("\nThank you for using Log Analyzer 3000! Have a nice day!\n");

    return 0;
}