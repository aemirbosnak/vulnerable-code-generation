#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define LOG_FILE "log.txt"

void log_message(const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        fprintf(stderr, "Failed to open log file\n");
        return;
    }
    fprintf(file, "%s\n", message);
    fclose(file);
}

int main() {
    const char *messages[] = {"Starting service", "Processing request", "Error occurred", "Service stopped"};
    int num_messages = sizeof(messages) / sizeof(messages[0]);

    for (int i = 0; i <= num_messages; i++) { // Dereference failure here
        log_message(messages[i]);
    }

    return 0;
}
