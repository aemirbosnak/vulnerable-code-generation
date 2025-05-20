//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENT 100
#define MAX_TIME 1000

typedef struct {
    int time;
    char event[50];
} Event;

int main() {
    int num_events;
    Event events[MAX_EVENT];
    char choice;
    int i;

    srand(time(NULL));
    num_events = rand() % 10 + 1;

    printf("Enter the number of events (1-10): ");
    scanf("%d", &num_events);

    for (i = 0; i < num_events; i++) {
        events[i].time = rand() % MAX_TIME;
        printf("Enter event %d: ", i+1);
        scanf("%s", events[i].event);
    }

    printf("\nEnter's' to start the simulation.\n");
    scanf(" %c", &choice);

    if (choice =='s') {
        int current_time = 0;
        while (current_time < MAX_TIME) {
            printf("\nCurrent time: %d\n", current_time);

            for (i = 0; i < num_events; i++) {
                if (events[i].time == current_time) {
                    printf("\nEvent %d: %s\n", i+1, events[i].event);
                }
            }

            printf("Enter 'n' to continue or 'q' to quit.\n");
            scanf(" %c", &choice);

            if (choice == 'q') {
                break;
            }

            current_time++;
        }
    } else {
        printf("Invalid choice. Exiting program.\n");
    }

    return 0;
}