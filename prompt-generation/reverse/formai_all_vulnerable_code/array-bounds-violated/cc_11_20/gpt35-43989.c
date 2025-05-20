//FormAI DATASET v1.0 Category: Log analysis ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

int main(int argc, char** argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *logfile = argv[1];
    FILE *fp = fopen(logfile, "r");
    if (!fp) {
        fprintf(stderr, "Unable to open logfile '%s'\n", logfile);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LOG_SIZE];
    int line_count = 1;

    while (fgets(line, MAX_LOG_SIZE, fp) != NULL) {

        // Strip line of trailing whitespace
        int len = strlen(line) - 1;
        while (isspace(line[len])) {
            line[len] = '\0';
            len--;
        }

        // Check for suspicious keywords
        if (strstr(line, "root") || strstr(line, "sudo") || strstr(line, "password")) {
            printf("WARNING: Suspicious keyword found on line %d\n", line_count);
        }

        // Check for suspicious IP addresses
        char *ip = strstr(line, " DPT=");
        if (ip != NULL) {
            char *end = strchr(ip + 5, ' ');
            if (end == NULL) {
                end = strchr(ip + 5, ':');
            }
            if (end != NULL) {
                *end = '\0';
                if (strstr(ip, "127.0.0.") == NULL && strstr(ip, "192.168.") == NULL) {
                    printf("WARNING: Suspicious IP address '%s' found on line %d\n", ip + 5, line_count);
                }
            }
        }

        // Check for suspicious filenames
        char *filename = strchr(line, ' ');
        if (filename != NULL) {
            filename++;
            if (strstr(filename, "..") || strstr(filename, "~") || strchr(filename, '/')) {
                printf("WARNING: Suspicious filename '%s' found on line %d\n", filename, line_count);
            }
        }

        line_count++;
    }

    fclose(fp);

    return 0;
}