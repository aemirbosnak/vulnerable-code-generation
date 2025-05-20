//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char ip[16];
    char user_agent[256];
    char request_url[1024];
    int status_code;
    time_t timestamp;
} LogEntry;

int compare_timestamps(const void *a, const void *b) {
    const struct tm *tm_a = localtime(&((LogEntry *)a)->timestamp);
    const struct tm *tm_b = localtime(&((LogEntry *)b)->timestamp);
    return tm_a->tm_hour * 60 + tm_a->tm_min - tm_b->tm_hour * 60 - tm_b->tm_min;
}

int main() {
    FILE *log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }

    LogEntry log_entries[MAX_NUM_LINES];
    int num_entries = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        if (num_entries >= MAX_NUM_LINES) {
            printf("Error: maximum number of log entries reached.\n");
            break;
        }

        char *tokens[7];
        int num_tokens = sscanf(line, "%15s %15s %15s %d %*s %*s %*s", tokens[0], tokens[1], tokens[2], &log_entries[num_entries].status_code);
        if (num_tokens!= 4) {
            printf("Error: invalid log entry format.\n");
            continue;
        }

        strncpy(log_entries[num_entries].ip, tokens[0], 16);
        strncpy(log_entries[num_entries].user_agent, tokens[1], 256);
        strncpy(log_entries[num_entries].request_url, tokens[2], 1024);
        log_entries[num_entries].timestamp = time(NULL);
        num_entries++;
    }

    fclose(log_file);

    qsort(log_entries, num_entries, sizeof(LogEntry), compare_timestamps);

    for (int i = 0; i < num_entries; i++) {
        printf("%s %s %s %d\n", log_entries[i].ip, log_entries[i].user_agent, log_entries[i].request_url, log_entries[i].status_code);
    }

    return 0;
}