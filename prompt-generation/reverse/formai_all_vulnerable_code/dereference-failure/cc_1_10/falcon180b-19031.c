//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "my_log.txt"
#define MAX_LINE_LENGTH 1024

typedef struct {
    char ip[20];
    char method[10];
    char url[100];
    int status_code;
} log_entry;

void read_log_file(log_entry *entries, int *num_entries) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int i = 0;

    file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (i >= *num_entries) {
            printf("Log file too large. Increase MAX_LINE_LENGTH and try again.\n");
            exit(1);
        }

        sscanf(line, "%s %s %s %d", entries[i].ip, entries[i].method, entries[i].url, &entries[i].status_code);
        i++;
    }

    fclose(file);
}

void print_entries(log_entry *entries, int num_entries) {
    int i;

    for (i = 0; i < num_entries; i++) {
        printf("%s %s %s %d\n", entries[i].ip, entries[i].method, entries[i].url, entries[i].status_code);
    }
}

int main() {
    log_entry entries[1000];
    int num_entries = 0;

    read_log_file(entries, &num_entries);
    print_entries(entries, num_entries);

    return 0;
}