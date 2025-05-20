//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_LINE_LENGTH 1000

typedef struct {
    char ip[16];
    char date[20];
    char method[10];
    char url[100];
    int status_code;
} log_entry_t;

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    log_entry_t entries[MAX_ENTRIES];
    int num_entries = 0;

    fp = fopen("access.log", "r");
    if (fp == NULL) {
        printf("Error: could not open access.log\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, " ");
        strcpy(entries[num_entries].ip, token);
        token = strtok(NULL, " ");
        strcpy(entries[num_entries].date, token);
        token = strtok(NULL, " ");
        strcpy(entries[num_entries].method, token);
        token = strtok(NULL, " ");
        strcpy(entries[num_entries].url, token);
        entries[num_entries].status_code = atoi(token);
        num_entries++;
        if (num_entries == MAX_ENTRIES) {
            break;
        }
    }

    fclose(fp);

    // Sort entries by status code
    for (int i = 0; i < num_entries - 1; i++) {
        for (int j = i + 1; j < num_entries; j++) {
            if (entries[i].status_code > entries[j].status_code) {
                log_entry_t temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }

    // Print entries
    printf("IP Address\tDate\tMethod\tURL\tStatus Code\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\t%s\t%s\t%d\n", entries[i].ip, entries[i].date, entries[i].method, entries[i].url, entries[i].status_code);
    }

    return 0;
}