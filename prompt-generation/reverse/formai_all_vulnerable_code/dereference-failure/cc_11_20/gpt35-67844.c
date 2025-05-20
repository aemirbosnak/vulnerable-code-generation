//FormAI DATASET v1.0 Category: Log analysis ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000
#define FILE_NAME "example.log"

typedef enum {
    INFO,
    WARNING,
    ERROR
} LogLevel;

typedef struct {
    char timestamp[20];
    LogLevel level;
    char message[100];
} LogRecord;

int main() {
    FILE *log_file = fopen(FILE_NAME, "r");

    if (!log_file) {
        printf("Error opening file %s\n", FILE_NAME);
        return 1;
    }

    LogRecord logs[MAX_LOG_SIZE];
    int count = 0;

    char line[300];
    char *timestamp, *level, *message;
    while (fgets(line, sizeof(line), log_file)) {
        timestamp = strtok(line, " ");
        level = strtok(NULL, " ");
        message = strtok(NULL, "\n");

        strcpy(logs[count].timestamp, timestamp);

        if (strcmp(level, "INFO") == 0) {
            logs[count].level = INFO;
        } else if (strcmp(level, "WARNING") == 0) {
            logs[count].level = WARNING;
        } else if (strcmp(level, "ERROR") == 0) {
            logs[count].level = ERROR;
        }

        strcpy(logs[count].message, message);
        count++;
    }

    fclose(log_file);

    printf("Total log records: %d\n\n", count);

    printf("INFO messages:\n");
    for (int i = 0; i < count; i++) {
        if (logs[i].level == INFO) {
            printf("%s [%s] %s\n", logs[i].timestamp, "INFO", logs[i].message);
        }
    }

    printf("\nWARNING messages:\n");
    for (int i = 0; i < count; i++) {
        if (logs[i].level == WARNING) {
            printf("%s [%s] %s\n", logs[i].timestamp, "WARNING", logs[i].message);
        }
    }

    printf("\nERROR messages:\n");
    for (int i = 0; i < count; i++) {
        if (logs[i].level == ERROR) {
            printf("%s [%s] %s\n", logs[i].timestamp, "ERROR", logs[i].message);
        }
    }

    return 0;
}