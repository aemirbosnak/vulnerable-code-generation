//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TIME 1000
#define MAX_EVENTS 100
#define MAX_EVENT_LENGTH 100
#define MAX_EVENT_TIME 100
#define MAX_EVENT_DESCRIPTION 1000

typedef struct {
    int time;
    char event[MAX_EVENT_LENGTH];
    char description[MAX_EVENT_DESCRIPTION];
} Event;

int main() {
    int num_events = 0;
    Event events[MAX_EVENTS];
    char input[MAX_EVENT_DESCRIPTION];
    int choice;

    printf("Welcome to the Post-Apocalyptic Time Travel Simulator!\n");
    printf("Please enter the number of events you would like to simulate: ");
    scanf("%d", &num_events);

    printf("Enter the events in chronological order:\n");
    for (int i = 0; i < num_events; i++) {
        printf("Event %d:\n", i+1);
        printf("Time: ");
        scanf("%d", &events[i].time);
        printf("Event: ");
        scanf("%s", events[i].event);
        printf("Description: ");
        fgets(input, MAX_EVENT_DESCRIPTION, stdin);
        strcpy(events[i].description, input);
        events[i].description[strcspn(events[i].description, "\n")] = '\0';
    }

    printf("\nTime travel starting in 3...2...1...\n\n");
    srand(time(NULL));
    int current_time = 0;

    while (current_time < MAX_TIME) {
        printf("Current time: %d\n", current_time);
        printf("Enter your choice:\n");
        printf("1. Travel forward in time\n");
        printf("2. Travel backward in time\n");
        printf("3. View events\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                current_time += rand() % 10 + 1;
                break;
            case 2:
                current_time -= rand() % 10 + 1;
                break;
            case 3:
                printf("\nEvents:\n");
                for (int i = 0; i < num_events; i++) {
                    if (events[i].time == current_time) {
                        printf("%s - %s\n", events[i].event, events[i].description);
                    }
                }
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}