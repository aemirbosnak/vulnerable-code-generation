//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_LOG_SIZE 1000
#define MAX_ERROR_LEVELS 5

typedef struct {
    char level[16];
    int count;
} LogLevel;

LogLevel errorLevels[MAX_ERROR_LEVELS] = {
    {"INFO", 0},
    {"WARNING", 0},
    {"ERROR", 0},
    {"DEBUG", 0},
    {"FATAL", 0}
};

int uniqueMessagesCount = 0;
char *uniqueMessages[MAX_LOG_SIZE];

void processLine(const char *line) {
    char logLevel[16];
    char message[MAX_LINE_LENGTH];
    
    sscanf(line, "%15s %[^\n]", logLevel, message);
    
    // Count occurrences of error levels
    for (int i = 0; i < MAX_ERROR_LEVELS; i++) {
        if (strcmp(logLevel, errorLevels[i].level) == 0) {
            errorLevels[i].count++;
            break;
        }
    }

    // Store unique messages
    for (int i = 0; i < uniqueMessagesCount; i++) {
        if (strcmp(uniqueMessages[i], message) == 0) {
            return; // Message already counted
        }
    }
    
    // If it's a new unique message, add it to the list
    uniqueMessages[uniqueMessagesCount] = strdup(message);
    uniqueMessagesCount++;
}

void printAnalysis() {
    printf("Log Analysis Report:\n");
    printf("--------------------\n");
    
    // Print error levels
    printf("Error Levels:\n");
    for (int i = 0; i < MAX_ERROR_LEVELS; i++) {
        printf("%s: %d\n", errorLevels[i].level, errorLevels[i].count);
    }
    
    // Print unique messages
    printf("\nUnique Messages (%d total):\n", uniqueMessagesCount);
    for (int i = 0; i < uniqueMessagesCount; i++) {
        printf("  - %s\n", uniqueMessages[i]);
        free(uniqueMessages[i]); // Free memory after printing
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *logFile = fopen(argv[1], "r");
    if (!logFile) {
        perror("Error opening log file");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), logFile)) {
        processLine(line);
    }

    fclose(logFile);
    
    printAnalysis();
    
    return EXIT_SUCCESS;
}