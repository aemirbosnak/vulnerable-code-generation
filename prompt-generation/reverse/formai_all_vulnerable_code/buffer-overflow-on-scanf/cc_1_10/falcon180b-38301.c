//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENT_LENGTH 80

typedef struct {
    time_t time;
    char message[MAX_EVENT_LENGTH];
} Event;

int main(int argc, char *argv[]) {
    srand(time(NULL));

    Event events[MAX_EVENTS];
    int num_events = 0;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter your name: ");
    scanf("%s", events[num_events].message);
    events[num_events].time = time(NULL);
    num_events++;

    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Travel back in time\n");
        printf("2. Travel forward in time\n");
        printf("3. View timeline\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_events > 1) {
                    int index = rand() % num_events;
                    events[index].time -= 3600; // Travel back 1 hour
                    printf("\nYou have traveled back in time to %s!\n", ctime(&events[index].time));
                } else {
                    printf("You cannot travel back any further.\n");
                }
                break;
            case 2:
                if (num_events > 1) {
                    int index = rand() % num_events;
                    events[index].time += 3600; // Travel forward 1 hour
                    printf("\nYou have traveled forward in time to %s!\n", ctime(&events[index].time));
                } else {
                    printf("You cannot travel forward any further.\n");
                }
                break;
            case 3:
                printf("\nTimeline:\n");
                for (int i = 0; i < num_events; i++) {
                    printf("%s - %s\n", ctime(&events[i].time), events[i].message);
                }
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        if (choice!= 4) {
            printf("\nEnter a message to record this event: ");
            scanf("%s", events[num_events].message);
            events[num_events].time = time(NULL);
            num_events++;
        }
    } while (choice!= 4);

    return 0;
}