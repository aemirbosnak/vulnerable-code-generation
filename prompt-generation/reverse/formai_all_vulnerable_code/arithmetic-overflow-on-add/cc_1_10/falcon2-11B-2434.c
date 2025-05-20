//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int log_count;
    int error_count;
    int warning_count;
    int info_count;
    int debug_count;
} LogAnalysis;

void log_analysis(char *log_file) {
    LogAnalysis analysis;
    FILE *log = fopen(log_file, "r");
    if (log == NULL) {
        printf("Error: Could not open log file\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), log)!= NULL) {
        char *level = strtok(line, ": ");
        char *message = strtok(NULL, "\n");
        int level_num = atoi(level);
        if (level_num >= 0 && level_num <= 4) {
            if (level_num == 0) {
                analysis.error_count++;
            } else if (level_num == 1) {
                analysis.warning_count++;
            } else if (level_num == 2) {
                analysis.info_count++;
            } else if (level_num == 3) {
                analysis.debug_count++;
            } else {
                printf("Invalid log level: %d\n", level_num);
            }
            printf("%s\n", message);
        }
    }
    fclose(log);

    printf("Log Analysis:\n");
    printf("Total Log Count: %d\n", analysis.log_count);
    printf("Error Count: %d\n", analysis.error_count);
    printf("Warning Count: %d\n", analysis.warning_count);
    printf("Info Count: %d\n", analysis.info_count);
    printf("Debug Count: %d\n", analysis.debug_count);
}

int main() {
    char *log_file = "example.log";
    log_analysis(log_file);
    return 0;
}