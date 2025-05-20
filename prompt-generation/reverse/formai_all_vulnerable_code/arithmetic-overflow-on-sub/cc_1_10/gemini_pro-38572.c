//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <log file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = '\0';

        // Compile regular expression
        regex_t regex;
        int rc = regcomp(&regex, "^[0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2} ([A-Z]+) (.*)$", REG_EXTENDED);
        if (rc != 0) {
            char error_buffer[1024];
            regerror(rc, &regex, error_buffer, sizeof(error_buffer));
            fprintf(stderr, "regcomp: %s\n", error_buffer);
            return EXIT_FAILURE;
        }

        // Match regular expression
        regmatch_t matches[2];
        rc = regexec(&regex, line, 2, matches, 0);
        if (rc == 0) {
            // Extract log level and message
            char log_level[10];
            strncpy(log_level, line + matches[1].rm_so, matches[1].rm_eo - matches[1].rm_so);
            log_level[matches[1].rm_eo - matches[1].rm_so] = '\0';

            char message[MAX_LINE_LENGTH];
            strncpy(message, line + matches[2].rm_so, matches[2].rm_eo - matches[2].rm_so);
            message[matches[2].rm_eo - matches[2].rm_so] = '\0';

            // Print log level and message
            printf("%s: %s\n", log_level, message);
        }

        // Free regular expression
        regfree(&regex);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}