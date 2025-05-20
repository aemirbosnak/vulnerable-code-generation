#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

typedef struct {
    char log_msg[BUFFER_SIZE];
    char log_time[30];
} LogEntry;

LogEntry* create_log_entry() {
    LogEntry* new_entry = (LogEntry*) malloc(sizeof(LogEntry));
    if (!new_entry) {
        fprintf(stderr, "Failed to allocate memory for LogEntry\n");
        exit(EXIT_FAILURE);
    }
    memset(new_entry, 0, sizeof(LogEntry));
    return new_entry;
}

void write_log_to_file(LogEntry* entry, FILE* file) {
    fprintf(file, "%s - %s\n", entry->log_time, entry->log_msg);
}

int main() {
    int i;
    LogEntry* log = create_log_entry();
    FILE* log_file = fopen("vulnerable_logging_service.log", "w");

    for (i = 0; i < 10000; ++i) {
        snprintf(log->log_msg, BUFFER_SIZE, "Log message %d\n", i);
        strcpy(log->log_time, ctime(&i));

        write_log_to_file(log, log_file);
        write_log_to_file((LogEntry*)((void*)log + 1), log_file); // Dereference uninitialized memory
    }

    fclose(log_file);
    free(log);

    return 0;
}
