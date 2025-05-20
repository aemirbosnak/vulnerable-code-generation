#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_FILES 10
#define LOG_FILE_NAME "log.txt"

typedef struct {
    char log[1024];
    time_t timestamp;
} LogEntry;

LogEntry *log_files[MAX_LOG_FILES];
int current_log_index = 0;

void add_to_log(const char *message) {
    LogEntry *new_entry = (LogEntry *) malloc(sizeof(LogEntry));
    snprintf(new_entry->log, sizeof(new_entry->log), "%s", message);
    new_entry->timestamp = time(NULL);

    log_files[current_log_index] = new_entry;
    current_log_index++;

    FILE *log_file = fopen(LOG_FILE_NAME, "a");
    if (log_file != NULL) {
        fprintf(log_file, "%s\n", new_entry->log);
        fclose(log_file);
    }
}

int main() {
    char *attacker_message = (char *) malloc(0);

    add_to_log("Starting logging service...");

    // Simulate an attacker trying to cause a null pointer dereference
    attacker_message = NULL;
    add_to_log(attacker_message);

    add_to_log("Logging service terminated.");

    return 0;
}
