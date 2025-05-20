//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 1000
#define MAX_LINE_LENGTH 1024

typedef struct {
    char *ip;
    char *date;
    char *method;
    char *url;
    int status_code;
} LogEntry;

int main(int argc, char **argv) {
    FILE *fp;
    char log_file[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    LogEntry entry;
    int num_entries = 0;

    printf("Enter the name of the log file: ");
    scanf("%s", log_file);

    fp = fopen(log_file, "r");
    if (fp == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (num_entries >= MAX_LOG_LINES) {
            printf("Error: too many log entries.\n");
            fclose(fp);
            return 1;
        }

        entry.ip = strtok(line, " ");
        entry.date = strtok(NULL, " ");
        entry.method = strtok(NULL, " ");
        entry.url = strtok(NULL, " ");
        entry.status_code = atoi(strtok(NULL, " "));

        printf("IP: %s\n", entry.ip);
        printf("Date: %s\n", entry.date);
        printf("Method: %s\n", entry.method);
        printf("URL: %s\n", entry.url);
        printf("Status Code: %d\n", entry.status_code);
        printf("\n");

        num_entries++;
    }

    fclose(fp);
    return 0;
}