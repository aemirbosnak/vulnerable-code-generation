//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS 100
#define MIN_YEAR 1900
#define MAX_YEAR 2100

typedef struct {
    int year;
    char description[100];
} Event;

Event events[MAX_YEARS];

void set_event(int year, const char *description) {
    if (year >= MIN_YEAR && year <= MAX_YEAR) {
        events[year - MIN_YEAR] = (Event) {year, description};
    } else {
        printf("Invalid year: %d\n", year);
    }
}

int main() {
    srand(time(NULL));

    // Set some initial events
    for (int i = 0; i < 10; i++) {
        int year = rand() % (MAX_YEAR - MIN_YEAR + 1) + MIN_YEAR;
        char description[100];
        sprintf(description, "Event %d occurred.", year);
        set_event(year, description);
    }

    int current_year = MIN_YEAR + time(NULL) / 365;
    printf("\nCurrent year: %d\n", current_year);
    printf("Available commands:\n1. Go to the past\n2. Go to the future\n3. Show events\n4. Set an event\n");

    int command;
    while (1) {
        scanf("%d", &command);
        switch (command) {
            case 1:
                {
                    int year;
                    printf("Enter the year to travel to: ");
                    scanf("%d", &year);
                    if (year >= MIN_YEAR && year < current_year) {
                        current_year = year;
                        printf("You traveled to the past. Current year: %d\n", current_year);
                    } else {
                        printf("Invalid year or you cannot travel to the past from the present.\n");
                    }
                    break;
                }
            case 2:
                {
                    int year;
                    printf("Enter the year to travel to: ");
                    scanf("%d", &year);
                    if (year > current_year) {
                        current_year = year;
                        printf("You traveled to the future. Current year: %d\n", current_year);
                    } else {
                        printf("Invalid year or you cannot travel to the future from the present.\n");
                    }
                    break;
                }
            case 3:
                {
                    printf("Events:\n");
                    for (int i = 0; i < MAX_YEARS; i++) {
                        if (events[i].year) {
                            printf("Year %d: %s\n", events[i].year, events[i].description);
                        }
                    }
                    break;
                }
            case 4:
                {
                    int year;
                    char description[100];
                    printf("Enter the year and the description of the event: ");
                    scanf("%d%s", &year, description);
                    set_event(year, description);
                    printf("Event set.\n");
                    break;
                }
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}