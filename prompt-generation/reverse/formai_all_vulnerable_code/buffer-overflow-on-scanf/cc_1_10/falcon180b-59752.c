//Falcon-180B DATASET v1.0 Category: System event logger ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

struct event_t {
    char message[100];
    time_t timestamp;
};

int main(void) {
    FILE *log_file;
    char log_filename[30];
    int event_count = 0;
    struct event_t events[MAX_EVENTS];

    printf("Welcome to the Happy Event Logger!\n");
    printf("Please enter the name of the log file: ");
    scanf("%s", log_filename);

    log_file = fopen(log_filename, "w");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    while (1) {
        printf("\nEnter an event (or type 'quit' to exit): ");
        fflush(stdin);
        scanf("%s", events[event_count].message);

        if (strcmp(events[event_count].message, "quit") == 0) {
            break;
        }

        time(&events[event_count].timestamp);
        fprintf(log_file, "%s - %s\n", events[event_count].message, ctime(&events[event_count].timestamp));
        event_count++;

        if (event_count >= MAX_EVENTS) {
            printf("\nLog file is full. Please start a new log.\n");
            break;
        }
    }

    fclose(log_file);
    printf("\nEvent logging complete!\n");

    return 0;
}