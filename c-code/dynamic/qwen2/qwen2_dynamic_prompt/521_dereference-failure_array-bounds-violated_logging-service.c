#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100

typedef struct {
    char message[256];
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];

void add_log_entry(const char *message) {
    static int index = 0;
    if (index >= MAX_LOG_ENTRIES) {
        printf("Log buffer overflow!\n");
        return;
    }
    strncpy(logEntries[index].message, message, sizeof(logEntries[index].message) - 1);
    logEntries[index].message[sizeof(logEntries[index].message) - 1] = '\0';
    index++;
}

void print_logs() {
    for (int i = 0; i < MAX_LOG_ENTRIES; i++) {
        if (logEntries[i].message[0] == '\0') {
            break;
        }
        printf("%s\n", logEntries[i].message);
    }
}

int main() {
    add_log_entry("System started.");
    add_log_entry("User logged in.");
    // Intentionally causing an array bounds violation by accessing beyond MAX_LOG_ENTRIES
    add_log_entry("This should cause a buffer overflow.");

    print_logs();

    return 0;
}
