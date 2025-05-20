//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_LINES 1000
#define MAX_LOG_LINE_LENGTH 1024

struct log_line {
    char *timestamp;
    char *ip_address;
    char *request_method;
    char *request_uri;
    int response_code;
};

int compare_log_lines(const void *a, const void *b) {
    struct log_line *log_line_a = (struct log_line *)a;
    struct log_line *log_line_b = (struct log_line *)b;

    if (log_line_a->response_code > log_line_b->response_code) {
        return -1;
    } else if (log_line_a->response_code < log_line_b->response_code) {
        return 1;
    } else {
        return 0;
    }
}

void print_log_lines(struct log_line log_lines[], int num_log_lines) {
    qsort(log_lines, num_log_lines, sizeof(struct log_line), compare_log_lines);

    for (int i = 0; i < num_log_lines; i++) {
        printf("%s %s %s %d\n", log_lines[i].timestamp, log_lines[i].ip_address, log_lines[i].request_method, log_lines[i].response_code);
    }
}

int main() {
    FILE *log_file;
    char log_line[MAX_LOG_LINE_LENGTH];
    struct log_line log_lines[MAX_LOG_LINES];
    int num_log_lines = 0;

    log_file = fopen("access.log", "r");

    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    while (fgets(log_line, MAX_LOG_LINE_LENGTH, log_file)!= NULL) {
        if (num_log_lines >= MAX_LOG_LINES) {
            printf("Maximum number of log lines reached.\n");
            break;
        }

        struct log_line *current_log_line = &log_lines[num_log_lines];

        current_log_line->timestamp = strtok(log_line, " ");
        current_log_line->ip_address = strtok(NULL, " ");
        current_log_line->request_method = strtok(NULL, " ");
        current_log_line->request_uri = strtok(NULL, " ");
        current_log_line->response_code = atoi(strtok(NULL, "\n"));

        num_log_lines++;
    }

    fclose(log_file);

    print_log_lines(log_lines, num_log_lines);

    return 0;
}