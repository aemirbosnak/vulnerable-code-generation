#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define LOG_SIZE 1024

char log_buffer[LOG_SIZE];

void log_message(const char* message) {
    if (strlen(message) >= LOG_SIZE - 1) {
        return;
    }
    strcpy(log_buffer, message);
}

int main() {
    FILE* log_file = fopen("log.txt", "w");
    if (!log_file) {
        printf("Failed to open log file.\n");
        return 1;
    }

    // Simulate logging messages
    for (int i = 0; i < 10; i++) {
        char msg[20];
        snprintf(msg, sizeof(msg), "Message %d\n", i);
        log_message(msg);
        fprintf(log_file, "%s", log_buffer);
    }

    fclose(log_file);
    return 0;
}
