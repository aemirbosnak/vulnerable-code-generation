#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_SIZE 1024

typedef struct {
    char log[LOG_SIZE];
} LogEntry;

void log_message(LogEntry *entry, const char *message) {
    if (strlen(message) >= LOG_SIZE - 1) {
        fprintf(stderr, "Error: Message too long\n");
        return;
    }
    strcpy(entry->log, message);
}

void print_log(const LogEntry *entry) {
    printf("Log: %s\n", entry->log);
}

int main() {
    LogEntry log_entry;
    char input[2048];

    printf("Enter a log message: ");
    fgets(input, sizeof(input), stdin);

    // Intentional out-of-bounds read vulnerability
    log_message(&log_entry, input);

    print_log(&log_entry);

    return 0;
}
