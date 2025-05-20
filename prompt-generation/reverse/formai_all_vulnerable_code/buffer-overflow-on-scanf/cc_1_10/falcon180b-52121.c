//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 100

struct time_travel {
    time_t timestamp;
    int destination_year;
};

int main() {
    struct time_travel time_travels[MAX_TIME_TRAVELS];
    int num_time_travels = 0;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You can travel back in time by entering a negative number of years.\n");
    printf("You can travel forward in time by entering a positive number of years.\n");
    printf("To exit the program, enter 0.\n");

    while (1) {
        printf("Enter the number of years you want to travel (0 to exit): ");
        int years;
        scanf("%d", &years);

        if (years == 0) {
            break;
        }

        gettimeofday(&time_travels[num_time_travels].timestamp, NULL);
        time_travels[num_time_travels].destination_year = years;
        num_time_travels++;

        if (num_time_travels >= MAX_TIME_TRAVELS) {
            printf("Maximum number of time travels reached. Exiting program.\n");
            exit(0);
        }
    }

    printf("\nYour time travel log:\n");
    for (int i = 0; i < num_time_travels; i++) {
        time_t now = time(NULL);
        struct tm *current_time = localtime(&now);
        int current_year = 1900 + current_time->tm_year;

        int diff = current_year - time_travels[i].destination_year;
        if (diff < 0) {
            printf("You traveled back in time %d years to %d.\n", -diff, current_year);
        } else {
            printf("You traveled forward in time %d years to %d.\n", diff, current_year);
        }
    }

    return 0;
}