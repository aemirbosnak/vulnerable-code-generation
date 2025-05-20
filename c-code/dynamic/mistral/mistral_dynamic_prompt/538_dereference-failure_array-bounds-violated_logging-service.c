#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 100
#define NUM_LOGS 1000

struct Log {
    char logMessage[MAX_LOG_SIZE];
    time_t timestamp;
};

struct Log logs[NUM_LOGS];
int logIndex = 0;

void logMessage(char *message) {
    strcpy(logs[logIndex].logMessage, message);
    logs[logIndex].timestamp = time(NULL);
    logIndex++;
}

int main() {
    char input[MAX_LOG_SIZE];
    while (1) {
        printf("Enter log message (or 'q' to quit): ");
        fgets(input, MAX_LOG_SIZE, stdin);
        if (strchr(input, 'q') != NULL)
            break;

        logMessage(input);

        printf("Log message '%s' saved at %s\n", logs[logIndex-1].logMessage, ctime(&(logs[logIndex-1].timestamp)));

        if (logIndex == NUM_LOGS) {
            printf("Log buffer is full. Overwriting oldest logs.\n");
            logIndex = 0;
        }
    }

    return 0;
}
