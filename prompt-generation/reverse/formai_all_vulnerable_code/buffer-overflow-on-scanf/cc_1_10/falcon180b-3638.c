//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME 1000000000
#define MAX_EVENTS 1000
#define MAX_EVENT_LEN 100

typedef struct event {
    int time;
    char description[MAX_EVENT_LEN];
} Event;

int main() {
    srand(time(NULL));

    Event events[MAX_EVENTS];
    int num_events = 0;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You are about to embark on a journey through time.\n");
    printf("Please enter your name:\n");
    char name[MAX_EVENT_LEN];
    scanf("%s", name);

    printf("You are now entering the time machine...\n");
    printf("3...\n");
    printf("2...\n");
    printf("1...\n");
    printf("Blastoff!\n");

    int current_time = rand() % MAX_TIME;

    while (current_time < MAX_TIME) {
        if (num_events == MAX_EVENTS) {
            printf("You have reached the end of time.\n");
            break;
        }

        printf("Year %d:\n", current_time);

        int event_time = rand() % MAX_TIME;
        while (event_time < current_time) {
            event_time += rand() % 100000;
        }

        if (event_time - current_time < 1000000) {
            printf("In %d years, you will witness ", event_time - current_time);
        } else if (event_time - current_time < 10000000) {
            printf("In %d decades, you will witness ", (event_time - current_time) / 1000000);
        } else {
            printf("In %d centuries, you will witness ", (event_time - current_time) / 100000000);
        }

        switch (rand() % 3) {
            case 0:
                printf("a great technological advancement.\n");
                break;
            case 1:
                printf("a major historical event.\n");
                break;
            case 2:
                printf("a catastrophic disaster.\n");
                break;
        }

        events[num_events].time = event_time;
        printf("Would you like to add a note about this event? (y/n)\n");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y') {
            printf("Please enter your note:\n");
            scanf("%[^\n]", events[num_events].description);
        }

        num_events++;
    }

    printf("Your journey through time has come to an end.\n");
    printf("Thank you for using the Time Travel Simulator!\n");

    return 0;
}