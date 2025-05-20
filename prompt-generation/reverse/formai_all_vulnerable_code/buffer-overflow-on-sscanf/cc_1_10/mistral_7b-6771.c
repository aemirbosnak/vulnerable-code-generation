//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define LOG_FILE "post_apocalypse.log"

typedef struct {
    char timestamp[20];
    int severity;
    char message[MAX_LINE_LENGTH];
} log_entry;

void parse_log_entry(char *line, log_entry *entry) {
    sscanf(line, "%s %d %s", entry->timestamp, &entry->severity, entry->message);
}

int main() {
    FILE *log_file;
    log_entry entry;
    char line[MAX_LINE_LENGTH];
    int total_errors = 0;

    log_file = fopen(LOG_FILE, "r");

    if (log_file == NULL) {
        printf("Error: Unable to open log file.\n");
        return 1;
    }

    printf("\n===============\n");
    printf("| Post-Apocalyptic Log Analysis |\n");
    printf("===============\n\n");

    while (fgets(line, MAX_LINE_LENGTH, log_file) != NULL) {
        parse_log_entry(line, &entry);

        if (entry.severity >= 3) {
            printf("%s: [ERROR] %s\n", entry.timestamp, entry.message);
            total_errors++;
        } else {
            printf("%s: [INFO] %s\n", entry.timestamp, entry.message);
        }
    }

    fclose(log_file);

    printf("\n===============\n");
    printf("| Total Errors: %d |\n");
    printf("===============\n");

    return 0;
}