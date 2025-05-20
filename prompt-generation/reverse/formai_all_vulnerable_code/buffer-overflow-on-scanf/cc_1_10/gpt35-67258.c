//FormAI DATASET v1.0 Category: Log analysis ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to our unique C Log analysis program!\n");
    printf("Please enter the name of the log file to analyze: ");

    char filename[256];
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s for reading.\n", filename);
        exit(1);
    }

    printf("Successfully opened file %s.\n", filename);
    printf("Analyzing file...\n");

    int total_lines = 0;
    int error_lines = 0;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        total_lines++;

        if (strstr(line, "ERROR")) {
            error_lines++;
        }

        if (strstr(line, "I_AM_CONFUSED")) {
            printf("Warning: Log file contains confusion.\n");
        }

        if (strstr(line, "CRITICAL")) {
            printf("ALERT: Critical error in log file.\n");
            system("notify-admin.sh");
        }

        if (strstr(line, "FIXME")) {
            printf("Warning: Log file contains fixme.\n");
        }

        if (strstr(line, "TODO")) {
            printf("Note: Log file contains todo.\n");
        }
    }

    fclose(file);

    printf("Analysis complete.\n");
    printf("Total lines: %d\n", total_lines);
    printf("Error lines: %d\n", error_lines);

    if (error_lines > total_lines * 0.1) {
        printf("Error rate exceeds 10%%. Action required!\n");
    }

    return 0;
}