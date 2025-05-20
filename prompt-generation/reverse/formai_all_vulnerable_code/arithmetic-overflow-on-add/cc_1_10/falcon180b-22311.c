//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999

struct event {
    int year;
    char *description;
};

void time_travel(int start_year, int end_year) {
    srand(time(NULL));

    struct event events[] = {
        {1900, "First flight by the Wright brothers"},
        {1928, "Penicillin discovered by Alexander Fleming"},
        {1955, "Disneyland opens in California"},
        {1969, "Apollo 11 lands on the moon"},
        {1989, "Fall of the Berlin Wall"},
        {2007, "Apple releases the first iPhone"},
        {2020, "COVID-19 pandemic spreads worldwide"}
    };

    int num_events = sizeof(events) / sizeof(events[0]);

    for (int i = start_year; i <= end_year; i++) {
        if (i >= 1900 && i <= MAX_YEAR) {
            printf("Traveling to year %d...\n", i);

            for (int j = 0; j < num_events; j++) {
                if (events[j].year == i) {
                    printf("%s\n", events[j].description);
                }
            }
        } else {
            printf("Invalid year.\n");
        }

        printf("\n");
    }
}

int main() {
    int start_year, end_year;

    printf("Enter start year (1900-9999): ");
    scanf("%d", &start_year);

    printf("Enter end year (1900-9999): ");
    scanf("%d", &end_year);

    time_travel(start_year, end_year);

    return 0;
}