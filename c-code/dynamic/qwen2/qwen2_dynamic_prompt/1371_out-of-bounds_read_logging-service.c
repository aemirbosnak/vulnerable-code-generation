#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

typedef struct {
    char log[MAX_LOG_SIZE];
} LogEntry;

void write_log(LogEntry *entry, const char *message) {
    if (strlen(message) >= MAX_LOG_SIZE - 1) {
        fprintf(stderr, "Error: Message too large\n");
        return;
    }
    strcpy(entry->log, message);
}

void read_log(LogEntry *entry, int index) {
    if (index < 0 || index >= strlen(entry->log)) {
        printf("Out of bounds read attempt at index %d\n", index);
        exit(1);
    }
    printf("Log entry at index %d: %c\n", index, entry->log[index]);
}

int main() {
    LogEntry my_log;
    write_log(&my_log, "This is a test log entry.");

    // Intentionally trying to read out of bounds
    read_log(&my_log, 20);

    return 0;
}
