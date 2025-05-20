//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define LOG_FILE "log.txt"

typedef struct {
    char ip[16];
    int lines;
} log_entry;

void process_log_line(char *line, log_entry *log_data) {
    char ip[16];
    sscanf(line, "%[^ ] %*s %s", log_data->ip, ip);
    strcpy(log_data->ip, ip);

    if (strcmp(log_data->ip, "*") != 0) {
        log_data->lines++;
    }
}

int main() {
    FILE *log_file;
    log_entry log_data[256];

    log_file = fopen(LOG_FILE, "r");

    if (log_file == NULL) {
        perror("Error opening log file");
        return 1;
    }

    int num_entries = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, log_file) != NULL) {
        if (num_entries >= 256) {
            printf("Error: Too many log entries\n");
            break;
        }

        process_log_line(line, &log_data[num_entries]);
        num_entries++;
    }

    fclose(log_file);

    printf("\n------ LOVE LETTERS ------\n");
    printf("Log analysis report in Romeo and Juliet style:\n\n");

    for (int i = 0; i < num_entries; i++) {
        log_entry *entry = &log_data[i];

        if (strcmp(entry->ip, "*") != 0) {
            int lines = entry->lines;

            if (lines == 1) {
                printf("%s: %d line of love\n", entry->ip, lines);
            } else if (lines > 1 && lines < 11) {
                printf("%s: %d lines of love\n", entry->ip, lines);
            } else {
                printf("%s: %d lines of burning love\n", entry->ip, lines);
            }
        }
    }

    printf("\n------ END OF REPORT ------\n");

    return 0;
}