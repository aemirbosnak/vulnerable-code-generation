//FormAI DATASET v1.0 Category: Log analysis ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

/* A struct to store log data */
typedef struct {
    char date[20];
    char time[20];
    char level[10];
    char message[MAX_LINE];
} Log;

/* Function to read logs from file and parse them into structs */
int parse_logs(char *filename, Log *logs) {
    FILE *file_ptr;
    int n_logs = 0;

    file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        printf("Error opening %s", filename);
        return 0;
    }

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), file_ptr)) {
        /* Remove new line character */
        line[strcspn(line, "\n")] = 0;

        /* Parse log data into struct */
        sscanf(line, "%s %s - %s - %[^\t\n]", logs[n_logs].date, logs[n_logs].time, logs[n_logs].level, logs[n_logs].message);
        n_logs++;
    }

    fclose(file_ptr);
    return n_logs;
}

/* Function to count error and warning logs */
int count_errors_warnings(Log *logs, int n_logs) {
    int count = 0;

    for (int i = 0; i < n_logs; i++) {
        if (strcmp(logs[i].level, "ERROR") == 0 || strcmp(logs[i].level, "WARNING") == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    char filename[] = "example.log";
    Log logs[MAX_LINE];
    int n_logs = 0;

    n_logs = parse_logs(filename, logs);

    printf("Total logs: %d\n", n_logs);
    printf("Error and warning logs: %d\n", count_errors_warnings(logs, n_logs));

    return 0;
}