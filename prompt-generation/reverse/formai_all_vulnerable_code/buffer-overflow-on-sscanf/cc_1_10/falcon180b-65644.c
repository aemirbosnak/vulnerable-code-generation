//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100

struct event {
    time_t timestamp;
    char description[80];
};

int main() {
    int num_events = 0;
    struct event events[MAX_EVENTS];
    char input[80];
    time_t current_time = time(NULL);

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You can travel through time by entering a date and time in the format 'YYYY-MM-DD HH:MM:SS'.\n");
    printf("Type 'quit' to exit the simulator.\n");

    while (1) {
        printf("Enter your command: ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        if (num_events >= MAX_EVENTS) {
            printf("Error: Maximum number of events reached.\n");
            continue;
        }

        struct tm *event_time = NULL;
        event_time = localtime(&current_time);

        if (sscanf(input, "%d-%d-%d %d:%d:%d", &event_time->tm_year, &event_time->tm_mon, &event_time->tm_mday, &event_time->tm_hour, &event_time->tm_min, &event_time->tm_sec)!= 6) {
            printf("Error: Invalid date and time format.\n");
            continue;
        }

        events[num_events].timestamp = mktime(event_time);
        printf("Event added: %s\n", ctime(&events[num_events].timestamp));
        num_events++;
    }

    printf("\nYour time travel itinerary:\n");

    for (int i = 0; i < num_events; i++) {
        printf("%s - %s\n", ctime(&events[i].timestamp), events[i].description);
    }

    return 0;
}