//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define NUM_FIELDS 6

typedef struct {
    char ip[16];
    int status;
    char method[8];
    char path[256];
    char user[16];
    char timestamp[20];
} LogEntry;

void parse_log_line(char* line, LogEntry* entry) {
    sscanf(line, "%s %s %s %s %s %s", entry->ip, entry->method, entry->path, entry->user, entry->timestamp, &entry->status);
}

int main() {
    FILE* log_file = fopen("server.log", "r");
    if (log_file == NULL) {
        perror("Error opening log file");
        exit(1);
    }

    LogEntry current_entry;
    int total_status_code_count[3] = {0};

    while (fgets(current_entry.path, MAX_LINE_LENGTH, log_file) != NULL) {
        memset(&current_entry, 0, sizeof(LogEntry));
        parse_log_line(current_entry.path, &current_entry);

        if (strcmp(current_entry.method, "GET") == 0) {
            total_status_code_count[current_entry.status / 100]++;
        }
    }

    fclose(log_file);

    printf("\nStatus code distribution:\n");
    printf("---------------------------\n");
    printf("| Status code | Count |\n");
    printf("---------------------------\n");
    for (int i = 0; i < NUM_FIELDS; i++) {
        printf("| %2dxx | %5d |\n", i * 100, total_status_code_count[i]);
    }

    return 0;
}