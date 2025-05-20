#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define LOG_FILE "log.txt"

void log_message(const char* message) {
    FILE* file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        return;
    }
    fprintf(file, "%s\n", message);
    fclose(file);
}

int main() {
    const char* messages[] = {
        "Starting application",
        "Processing data",
        "Error: Division by zero",
        "User logged in",
        "System shutdown"
    };

    int num_messages = sizeof(messages) / sizeof(messages[0]);

    // Simulate logging with intentional buffer overflow
    char buffer[10];
    for (int i = 0; i < num_messages; i++) {
        snprintf(buffer, sizeof(buffer), "%s", messages[i]);
        log_message(buffer);
    }

    return 0;
}
