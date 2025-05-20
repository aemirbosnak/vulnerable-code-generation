#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 10

struct Log {
    char message[100];
    struct Log *next;
};

struct Log *head = NULL;

void log_message(const char *msg) {
    struct Log *log = (struct Log *) malloc(sizeof(struct Log));
    strcpy(log->message, msg);
    log->next = head;
    head = log;
}

void free_logs() {
    struct Log *current = head;
    struct Log *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

int main() {
    char *messages[5] = {
        "Initializing service...",
        "Logging connection established...",
        "Received package: Package 1",
        "Processing package...",
        "Package 1 processed successfully."
    };

    int i;
    for (i = 0; i < 5; i++) {
        log_message(messages[i]);
    }

    // Simulate new log messages
    log_message("Handling error...");
    log_message("New log added...");

    // Service cleanup
    free_logs();

    return 0;
}
