//FormAI DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINE_LENGTH 1000

typedef struct LogRecord {
    char* time;
    char* level;
    char* message;
    struct LogRecord* next;
} LogRecord;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./log-analyzer filename\n");
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (!file) {
        printf("Error: Cannot open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    LogRecord *head = NULL;
    LogRecord *tail = NULL;

    char line[MAX_LOG_LINE_LENGTH];
    while (fgets(line, MAX_LOG_LINE_LENGTH, file)) {
        char* time = strtok(line, ",");
        char* level = strtok(NULL, ",");
        char* message = strtok(NULL, ",");
        message[strcspn(message, "\n")] = 0; // remove newline character at end of message

        LogRecord *record = (LogRecord*)malloc(sizeof(LogRecord));
        record->time = time;
        record->level = level;
        record->message = message;
        record->next = NULL;

        if (!head) {
            head = record;
            tail = record;
        }
        else {
            tail->next = record;
            tail = record;
        }
    }

    fclose(file);

    // print out all log records
    LogRecord *current = head;
    while (current) {
        printf("%s,%s,%s\n", current->time, current->level, current->message);
        current = current->next;
    }

    // find and print all error messages
    printf("\nError messages:\n");
    current = head;
    while (current) {
        if (strcmp(current->level, "ERROR") == 0) {
            printf("%s,%s\n", current->time, current->message);
        }
        current = current->next;
    }

    // count number of warnings and print out result
    int num_warnings = 0;
    current = head;
    while (current) {
        if (strcmp(current->level, "WARNING") == 0) {
            num_warnings++;
        }
        current = current->next;
    }
    printf("\nNumber of warnings: %d\n", num_warnings);

    // free all dynamically allocated memory
    current = head;
    while (current) {
        LogRecord *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}