//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TIME_TRAVELS 100
#define MAX_TIME_TRAVEL_LENGTH 100

struct time_travel {
    int length;
    int start_year;
    int end_year;
};

int main() {
    struct time_travel time_travels[MAX_TIME_TRAVELS];
    int num_time_travels = 0;
    int choice;
    int year = 2021;

    srand(time(NULL));

    while (1) {
        printf("Welcome to the Time Travel Simulator!\n");
        printf("1. Start a new time travel\n");
        printf("2. View time travel history\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_time_travels >= MAX_TIME_TRAVELS) {
                printf("Maximum number of time travels reached.\n");
            } else {
                time_travels[num_time_travels].length = rand() % (MAX_TIME_TRAVEL_LENGTH + 1);
                time_travels[num_time_travels].start_year = year;
                printf("Enter the end year for your time travel: ");
                scanf("%d", &time_travels[num_time_travels].end_year);
                num_time_travels++;
            }
            break;
        case 2:
            if (num_time_travels == 0) {
                printf("No time travel history.\n");
            } else {
                printf("Time Travel History:\n");
                for (int i = 0; i < num_time_travels; i++) {
                    printf("Time travel %d: %d years from %d to %d\n", i + 1,
                            time_travels[i].length, time_travels[i].start_year,
                            time_travels[i].end_year);
                }
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