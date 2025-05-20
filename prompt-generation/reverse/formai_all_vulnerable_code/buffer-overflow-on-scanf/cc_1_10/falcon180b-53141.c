//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_TIME_TRAVELS 10
#define MAX_TIME_TRAVEL_DURATION 60

struct time_travel {
    int duration;
    int destination_year;
};

int main() {
    struct time_travel time_travels[MAX_TIME_TRAVELS];
    int num_time_travels = 0;
    int choice, year = 2021;

    while (1) {
        printf("\nWelcome to the Time Travel Simulator!\n");
        printf("Current year: %d\n", year);

        if (num_time_travels == MAX_TIME_TRAVELS) {
            printf("Sorry, you have reached the maximum number of time travels.\n");
            break;
        }

        printf("Please choose an option:\n");
        printf("1. Travel through time\n");
        printf("2. View time travel history\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the duration of your time travel (in seconds): ");
            scanf("%d", &time_travels[num_time_travels].duration);
            printf("Enter the destination year: ");
            scanf("%d", &time_travels[num_time_travels].destination_year);
            num_time_travels++;
            break;
        case 2:
            printf("\nTime travel history:\n");
            for (int i = 0; i < num_time_travels; i++) {
                printf("Time travel %d: %d seconds to the year %d\n", i+1, time_travels[i].duration, time_travels[i].destination_year);
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}