#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 10

typedef struct {
    char *message;
} LogEntry;

LogEntry log_entries[MAX_LOG_ENTRIES];
int log_count = 0;

void add_log_entry(const char *msg) {
    if (log_count >= MAX_LOG_ENTRIES) return;
    log_entries[log_count].message = strdup(msg);
    log_count++;
}

void remove_log_entry(int index) {
    if (index < 0 || index >= log_count) return;
    free(log_entries[index].message);
    log_entries[index].message = NULL;
}

void print_logs() {
    for (int i = 0; i < log_count; i++) {
        printf("Log %d: %s\n", i, log_entries[i].message);
    }
}

int main() {
    add_log_entry("System started");
    add_log_entry("User logged in");
    remove_log_entry(0); // Remove first entry
    add_log_entry("User performed action");
    print_logs();
    return 0;
}
