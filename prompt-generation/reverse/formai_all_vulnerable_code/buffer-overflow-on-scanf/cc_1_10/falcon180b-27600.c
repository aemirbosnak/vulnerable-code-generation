//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS 1000000

struct Event {
    int year;
    char *description;
};

int main() {
    srand(time(NULL));

    int num_events = rand() % 10 + 1;
    struct Event events[num_events];

    for (int i = 0; i < num_events; i++) {
        events[i].year = rand() % MAX_YEARS;
        events[i].description = malloc(50 * sizeof(char));
        sprintf(events[i].description, "Event %d: %d", i + 1, events[i].year);
    }

    int current_year = 0;
    int destination_year = 0;

    while (1) {
        system("clear");
        printf("Current Year: %d\n", current_year);

        for (int i = 0; i < num_events; i++) {
            if (events[i].year == current_year) {
                printf("%s\n", events[i].description);
            }
        }

        printf("Enter Destination Year: ");
        scanf("%d", &destination_year);

        if (destination_year < current_year || destination_year > MAX_YEARS) {
            printf("Invalid year!\n");
            continue;
        }

        int travel_time = destination_year - current_year;

        printf("Traveling to %d...\n", destination_year);
        for (int i = 0; i < travel_time; i++) {
            printf("%d years passed...\n", i + 1);
            usleep(1000000);
        }

        current_year = destination_year;
    }

    return 0;
}