//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 256

typedef struct {
    char ip[16];
    char date[32];
    char request[MAX_LOG_ENTRY_LENGTH];
    int response_code;
} LogEntry;

int main() {
    FILE *logfile;
    LogEntry log[MAX_LOG_ENTRIES];
    int num_entries = 0;

    logfile = fopen("example.log", "r");
    if (logfile == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    while (fscanf(logfile, "%s %s %s %d\n", log[num_entries].ip, log[num_entries].date, log[num_entries].request, &log[num_entries].response_code)!= EOF) {
        num_entries++;
        if (num_entries == MAX_LOG_ENTRIES) {
            break;
        }
    }

    fclose(logfile);

    printf("Log Analysis:\n");
    printf("Total entries: %d\n", num_entries);

    int num_404s = 0;
    int num_500s = 0;

    for (int i = 0; i < num_entries; i++) {
        if (log[i].response_code == 404) {
            num_404s++;
        } else if (log[i].response_code == 500) {
            num_500s++;
        }
    }

    printf("404s: %d\n", num_404s);
    printf("500s: %d\n", num_500s);

    return 0;
}