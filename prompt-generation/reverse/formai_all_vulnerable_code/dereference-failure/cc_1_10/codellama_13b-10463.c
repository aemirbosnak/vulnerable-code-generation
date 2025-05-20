//Code Llama-13B DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char* log_entry;
    bool is_error;
} LogEntry;

LogEntry* parse_log_entry(char* line) {
    LogEntry* entry = malloc(sizeof(LogEntry));
    entry->log_entry = strdup(line);
    entry->is_error = false;

    char* error_msg = strstr(line, "ERROR:");
    if (error_msg != NULL) {
        entry->is_error = true;
    }

    return entry;
}

void print_log_entry(LogEntry* entry) {
    if (entry->is_error) {
        printf("[ERROR] ");
    } else {
        printf("[INFO] ");
    }

    printf("%s\n", entry->log_entry);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE* log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file %s\n", argv[1]);
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), log_file) != NULL) {
        LogEntry* entry = parse_log_entry(line);
        print_log_entry(entry);
        free(entry);
    }

    fclose(log_file);
    return 0;
}