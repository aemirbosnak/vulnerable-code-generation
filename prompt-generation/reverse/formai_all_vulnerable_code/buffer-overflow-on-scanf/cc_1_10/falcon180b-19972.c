//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    struct log_entry *next;
} log_entry;

typedef struct {
    int count;
    log_entry *entries;
} log_data;

log_entry *read_log_file(FILE *fp, log_data *data);
void print_log_entries(log_entry *entry);
void free_log_entries(log_entry *entry);

int main() {
    FILE *fp;
    char filename[MAX_LINE_LENGTH];
    log_data data;

    printf("Enter the name of the log file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }

    data.entries = NULL;
    data.count = 0;

    data.entries = read_log_file(fp, &data);

    if (data.count == 0) {
        printf("No log entries found.\n");
    } else {
        printf("Log entries:\n");
        print_log_entries(data.entries);
    }

    free_log_entries(data.entries);
    fclose(fp);

    return 0;
}

log_entry *read_log_file(FILE *fp, log_data *data) {
    char line[MAX_LINE_LENGTH];
    char *token;
    log_entry *entry = NULL;
    log_entry *head = NULL;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, " ");
        if (token == NULL) {
            continue;
        }

        if (strcmp(token, "GET") == 0 || strcmp(token, "POST") == 0) {
            entry = (log_entry *)malloc(sizeof(log_entry));
            entry->line = strdup(line);
            entry->next = NULL;

            if (head == NULL) {
                head = entry;
            } else {
                log_entry *current = head;
                while (current->next!= NULL) {
                    current = current->next;
                }
                current->next = entry;
            }

            data->count++;
        }
    }

    return head;
}

void print_log_entries(log_entry *entry) {
    while (entry!= NULL) {
        printf("%s\n", entry->line);
        entry = entry->next;
    }
}

void free_log_entries(log_entry *entry) {
    while (entry!= NULL) {
        free(entry->line);
        entry = entry->next;
    }
}