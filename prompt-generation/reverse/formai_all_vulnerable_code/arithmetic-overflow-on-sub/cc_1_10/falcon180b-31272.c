//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_EVENTS 10000

struct event {
    time_t timestamp;
    char *description;
};

int main() {
    struct event events[MAX_EVENTS];
    int num_events = 0;
    time_t current_time = time(NULL);
    int choice;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You have %d events to choose from.\n", num_events);

    while(1) {
        printf("\nEnter your choice:\n");
        printf("1. Travel back in time\n");
        printf("2. Travel forward in time\n");
        printf("3. Add an event\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Traveling back in time...\n");
                current_time -= 3600; // Travel back 1 hour
                break;
            case 2:
                printf("Traveling forward in time...\n");
                current_time += 3600; // Travel forward 1 hour
                break;
            case 3:
                if(num_events >= MAX_EVENTS) {
                    printf("Sorry, you cannot add any more events.\n");
                    break;
                }
                printf("Enter the event description:\n");
                scanf("%s", events[num_events].description);
                events[num_events].timestamp = current_time;
                num_events++;
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        printf("\nCurrent time: %s", ctime(&current_time));

        for(int i=0; i<num_events; i++) {
            if(difftime(current_time, events[i].timestamp) == 0) {
                printf("\nEvent: %s\n", events[i].description);
            }
        }
    }

    return 0;
}