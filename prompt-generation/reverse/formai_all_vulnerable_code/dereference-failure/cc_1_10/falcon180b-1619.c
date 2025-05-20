//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 1000
#define MAX_LINE_LENGTH 1024

typedef struct {
    char *ip;
    char *date;
    char *time;
    char *request;
    int status_code;
} LogEntry;

LogEntry entries[MAX_LOG_LINES];
int num_entries = 0;

void parse_log_line(char *line) {
    char *ip_start = strstr(line, " ");
    char *date_start = strstr(line, "[");
    char *time_start = strstr(line, ":");
    char *request_start = strstr(line, " ");
    char *status_code_start = strstr(line, " ");

    if (num_entries >= MAX_LOG_LINES) {
        printf("Error: Log file too large\n");
        exit(1);
    }

    entries[num_entries].ip = malloc(strlen(ip_start) + 1);
    strcpy(entries[num_entries].ip, ip_start);

    entries[num_entries].date = malloc(strlen(date_start) + 1);
    strcpy(entries[num_entries].date, date_start);

    entries[num_entries].time = malloc(strlen(time_start) + 1);
    strcpy(entries[num_entries].time, time_start);

    entries[num_entries].request = malloc(strlen(request_start) + 1);
    strcpy(entries[num_entries].request, request_start);

    entries[num_entries].status_code = atoi(status_code_start);

    num_entries++;
}

void print_entries() {
    printf("IP\tDate\tTime\tRequest\tStatus Code\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\t%s\t%s\t%d\n", entries[i].ip, entries[i].date, entries[i].time, entries[i].request, entries[i].status_code);
    }
}

int main() {
    FILE *log_file;
    char line[MAX_LINE_LENGTH];

    log_file = fopen("logfile.txt", "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        parse_log_line(line);
    }

    fclose(log_file);
    print_entries();

    return 0;
}