//FormAI DATASET v1.0 Category: System event logger ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 1000

typedef struct {
    char date[20];
    char time[20];
    char event[100];
} EventLog;

void add_event(EventLog *log, char *event) {
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(log->date, 20, "%Y-%m-%d", timeinfo);
    strftime(log->time, 20, "%H:%M:%S", timeinfo);
    strcpy(log->event, event);
}

void print_log(EventLog *log) {
    printf("Date\tTime\t\tEvent\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < MAX_EVENTS; i++) {
        if (log[i].date[0] == '\0') break;
        printf("%s\t%s\t%s\n", log[i].date, log[i].time, log[i].event);
    }
}

int main() {
    EventLog log[MAX_EVENTS];
    char input[100];
    int index = 0;

    printf("Welcome to the C System Event Logger! Type 'exit' to quit.\n");

    while (1) {
        printf("> ");
        fgets(input, 100, stdin);
        input[strlen(input)-1] = '\0';

        if (strcmp(input, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }

        add_event(&log[index], input);
        index++;

        if (index >= MAX_EVENTS) {
            printf("Maximum number of events reached.\n");
            break;
        }
    }

    print_log(log);

    return 0;
}