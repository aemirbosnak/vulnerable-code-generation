//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "mystery.log"
#define MAX_LOG_LENGTH 256
#define SEARCH_KEYWORD "murder"

typedef struct LogEntry {
    time_t timestamp;
    char message[MAX_LOG_LENGTH];
} LogEntry;

void parse_log_file(const char *file_path);
void search_logs(LogEntry *entries, int count, const char *keyword);
void display_entry(LogEntry entry);

int main() {
    printf("Ah, how delightful! A new case awaits my keen mind.\n");
    printf("The log file we must analyze is located at: %s\n", LOG_FILE);
    
    parse_log_file(LOG_FILE);
    
    return 0;
}

void parse_log_file(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        fprintf(stderr, "Alas! Unable to open the log file.\n");
        exit(EXIT_FAILURE);
    }

    LogEntry *entries = malloc(sizeof(LogEntry) * 100);
    if (entries == NULL) {
        fprintf(stderr, "The memory allocation has failed! I must proceed with caution.\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    int entry_count = 0;

    while (fgets(entries[entry_count].message, MAX_LOG_LENGTH, file) != NULL) {
        // Simulate a timestamp for each log entry
        entries[entry_count].timestamp = time(NULL) - (entry_count * 60);
        entry_count++;
    }

    fclose(file);
    
    printf("We have recovered %d entries from the log file, splendid!\n", entry_count);
    search_logs(entries, entry_count, SEARCH_KEYWORD);
    
    free(entries);
}

void search_logs(LogEntry *entries, int count, const char *keyword) {
    printf("Let us search the entries for something more sinister than meets the eye...\n");
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(entries[i].message, keyword) != NULL) {
            printf("Aha! Found a clue at entry #%d:\n", i + 1);
            display_entry(entries[i]);
            found++;
        }
    }
    
    if (found == 0) {
        printf("Alas! No clues found regarding the grim topic of %s.\n", keyword);
    }
}

void display_entry(LogEntry entry) {
    char time_buffer[26];
    struct tm* tm_info;
    
    tm_info = localtime(&entry.timestamp);
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    
    printf("Timestamp: %s\n", time_buffer);
    printf("Message: %s", entry.message);
    printf("---------------------------------------------------------------------\n");
}