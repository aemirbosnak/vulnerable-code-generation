//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE 1024
#define LOG_FILE "access.log"

typedef struct {
    char ip[16];
    int requests;
    int bytes;
} LogStats;

void parse_log_line(char *line, LogStats *stats) {
    char ip_str[16];
    int index;

    sscanf(line, "%s %ld %ld %s %s %s %s %s %s %s %s %s %s",
           ip_str, &stats->requests, &stats->bytes,
           &index, &index, &index, &index, &index, &index, &index, &index, &index, &index);

    strncpy(stats->ip, ip_str, sizeof(stats->ip));
}

LogStats *read_log_file(FILE *file) {
    LogStats *stats = calloc(1, sizeof(LogStats));
    char line[MAX_LINE];

    while (fgets(line, sizeof(line), file)) {
        LogStats tmp;
        parse_log_line(line, &tmp);

        if (strcmp(stats->ip, tmp.ip) != 0) {
            if (stats->requests > 0) {
                printf("%s: %d requests, %d bytes\n", stats->ip, stats->requests, stats->bytes);
                free(stats);
                stats = calloc(1, sizeof(LogStats));
                strcpy(stats->ip, tmp.ip);
                stats->requests = tmp.requests;
                stats->bytes = tmp.bytes;
            }
        } else {
            stats->requests += tmp.requests;
            stats->bytes += tmp.bytes;
        }
    }

    if (stats->requests > 0) {
        printf("%s: %d requests, %d bytes\n", stats->ip, stats->requests, stats->bytes);
        free(stats);
    }

    fclose(file);
    return NULL;
}

int main() {
    FILE *file = fopen(LOG_FILE, "r");

    if (!file) {
        perror("Error opening log file");
        return 1;
    }

    read_log_file(file);
    fclose(file);

    return 0;
}