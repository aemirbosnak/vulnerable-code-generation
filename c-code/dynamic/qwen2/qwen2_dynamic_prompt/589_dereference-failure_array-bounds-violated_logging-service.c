#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100

typedef struct {
    char message[256];
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];

void logMessage(const char *message) {
    static int index = 0;
    if (index >= MAX_LOG_ENTRIES) {
        printf("Error: Log buffer overflow\n");
        return;
    }
    strncpy(logEntries[index].message, message, sizeof(logEntries[index].message) - 1);
    logEntries[index].message[sizeof(logEntries[index].message) - 1] = '\0';
    index++;
}

void printLogs() {
    for (int i = 0; i < MAX_LOG_ENTRIES; i++) {
        if (logEntries[i].message[0] != '\0') {
            printf("%s\n", logEntries[i].message);
        } else {
            break;
        }
    }
}

int main() {
    logMessage("System startup");
    logMessage("User login: admin");
    logMessage("File read: /etc/passwd");

    // Intentional out-of-bounds write to demonstrate vulnerability
    logEntries[MAX_LOG_ENTRIES].message[0] = 'X'; // This will overwrite the next entry's message

    logMessage("File write: /etc/hosts");
    logMessage("User logout: admin");

    printLogs();

    return 0;
}
