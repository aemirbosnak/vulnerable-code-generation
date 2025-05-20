//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000

typedef struct {
    time_t timestamp;
    char *description;
} Event;

int main() {
    srand(time(NULL));

    Event events[MAX_EVENTS];
    int num_events = 0;

    for (int i = 0; i < MAX_EVENTS && num_events < 10; i++) {
        events[i].timestamp = rand() % (time(NULL) - 365 * 24 * 60 * 60);
        events[i].description = (char *)malloc(sizeof(char) * 100);
        sprintf(events[i].description, "Event %d", num_events + 1);
        num_events++;
    }

    int user_choice;
    do {
        printf("Welcome to the Time Travel Simulator!\n");
        printf("Please choose an event:\n");
        for (int i = 0; i < num_events; i++) {
            printf("%d. %s\n", i + 1, events[i].description);
        }
        scanf("%d", &user_choice);

        if (user_choice >= 1 && user_choice <= num_events) {
            time_t destination_timestamp = events[user_choice - 1].timestamp;
            time_t current_timestamp = time(NULL);

            if (destination_timestamp > current_timestamp) {
                printf("You cannot travel to the future!\n");
            } else {
                time_t travel_duration = destination_timestamp - current_timestamp;
                printf("Traveling back in time to %s...\n", ctime(&destination_timestamp));
                sleep(travel_duration);
                printf("You have arrived at your destination.\n");
            }
        } else {
            printf("Invalid choice.\n");
        }

        printf("Press enter to continue...\n");
        getchar();
    } while (1);

    return 0;
}