//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 1000
#define MAX_WORD_LENGTH 50

struct log_entry {
    char ip[MAX_WORD_LENGTH];
    char request[MAX_WORD_LENGTH];
    int status_code;
};

int compare_log_entries(const void *a, const void *b) {
    const struct log_entry *entry_a = (const struct log_entry *)a;
    const struct log_entry *entry_b = (const struct log_entry *)b;

    if (entry_a->status_code > entry_b->status_code) {
        return -1;
    } else if (entry_a->status_code < entry_b->status_code) {
        return 1;
    } else {
        return 0;
    }
}

void print_log_entries(struct log_entry entries[], int num_entries) {
    qsort(entries, num_entries, sizeof(struct log_entry), compare_log_entries);

    for (int i = 0; i < num_entries; i++) {
        printf("%s %s %d\n", entries[i].ip, entries[i].request, entries[i].status_code);
    }
}

int main() {
    FILE *log_file = fopen("logfile.txt", "r");

    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    char line[MAX_WORD_LENGTH];
    struct log_entry entries[MAX_LOG_LINES];
    int num_entries = 0;

    while (fgets(line, MAX_WORD_LENGTH, log_file)!= NULL) {
        char *token = strtok(line, " ");
        strcpy(entries[num_entries].ip, token);

        token = strtok(NULL, " ");
        strcpy(entries[num_entries].request, token);

        token = strtok(NULL, " ");
        entries[num_entries].status_code = atoi(token);

        num_entries++;

        if (num_entries >= MAX_LOG_LINES) {
            break;
        }
    }

    fclose(log_file);

    print_log_entries(entries, num_entries);

    return 0;
}