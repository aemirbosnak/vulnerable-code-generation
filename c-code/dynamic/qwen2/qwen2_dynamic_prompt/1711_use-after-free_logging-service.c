#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100

typedef struct {
    char *message;
} LogEntry;

LogEntry log_entries[MAX_LOG_ENTRIES];
int log_count = 0;

void add_log_entry(const char *msg) {
    if (log_count >= MAX_LOG_ENTRIES) {
        printf("Log buffer full!\n");
        return;
    }
    log_entries[log_count].message = strdup(msg);
    log_count++;
}

void print_logs() {
    for (int i = 0; i < log_count; i++) {
        printf("%s\n", log_entries[i].message);
    }
}

void free_logs() {
    for (int i = 0; i < log_count; i++) {
        free(log_entries[i].message);
    }
    log_count = 0;
}

int main() {
    add_log_entry("System started");
    add_log_entry("User logged in");

    // Simulate some operations
    for (int i = 0; i < 98; i++) {
        char msg[20];
        snprintf(msg, sizeof(msg), "Operation %d", i);
        add_log_entry(msg);
    }

    print_logs();

    // Free logs
    free_logs();

    // Use after free vulnerability
    printf("%s\n", log_entries[97].message); // This will cause undefined behavior

    return 0;
}
