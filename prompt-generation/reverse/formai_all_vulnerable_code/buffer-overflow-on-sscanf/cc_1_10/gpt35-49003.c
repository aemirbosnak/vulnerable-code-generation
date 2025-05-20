//FormAI DATASET v1.0 Category: Log analysis ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_LINES 500
#define MAX_LINE_LENGTH 200

typedef struct {
    char date[20];
    char time[20];
    char message[MAX_LINE_LENGTH];
} LogLine;

int main() {
    FILE *log_file;
    char log_line[MAX_LINE_LENGTH];
    int line_count = 0;
    LogLine log_lines[MAX_LOG_LINES];

    // open the log file
    log_file = fopen("server.log", "r");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    // read the log file line by line
    while (fgets(log_line, MAX_LINE_LENGTH, log_file) != NULL && line_count < MAX_LOG_LINES) {
        // parse the log line into its components and add it to the array
        sscanf(log_line, "%s %s %[^\n]", log_lines[line_count].date, log_lines[line_count].time, log_lines[line_count].message);
        line_count++;
    }

    // close the log file
    fclose(log_file);

    // print the number of log entries
    printf("Number of log entries: %d\n", line_count);

    // print the first and last log entries
    printf("First log entry: %s %s %s\n", log_lines[0].date, log_lines[0].time, log_lines[0].message);
    printf("Last log entry: %s %s %s\n", log_lines[line_count-1].date, log_lines[line_count-1].time, log_lines[line_count-1].message);

    // search for log entries containing a specific keyword
    char keyword[MAX_LINE_LENGTH];
    printf("Enter keyword to search for: ");
    scanf("%s", keyword);
    printf("Log entries containing '%s':\n", keyword);
    for (int i = 0; i < line_count; i++) {
        if (strstr(log_lines[i].message, keyword) != NULL) {
            printf("%s %s %s\n", log_lines[i].date, log_lines[i].time, log_lines[i].message);
        }
    }

    return 0;
}