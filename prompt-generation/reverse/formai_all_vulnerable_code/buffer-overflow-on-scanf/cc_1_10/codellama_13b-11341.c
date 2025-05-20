//Code Llama-13B DATASET v1.0 Category: Log analysis ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LOG_ENTRIES 100

typedef struct {
    char message[100];
    int level;
    int timestamp;
} LogEntry;

void print_log_entry(LogEntry* entry) {
    printf("[%d] %s\n", entry->level, entry->message);
}

int main() {
    LogEntry entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    while (1) {
        char input[100];
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        int level = 0;
        if (strcmp(input, "debug") == 0) {
            level = 1;
        } else if (strcmp(input, "info") == 0) {
            level = 2;
        } else if (strcmp(input, "warn") == 0) {
            level = 3;
        } else if (strcmp(input, "error") == 0) {
            level = 4;
        }

        int timestamp = time(NULL);

        strcpy(entries[num_entries].message, input);
        entries[num_entries].level = level;
        entries[num_entries].timestamp = timestamp;

        num_entries++;
    }

    for (int i = 0; i < num_entries; i++) {
        print_log_entry(&entries[i]);
    }

    return 0;
}