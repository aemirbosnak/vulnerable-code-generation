//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LOG_ENTRIES 10000
#define MAX_LOG_ENTRY_SIZE 2048

typedef struct {
    char ip[16];
    char user_agent[256];
    char url[512];
    char method[8];
    int status_code;
    time_t timestamp;
} log_entry;

log_entry log_entries[MAX_LOG_ENTRIES];
int num_entries = 0;

void parse_log_entry(const char* log_line) {
    char* token;
    log_entry* entry = &log_entries[num_entries];
    num_entries++;

    token = strtok(log_line, " ");
    strncpy(entry->ip, token, sizeof(entry->ip));

    token = strtok(NULL, " ");
    strncpy(entry->user_agent, token, sizeof(entry->user_agent));

    token = strtok(NULL, " ");
    strncpy(entry->url, token, sizeof(entry->url));

    token = strtok(NULL, " ");
    strncpy(entry->method, token, sizeof(entry->method));

    entry->status_code = atoi(strtok(NULL, " "));
    entry->timestamp = time(NULL);
}

void print_log_entries() {
    int i;

    printf("IP\tUser Agent\tURL\tMethod\tStatus Code\tTimestamp\n");
    for (i = 0; i < num_entries; i++) {
        printf("%-15s %-30s %-40s %-8s %d %s\n",
               log_entries[i].ip,
               log_entries[i].user_agent,
               log_entries[i].url,
               log_entries[i].method,
               log_entries[i].status_code,
               ctime(&log_entries[i].timestamp));
    }
}

int main() {
    FILE* log_file;
    char log_line[MAX_LOG_ENTRY_SIZE];
    int line_count = 0;

    log_file = fopen("access.log", "r");

    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    while (fgets(log_line, sizeof(log_line), log_file)) {
        if (line_count >= MAX_LOG_ENTRIES) {
            printf("Maximum number of log entries reached.\n");
            break;
        }

        parse_log_entry(log_line);
        line_count++;
    }

    fclose(log_file);

    printf("Number of log entries: %d\n", num_entries);
    print_log_entries();

    return 0;
}