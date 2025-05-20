//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    time_t timestamp;
    char description[MAX_DESCRIPTION_LENGTH];
} Event;

int main() {
    srand(time(NULL));
    Event events[MAX_EVENTS];
    int num_events = 0;
    int choice;
    time_t current_time = time(NULL);

    do {
        printf("Welcome to the Time Travel Simulator!\n");
        printf("Current time: %s", ctime(&current_time));
        printf("\n");
        printf("1. Travel back in time\n");
        printf("2. Travel forward in time\n");
        printf("3. Create a new event\n");
        printf("4. View past events\n");
        printf("5. Quit\n");
        printf("\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Traveling back in time...\n");
            current_time -= rand() % 3600 + 1; // Travel back between 1 and 3600 seconds
            break;
        case 2:
            printf("Traveling forward in time...\n");
            current_time += rand() % 3600 + 1; // Travel forward between 1 and 3600 seconds
            break;
        case 3:
            printf("Creating a new event...\n");
            printf("Enter a description of the event: ");
            scanf("%s", events[num_events].description);
            events[num_events].timestamp = current_time;
            num_events++;
            break;
        case 4:
            printf("Viewing past events...\n");
            for (int i = 0; i < num_events; i++) {
                printf("%s - %s\n", ctime(&events[i].timestamp), events[i].description);
            }
            break;
        case 5:
            printf("Exiting the Time Travel Simulator.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }

    } while (choice!= 5);

    return 0;
}