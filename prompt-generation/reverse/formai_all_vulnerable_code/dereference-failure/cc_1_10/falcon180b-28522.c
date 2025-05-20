//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LOG_LINES 1000
#define MAX_WORD_LENGTH 50

struct log_entry {
    char date[20];
    char time[10];
    char ip[20];
    char url[100];
    char user_agent[100];
};

void read_log_file(char *filename, struct log_entry entries[], int *num_entries) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open log file.\n");
        exit(1);
    }

    char line[MAX_LOG_LINES];
    int line_num = 0;

    *num_entries = 0;

    while (fgets(line, MAX_LOG_LINES, fp)!= NULL) {
        if (line_num >= MAX_LOG_LINES) {
            printf("Error: log file is too large.\n");
            exit(1);
        }

        char *date_time = strtok(line, " ");
        strncpy(entries[*num_entries].date, date_time, 19);
        entries[*num_entries].date[19] = '\0';

        char *ip_address = strtok(NULL, " ");
        strncpy(entries[*num_entries].ip, ip_address, 19);
        entries[*num_entries].ip[19] = '\0';

        char *url = strtok(NULL, " ");
        strncpy(entries[*num_entries].url, url, 99);
        entries[*num_entries].url[99] = '\0';

        char *user_agent = strtok(NULL, " ");
        strncpy(entries[*num_entries].user_agent, user_agent, 99);
        entries[*num_entries].user_agent[99] = '\0';

        (*num_entries)++;
        line_num++;
    }

    fclose(fp);
}

void print_log_entries(struct log_entry entries[], int num_entries) {
    printf("Date/Time\tIP Address\tURL\tUser Agent\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\t%s\t%s\n", entries[i].date, entries[i].ip, entries[i].url, entries[i].user_agent);
    }
}

int main() {
    struct log_entry entries[MAX_LOG_LINES];
    int num_entries = 0;

    read_log_file("logfile.txt", entries, &num_entries);

    printf("Number of log entries: %d\n", num_entries);
    print_log_entries(entries, num_entries);

    return 0;
}