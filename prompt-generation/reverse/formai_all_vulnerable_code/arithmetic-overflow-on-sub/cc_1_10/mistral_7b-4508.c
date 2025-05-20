//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100

struct Event {
    int year;
    char description[100];
};

int main() {
    int choice, dest_year;
    struct Event events[MAX_EVENTS];
    struct Event current_event;
    int current_index = 0;
    clock_t start, end;

    printf("\n*************************************************\n");
    printf("*          Welcome to The ChronoMage's Apprentice! *\n");
    printf("*************************************************\n");
    printf("\nPress '1' to add an event, '2' to travel in time,\n");
    printf("or '0' to exit the program.\n");

    while (1) {
        printf("\nWhat would you like to do? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (current_index >= MAX_EVENTS) {
                    printf("Maximum number of events reached!\n");
                    break;
                }
                printf("Enter year and description: ");
                scanf("%d %s", &events[current_index].year, events[current_index].description);
                current_index++;
                break;

            case 2:
                printf("Enter destination year: ");
                scanf("%d", &dest_year);

                start = clock();
                for (int i = 0; i < current_index; i++) {
                    if (events[i].year > dest_year) {
                        current_event = events[i];
                        break;
                    }
                }

                printf("\nYou have traveled back in time to the year %d.\n", current_event.year);
                printf("Event: %s\n", current_event.description);

                end = clock();
                double time_difference = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Time traveled: %f seconds.\n", time_difference);

                break;

            case 0:
                printf("\nThank you for using The ChronoMage's Apprentice!\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}