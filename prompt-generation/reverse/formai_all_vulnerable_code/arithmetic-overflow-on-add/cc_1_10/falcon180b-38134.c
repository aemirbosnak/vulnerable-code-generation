//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

struct event {
    time_t timestamp;
    char description[80];
};

int main() {
    struct event events[MAX_EVENTS];
    int num_events = 0;
    int choice;
    time_t current_time;

    srand(time(NULL));
    current_time = time(NULL);

    do {
        printf("\nTime Travel Simulator\n");
        printf("1. Add event\n");
        printf("2. View timeline\n");
        printf("3. Time travel\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_events >= MAX_EVENTS) {
                    printf("Maximum number of events reached.\n");
                } else {
                    printf("Enter event description: ");
                    scanf("%s", events[num_events].description);
                    events[num_events].timestamp = current_time + rand() % 86400;
                    num_events++;
                    printf("Event added.\n");
                }
                break;
            case 2:
                printf("\nTimeline:\n");
                for (int i = 0; i < num_events; i++) {
                    printf("%s - %s\n", ctime(&events[i].timestamp), events[i].description);
                }
                break;
            case 3:
                printf("Enter target time (YYYY-MM-DD HH:MM:SS): ");
                scanf("%s", events[num_events-1].description);
                events[num_events-1].timestamp = strptime(events[num_events-1].description, "%Y-%m-%d %H:%M:%S", NULL);
                current_time = events[num_events-1].timestamp;
                printf("Time travel successful.\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}