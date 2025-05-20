//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char logfile[100];
    FILE *fp;

    printf("Enter the log file name: ");
    scanf("%s", logfile);

    fp = fopen(logfile, "r");
    if (fp == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    int count = 0;
    int total_requests = 0;
    int total_errors = 0;
    int total_pageviews = 0;

    while (!feof(fp)) {
        char line[100];
        int line_length = fread(line, 1, sizeof(line), fp);

        if (line_length <= 0)
            break;

        char *tokens[4];
        strtok(line, " ");
        strtok(NULL, " ");
        strtok(NULL, " ");
        strtok(NULL, " ");

        tokens[0] = strtok(NULL, " ");
        tokens[1] = strtok(NULL, " ");
        tokens[2] = strtok(NULL, " ");
        tokens[3] = strtok(NULL, " ");

        if (strcmp(tokens[0], "GET") == 0) {
            total_requests++;
        } else if (strcmp(tokens[0], "POST") == 0) {
            total_pageviews++;
        } else if (strcmp(tokens[0], "ERROR") == 0) {
            total_errors++;
        }
    }

    fclose(fp);

    printf("Total requests: %d\n", total_requests);
    printf("Total pageviews: %d\n", total_pageviews);
    printf("Total errors: %d\n", total_errors);

    return 0;
}