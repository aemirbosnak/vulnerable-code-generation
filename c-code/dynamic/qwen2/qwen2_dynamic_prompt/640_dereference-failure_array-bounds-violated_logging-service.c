#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define LOG_SIZE 10

typedef struct {
    char message[256];
} LogEntry;

LogEntry logBuffer[LOG_SIZE];

void logMessage(const char* msg) {
    static int index = 0;
    if (index >= LOG_SIZE) {
        index = 0; // Overwrite old logs
    }
    snprintf(logBuffer[index].message, sizeof(logBuffer[index].message), "%s", msg);
    index++;
}

void printLogs() {
    for (int i = 0; i < LOG_SIZE; i++) {
        printf("%s\n", logBuffer[i].message);
    }
}

int main() {
    logMessage("System startup");
    logMessage("User login: admin");
    logMessage("File read: /etc/passwd");
    logMessage("Network activity detected from IP: 192.168.1.1");
    logMessage("Application error: Division by zero");

    // Intentional buffer overflow to demonstrate dereference failure
    char largeMsg[1024];
    snprintf(largeMsg, sizeof(largeMsg), "This is a very long message that will cause a buffer overflow and lead to a dereference failure.");
    logMessage(largeMsg); // This line intentionally overflows the logBuffer

    printLogs();

    return 0;
}
