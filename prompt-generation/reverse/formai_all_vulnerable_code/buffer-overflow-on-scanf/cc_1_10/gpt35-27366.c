//FormAI DATASET v1.0 Category: Log analysis ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_LOG_ENTRIES 100

typedef struct log_entry {
    char date[11];
    char time[9];
    char level[10];
    char message[MAX_LINE_LENGTH];
} log_entry;

void parse_line(char *line, log_entry *entry) {
    char *token = strtok(line, " ");
    int i = 0;

    while (token) {
        switch (i) {
            case 0: 
                strncpy(entry->date, token, 10);
                break;
            case 1:
                strncpy(entry->time, token, 8);
                break;
            case 2:
                strncpy(entry->level, token, 10);
                break;
            default:
                strcat(entry->message, token);
                strcat(entry->message, " ");
                break;
        }

        token = strtok(NULL, " ");
        i++;
    }

    // Remove trailing whitespace from message
    entry->message[strcspn(entry->message, "\n")] = '\0';
}

void print_log_entry(log_entry entry) {
    printf("%s %s %s %s\n", entry.date, entry.time, entry.level, entry.message);
}

int main() {
    FILE *log_file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    log_entry entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    printf("Enter filename to analyze: ");
    scanf("%s", filename);

    log_file = fopen(filename, "r");
    if (!log_file) {
        printf("Error: file could not be opened.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), log_file)) {
        // Ignore empty lines
        if (strcmp(line, "\n") == 0) {
            continue;
        }

        log_entry entry;
        parse_line(line, &entry);
        entries[num_entries] = entry;
        num_entries++;
    }

    fclose(log_file);

    printf("Log file contains %d entries.\n\n", num_entries);

    // Print all entries
    for (int i = 0; i < num_entries; i++) {
        print_log_entry(entries[i]);
    }

    // Count number of entries of each level
    int debug_count = 0;
    int info_count = 0;
    int error_count = 0;

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].level, "DEBUG") == 0) {
            debug_count++;
        } else if (strcmp(entries[i].level, "INFO") == 0) {
            info_count++;
        } else if (strcmp(entries[i].level, "ERROR") == 0) {
            error_count++;
        }
    }

    printf("\nNumber of entries by level:\n");
    printf("DEBUG: %d\n", debug_count);
    printf("INFO: %d\n", info_count);
    printf("ERROR: %d\n", error_count);

    // Find entries containing keyword
    char keyword[MAX_LINE_LENGTH];
    printf("\nEnter keyword to search for: ");
    scanf("%s", keyword);

    printf("Entries containing \"%s\":\n", keyword);
    for (int i = 0; i < num_entries; i++) {
        char *lowercase_message = strdup(entries[i].message);
        for (int j = 0; lowercase_message[j]; j++) {
            lowercase_message[j] = tolower(lowercase_message[j]);
        }

        char *found = strstr(lowercase_message, keyword);
        if (found) {
            print_log_entry(entries[i]);
        }
    }

    return 0;
}