//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 10000
#define MAX_LINE_LENGTH 1024

typedef struct {
    char ip[16];
    char date_time[26];
    char request[MAX_LINE_LENGTH];
    char status_code[4];
    int bytes_sent;
} log_entry;

log_entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *ip, char *date_time, char *request, char *status_code, int bytes_sent) {
    strcpy(entries[num_entries].ip, ip);
    strcpy(entries[num_entries].date_time, date_time);
    strcpy(entries[num_entries].request, request);
    strcpy(entries[num_entries].status_code, status_code);
    entries[num_entries].bytes_sent = bytes_sent;

    num_entries++;
}

void print_entries() {
    printf("IP\tDate/Time\tRequest\tStatus Code\tBytes Sent\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%-15s", entries[i].ip);
        printf("%-25s", entries[i].date_time);
        printf("%-40s", entries[i].request);
        printf("%-10s", entries[i].status_code);
        printf("%d\n", entries[i].bytes_sent);
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char ip[16];
    char date_time[26];
    char request[MAX_LINE_LENGTH];
    char status_code[4];
    int bytes_sent;

    fp = fopen("access.log", "r");

    if (fp == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        sscanf(line, "%s %s %s %s %d", ip, date_time, request, status_code, &bytes_sent);

        add_entry(ip, date_time, request, status_code, bytes_sent);
    }

    fclose(fp);

    print_entries();

    return 0;
}