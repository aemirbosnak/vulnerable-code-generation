#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[256];
    char level[256];
    char message[4096];
    time_t timestamp;
} LogEntry;

LogEntry* create_log_entry() {
    LogEntry* entry = (LogEntry*)malloc(sizeof(LogEntry));
    return entry;
}

void destroy_log_entry(LogEntry* entry) {
    free(entry);
}

void print_log_entry(LogEntry* entry) {
    printf("Name: %s\n", entry->name);
    printf("Level: %s\n", entry->level);
    printf("Message: %s\n", entry->message);
    printf("Timestamp: %s", ctime(&entry->timestamp));
}

void write_log_entry(LogEntry* entry) {
    FILE* log_file = fopen("log.txt", "a");
    fprintf(log_file, "Name: %s\n", entry->name);
    fprintf(log_file, "Level: %s\n", entry->level);
    fprintf(log_file, "Message: %s\n", entry->message);
    fprintf(log_file, "Timestamp: %s", ctime(&entry->timestamp));
    fclose(log_file);
}

int main() {
    LogEntry* entry = create_log_entry();
    strcpy(entry->name, "John Doe");
    strcpy(entry->level, "ERROR");
    strcpy(entry->message, "Invalid database connection.");
    print_log_entry(entry);
    write_log_entry(entry);
    destroy_log_entry(NULL); // Dereference failure
    return 0;
}
