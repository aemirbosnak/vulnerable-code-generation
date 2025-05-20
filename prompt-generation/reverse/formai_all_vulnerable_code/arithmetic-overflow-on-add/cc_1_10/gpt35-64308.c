//FormAI DATASET v1.0 Category: System event logger ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENT 100

void log_event(char* event);
void print_log();

char events[MAX_EVENT][50];
int event_count = 0;

int main() {

    int option;
    char event[50];

    do {
        printf("\nEnter an option:\n");
        printf("1- Log an event\n");
        printf("2- Print log\n");
        printf("3- Quit\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter event description(less than 50 chars): ");
                scanf("%s", event);
                log_event(event);
                break;
            case 2:
                print_log();
                break;
            case 3:
                printf("\nBye!\n");
                break;
            default:
                printf("\nInvalid option. Try again.\n");
                break;
        }

    } while(option != 3);

    return 0;
}

void log_event(char* event) {
    if(event_count < MAX_EVENT) {
        time_t t = time(NULL);
        struct tm* timeptr = localtime(&t);
        sprintf(events[event_count], "%.2d/%.2d/%d %.2d:%.2d:%.2d - %s", timeptr->tm_mday, 
                                                                     timeptr->tm_mon + 1,
                                                                     timeptr->tm_year + 1900,
                                                                     timeptr->tm_hour,
                                                                     timeptr->tm_min,
                                                                     timeptr->tm_sec,
                                                                     event);
        printf("\nEvent logged successfully.\n");
        event_count++;
    } else {
        printf("\nLog is full. Can't log new events.\n");
    }
}

void print_log() {
    if(event_count == 0) {
        printf("\nLog is empty.\n");
    } else {
        printf("\nLog:\n");
        for(int i = 0; i < event_count; i++) {
            printf("%s\n", events[i]);
        }
    }
}