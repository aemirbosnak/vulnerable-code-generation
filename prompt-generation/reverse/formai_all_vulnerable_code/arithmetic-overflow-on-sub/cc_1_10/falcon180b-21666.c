//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_STRING_LENGTH 100

typedef struct {
    time_t time;
    char description[MAX_STRING_LENGTH];
} Event;

int main() {
    srand(time(NULL));
    Event events[MAX_EVENTS];
    int num_events = 0;
    int current_event = 0;
    char input[MAX_STRING_LENGTH];
    char choice;

    // Initialize random seed
    printf("Initializing time travel simulator...\n");
    while (num_events < 5) {
        events[num_events].time = rand() % 1000000000; // Generate random time in seconds since epoch
        printf("Enter description for event %d: ", num_events + 1);
        fgets(events[num_events].description, MAX_STRING_LENGTH, stdin);
        num_events++;
    }

    printf("\nWelcome to the Time Travel Simulator!\n");
    printf("You have %d events to choose from:\n", num_events);
    for (int i = 0; i < num_events; i++) {
        printf("%d. %s\n", i + 1, events[i].description);
    }

    while (1) {
        printf("\nEnter your choice: ");
        fgets(input, MAX_STRING_LENGTH, stdin);
        choice = input[0];

        if (choice == 'q') {
            break;
        } else if (choice >= '1' && choice <= '9') {
            current_event = choice - '0' - 1;
            if (current_event >= 0 && current_event < num_events) {
                time_t target_time = events[current_event].time;
                time_t current_time = time(NULL);
                time_t seconds_to_travel = target_time - current_time;
                sleep(seconds_to_travel);
                printf("\nTraveling back in time to event %s...\n", events[current_event].description);
                printf("You have arrived at %s.\n", ctime(&target_time));
            } else {
                printf("Invalid event number.\n");
            }
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}