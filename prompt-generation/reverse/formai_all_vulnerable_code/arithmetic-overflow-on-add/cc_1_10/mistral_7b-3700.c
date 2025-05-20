//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_LENGTH 4096
#define DELIMITER ":"

struct log_entry {
    char method[8];
    char uri[32];
    char protocol[8];
    int status_code;
    long long request_time;
};

int main() {
    FILE *log_file;
    char line[LINE_LENGTH];
    int total_requests = 0;
    int successful_requests = 0;
    int failed_requests = 0;
    long long total_response_time = 0;

    log_file = fopen("clog.txt", "r");

    if (log_file == NULL) {
        perror("Error opening log file");
        return 1;
    }

    while (fgets(line, LINE_LENGTH, log_file)) {
        struct log_entry entry;
        char *token;

        sscanf(line, "%s %s %s %s %s %lld %d",
            entry.method, sizeof(entry.method),
            entry.uri, sizeof(entry.uri),
            entry.protocol, sizeof(entry.protocol),
            &entry.request_time,
            &entry.status_code);

        total_requests++;

        if (entry.status_code >= 200 && entry.status_code < 300) {
            successful_requests++;
            total_response_time += entry.request_time;
        } else {
            failed_requests++;
        }
    }

    fclose(log_file);

    printf("\nStatistics for CLog:\n");
    printf("------------------------\n");
    printf("Total number of requests: %d\n", total_requests);
    printf("Number of successful requests: %d\n", successful_requests);
    printf("Number of failed requests: %d\n", failed_requests);
    printf("Average response time: %.2f ms\n", (total_response_time / (double)total_requests));

    return 0;
}