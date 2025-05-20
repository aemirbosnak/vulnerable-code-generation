//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 1024

typedef struct {
    char message[MAX_LOG_ENTRY_LENGTH];
    time_t timestamp;
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int numLogEntries = 0;

void log(const char* format,...) {
    va_list args;
    va_start(args, format);
    vsnprintf(logEntries[numLogEntries].message, MAX_LOG_ENTRY_LENGTH, format, args);
    logEntries[numLogEntries].timestamp = time(NULL);
    numLogEntries++;
    if (numLogEntries >= MAX_LOG_ENTRIES) {
        numLogEntries = 0;
    }
    va_end(args);
}

void printLog() {
    for (int i = 0; i < numLogEntries; i++) {
        printf("%s (%ld)\n", logEntries[i].message, logEntries[i].timestamp);
    }
}

int main() {
    log("Starting program...");

    int choice;
    do {
        printf("\n");
        printf("1. Do something\n");
        printf("2. Do something else\n");
        printf("3. Exit\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                log("Doing something...");
                break;
            case 2:
                log("Doing something else...");
                break;
            case 3:
                log("Exiting program...");
                break;
            default:
                log("Invalid choice");
        }
    } while (choice!= 3);

    printLog();

    return 0;
}