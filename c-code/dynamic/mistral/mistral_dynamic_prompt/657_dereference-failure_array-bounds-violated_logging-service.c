#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024
#define NUM_LOGS 100

typedef struct {
    char timestamp[32];
    char log_message[MAX_LOG_SIZE];
} LogEntry;

LogEntry logs[NUM_LOGS];
int log_index = 0;

void log_message(const char *message) {
    if (log_index >= NUM_LOGS) {
        printf("Log buffer is full.\n");
        return;
    }

    strcpy(logs[log_index].log_message, message);
    log_index++;
    // Intentional dereference failure to show vulnerability
    printf("Logged message: %s\n", logs[log_index - 1].log_message);
}

int main() {
    char userInput[MAX_LOG_SIZE];

    printf("Log Service - Enter messages to log (or enter 'exit' to quit):\n");

    while (1) {
        fgets(userInput, MAX_LOG_SIZE, stdin);
        char *message = strtok(userInput, "\n");

        if (strcmp(message, "exit") == 0) {
            break;
        }

        log_message(message);
    }

    return 0;
}
