//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOG_FILES 10

struct log_entry {
    char ip[16];
    int hits;
};

int main(int argc, char *argv[]) {
    FILE *log_files[MAX_LOG_FILES];
    struct log_entry *log_data;
    int num_logs = 0, i, j;
    char line[MAX_LINE_LENGTH];
    char token[16];
    int ip_index;

    if (argc < 2) {
        printf("Usage: %s <log_file_1> [log_file_2] ...\n", argv[0]);
        return 1;
    }

    log_data = calloc(sizeof(struct log_entry), 256); // Max IP addresses

    for (i = 1; i < argc; i++) {
        log_files[num_logs] = fopen(argv[i], "r");
        if (log_files[num_logs] == NULL) {
            printf("Error: Could not open log file %s\n", argv[i]);
            return 1;
        }
        num_logs++;
    }

    for (i = 0; i < num_logs; i++) {
        while (fgets(line, sizeof(line), log_files[i]) != NULL) {
            sscanf(line, "%s %s %s %s %s %s %s %s %s %s %s",
                   token, token, token, token, token, token, token, token, token, token, token);
            ip_index = 0;
            for (j = 0; j < num_logs && strcmp(token, log_data[j].ip); j++);
            if (j >= num_logs) { // New IP address
                strncpy(log_data[num_logs].ip, token, sizeof(log_data[num_logs].ip) - 1);
                log_data[num_logs++].hits = 1;
            } else { // Existing IP address
                log_data[j].hits++;
            }
        }
    }

    for (i = 0; i < num_logs; i++) {
        printf("%s: %d hits\n", log_data[i].ip, log_data[i].hits);
    }

    for (i = 0; i < num_logs; i++) {
        free(log_files[i]);
    }
    free(log_data);

    return 0;
}