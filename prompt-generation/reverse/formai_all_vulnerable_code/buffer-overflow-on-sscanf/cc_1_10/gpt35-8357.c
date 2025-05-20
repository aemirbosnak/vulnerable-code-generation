//FormAI DATASET v1.0 Category: Log analysis ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LINE_LENGTH 1024

typedef struct {
    char date[20];
    char time[20];
    char message[MAX_LINE_LENGTH];
} log_entry_t;

typedef struct {
    log_entry_t entries[MAX_LOG_ENTRIES];
    int count;
} log_t;

log_t parse_log_file(const char* filename);
void print_log(log_t log);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <logfile>\n", argv[0]);
        return 1;
    }

    const char* log_file = argv[1];

    log_t log = parse_log_file(log_file);

    print_log(log);

    return 0;
}

log_t parse_log_file(const char* filename) {
    FILE* fp;
    char line[MAX_LINE_LENGTH];
    log_t log = { .count = 0 };

    fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        log_entry_t entry = { .date = "", .time = "", .message = "" };

        if (sscanf(line, "%s %s %[^\n]", entry.date, entry.time, entry.message) == 3) {
            if (log.count >= MAX_LOG_ENTRIES) {
                break; // we've reached our maximum number of entries
            }

            log.entries[log.count++] = entry;
        }
    }

    fclose(fp);

    return log;
}

void print_log(log_t log) {
    for (int i = 0; i < log.count; i++) {
        log_entry_t entry = log.entries[i];
        printf("[%s %s] %s\n", entry.date, entry.time, entry.message);
    }
}