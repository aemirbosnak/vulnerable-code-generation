//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define NUM_FIELDS 5

typedef struct {
    char ip[16];
    int status;
    char method[8];
    char path[256];
    char user_agent[128];
} log_entry;

void process_line(char *line) {
    log_entry entry;
    sscanf(line, "%s %s %s %s %s %s", entry.ip, entry.method, entry.path, &entry.status, entry.user_agent, NULL);

    // Process the log entry here

    if (entry.status >= 400) {
        printf("ERROR: Request with status %d from IP %s\n", entry.status, entry.ip);
    }

    if (strcmp(entry.method, "GET") == 0) {
        printf("INFO: GET request from IP %s to %s\n", entry.ip, entry.path);
    }
}

int main(int argc, char *argv[]) {
    FILE *log_file;
    char line[MAX_LINE_LENGTH];

    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    log_file = fopen(argv[1], "r");

    if (log_file == NULL) {
        perror("Error opening log file");
        return 1;
    }

    while (fgets(line, sizeof(line), log_file) != NULL) {
        process_line(line);
    }

    fclose(log_file);

    return 0;
}