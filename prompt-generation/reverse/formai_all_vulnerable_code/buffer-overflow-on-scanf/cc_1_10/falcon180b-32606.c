//Falcon-180B DATASET v1.0 Category: System event logger ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_EVENT_LENGTH 100

struct event {
    char message[MAX_EVENT_LENGTH];
    time_t timestamp;
};

int main() {
    FILE *log_file;
    struct event events[MAX_EVENTS];
    int num_events = 0;
    char filename[MAX_EVENT_LENGTH];
    char input[MAX_EVENT_LENGTH];
    time_t current_time;

    printf("Enter log file name: ");
    scanf("%s", filename);

    log_file = fopen(filename, "a");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    while (num_events < MAX_EVENTS) {
        printf("Enter event message: ");
        scanf("%s", input);

        if (strlen(input) >= MAX_EVENT_LENGTH) {
            printf("Event message too long.\n");
            continue;
        }

        strcpy(events[num_events].message, input);
        current_time = time(NULL);
        events[num_events].timestamp = current_time;
        num_events++;

        fprintf(log_file, "%.24s: %s\n", ctime(&current_time), events[num_events - 1].message);
    }

    fclose(log_file);

    printf("Log file created successfully.\n");
    return 0;
}