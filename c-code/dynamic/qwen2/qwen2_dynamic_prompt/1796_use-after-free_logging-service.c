#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_SIZE 1024

typedef struct {
    char *buffer;
    size_t length;
} LogEntry;

LogEntry *logs[LOG_SIZE];
size_t log_count = 0;

void add_log(const char *message) {
    if (log_count >= LOG_SIZE) return;
    logs[log_count] = malloc(sizeof(LogEntry));
    logs[log_count]->length = strlen(message);
    logs[log_count]->buffer = strdup(message);
    log_count++;
}

void remove_log(size_t index) {
    if (index >= log_count) return;
    free(logs[index]->buffer);
    free(logs[index]);
    for (size_t i = index; i < log_count - 1; i++) {
        logs[i] = logs[i + 1];
    }
    log_count--;
}

void print_logs() {
    for (size_t i = 0; i < log_count; i++) {
        printf("%zu: %s\n", i, logs[i]->buffer);
    }
}

int main() {
    add_log("System started");
    add_log("User logged in");
    remove_log(0); // Remove first log entry
    add_log("User performed action");
    print_logs();
    return 0;
}
