//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 1024

typedef struct {
    char ip[16];
    char method[8];
    char url[1024];
    int status_code;
} log_entry;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    char line[MAX_LOG_ENTRY_LENGTH];
    while (fgets(line, MAX_LOG_ENTRY_LENGTH, log_file)!= NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Log file is too large.\n");
            fclose(log_file);
            return 1;
        }

        log_entry entry;
        sscanf(line, "%15s %7s %1023s %d", entry.ip, entry.method, entry.url, &entry.status_code);
        strncpy(entry.url, "", sizeof(entry.url));
        log_entries[num_entries++] = entry;
    }

    fclose(log_file);

    printf("Log analysis:\n");
    printf("Total entries: %d\n", num_entries);

    int num_200s = 0;
    int num_404s = 0;

    for (int i = 0; i < num_entries; i++) {
        if (log_entries[i].status_code == 200) {
            num_200s++;
        } else if (log_entries[i].status_code == 404) {
            num_404s++;
        }
    }

    printf("Number of 200 responses: %d\n", num_200s);
    printf("Number of 404 responses: %d\n", num_404s);

    return 0;
}