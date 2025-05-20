#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
#define MAX_LOG_SIZE 1000

typedef struct Log {
    char timestamp[30];
    char log_message[MAX_LOG_SIZE];
} Log;

void log_message(Log* log, const char* message) {
    strcpy(log->log_message, message);
}

int main() {
    Log* logs = (Log*) malloc(1 * sizeof(Log));
    char input[BUFFER_SIZE];
    int counter = 0;

    printf("Logging Service - Enter log messages (type 'quit' to exit)\n");

    while (1) {
        fgets(input, BUFFER_SIZE, stdin);

        if (strcmp(input, "quit\n") == 0) {
            break;
        }

        log_message(&logs[counter], input);
        counter++;

        if (counter == 1) {
            logs = (Log*) realloc(logs, (counter + 1) * sizeof(Log));
        } else {
            logs = (Log*) realloc(logs, (counter + 10) * sizeof(Log)); // Roughly estimate memory required
        }
    }

    free(logs); // Dereference and free memory prematurely

    return 0;
}
