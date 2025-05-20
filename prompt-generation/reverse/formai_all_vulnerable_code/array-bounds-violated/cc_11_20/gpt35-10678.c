//FormAI DATASET v1.0 Category: Log analysis ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // check if correct number of arguments are provided
    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    int total_requests = 0, successful_requests = 0;
    int status_codes[6] = {0}; // 2xx, 3xx, 4xx and 5xx status codes

    while ((nread = getline(&line, &len, log_file)) != -1) {
        // parse the status code from the log entry
        char *tokens[10], *status_code_str;
        int token_count = 0;
        tokens[token_count] = strtok(line, " ");
        while (tokens[token_count] != NULL && token_count < 10) {
            token_count++;
            tokens[token_count] = strtok(NULL, " ");
        }
        status_code_str = tokens[token_count - 2];

        // convert the status code string to int
        int status_code = atoi(status_code_str);

        // increment the counters based on status code
        if (status_code >= 200 && status_code < 300) {
            successful_requests++;
            status_codes[0]++;
        } else if (status_code >= 300 && status_code < 400) {
            successful_requests++;
            status_codes[1]++;
        } else if (status_code >= 400 && status_code < 500) {
            status_codes[2]++;
        } else if (status_code >= 500 && status_code < 600) {
            status_codes[3]++;
        } else {
            status_codes[4]++;
        }
        total_requests++;
    }

    // print the summary
    printf("Total Requests: %d\n", total_requests);
    printf("Successful Requests: %d (%.2f%%)\n", successful_requests, (float) successful_requests / total_requests * 100);
    printf("2xx Status Codes: %d (%.2f%%)\n", status_codes[0], (float) status_codes[0] / total_requests * 100);
    printf("3xx Status Codes: %d (%.2f%%)\n", status_codes[1], (float) status_codes[1] / total_requests * 100);
    printf("4xx Status Codes: %d (%.2f%%)\n", status_codes[2], (float) status_codes[2] / total_requests * 100);
    printf("5xx Status Codes: %d (%.2f%%)\n", status_codes[3], (float) status_codes[3] / total_requests * 100);
    printf("Other Status Codes: %d (%.2f%%)\n", status_codes[4], (float) status_codes[4] / total_requests * 100);

    // free the memory and close the file
    if (line) {
        free(line);
    }
    fclose(log_file);

    return 0;
}