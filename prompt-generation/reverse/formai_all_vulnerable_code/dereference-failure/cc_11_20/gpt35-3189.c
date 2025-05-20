//FormAI DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Define color codes for output
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

int main() {
    // Initialize variables
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char *level;
    int debug = 0, info = 0, warn = 0, error = 0, fatal = 0;

    // Get filename from user input
    printf("Please enter the name of the log file: ");
    fgets(filename, MAX_LINE_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0;

    // Open file for reading
    FILE *logfile = fopen(filename, "r");
    if (logfile == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read through file line by line
    while (fgets(line, MAX_LINE_LENGTH, logfile)) {
        // Find the error level (first word in line)
        level = strtok(line, " ");
        if (strcmp(level, "DEBUG") == 0) {
            debug++;
        } else if (strcmp(level, "INFO") == 0) {
            info++;
        } else if (strcmp(level, "WARN") == 0) {
            warn++;
        } else if (strcmp(level, "ERROR") == 0) {
            error++;
        } else if (strcmp(level, "FATAL") == 0) {
            fatal++;
        }
    }

    // Close file
    fclose(logfile);

    // Print results as a bar chart
    printf("\nLog analysis results:\n\n");
    printf(RED "DEBUG: " RESET);
    for (int i = 1; i <= debug; i++) {
        printf("█");
    }
    printf(" %d\n", debug);
    printf(GREEN "INFO: " RESET);
    for (int i = 1; i <= info; i++) {
        printf("█");
    }
    printf(" %d\n", info);
    printf(YELLOW "WARN: " RESET);
    for (int i = 1; i <= warn; i++) {
        printf("█");
    }
    printf(" %d\n", warn);
    printf(BLUE "ERROR: " RESET);
    for (int i = 1; i <= error; i++) {
        printf("█");
    }
    printf(" %d\n", error);
    printf(MAGENTA "FATAL: " RESET);
    for (int i = 1; i <= fatal; i++) {
        printf("█");
    }
    printf(" %d\n", fatal);

    return 0;
}