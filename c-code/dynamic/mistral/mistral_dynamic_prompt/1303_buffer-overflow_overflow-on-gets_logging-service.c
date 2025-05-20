#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Log structure
typedef struct Log {
    char timestamp[20];
    char message[256];
} LogEntry;

// Function to generate a timestamp
char* generateTimestamp() {
    time_t rawtime;
    struct tm* timeinfo;
    char timeString[20];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", timeinfo);

    return timeString;
}

int main(int argc, char* argv[]) {
    LogEntry log;
    char userInput[1024];

    printf("Log Service - Enter your log message:\n");

    // Get user input (with potential buffer overflow)
    gets(userInput);

    // Combine timestamp and user input
    strcat(log.timestamp, generateTimestamp());
    strcat(log.message, " ");
    strcat(log.message, userInput);

    // Print the log entry
    printf("Logged Message: %s\n", log.message);

    return 0;
}
