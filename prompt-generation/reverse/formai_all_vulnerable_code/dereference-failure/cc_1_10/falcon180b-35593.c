//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_SIZE 256

typedef struct {
    char ip[16];
    char date[20];
    char time[8];
    char method[10];
    char url[100];
    int status_code;
} log_entry;

int main() {
    FILE *log_file;
    char log_buffer[MAX_LOG_ENTRY_SIZE];
    log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("Error opening log file\n");
        exit(1);
    }

    while (fgets(log_buffer, MAX_LOG_ENTRY_SIZE, log_file)!= NULL) {
        log_entry entry;
        char *token = strtok(log_buffer, " ");
        strncpy(entry.ip, token, 16);
        token = strtok(NULL, " ");
        strncpy(entry.date, token, 20);
        token = strtok(NULL, " ");
        strncpy(entry.time, token, 8);
        token = strtok(NULL, " ");
        strncpy(entry.method, token, 10);
        token = strtok(NULL, " ");
        strncpy(entry.url, token, 100);
        entry.status_code = atoi(strtok(NULL, " "));
        log_entries[num_entries++] = entry;
    }

    fclose(log_file);

    printf("Number of entries: %d\n", num_entries);
    printf("IP\tDate\tTime\tMethod\tURL\tStatus Code\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\t%s\t%s\t%s\t%d\n", log_entries[i].ip, log_entries[i].date, log_entries[i].time, log_entries[i].method, log_entries[i].url, log_entries[i].status_code);
    }

    return 0;
}