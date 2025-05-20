//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    int calories;
    int steps;
    int distance;
    int time;
} fitness_data;

int main() {
    int num_entries = 0;
    fitness_data entries[MAX_ENTRIES];
    time_t start_time;
    time_t end_time;
    double elapsed_time;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your fitness data:\n");

    while (num_entries < MAX_ENTRIES) {
        printf("Enter the number of calories burned: ");
        scanf("%d", &entries[num_entries].calories);

        printf("Enter the number of steps taken: ");
        scanf("%d", &entries[num_entries].steps);

        printf("Enter the distance traveled in meters: ");
        scanf("%d", &entries[num_entries].distance);

        printf("Enter the duration of the workout in seconds: ");
        scanf("%d", &entries[num_entries].time);

        num_entries++;
    }

    printf("\nYour fitness data has been saved!\n");

    start_time = time(NULL);
    end_time = start_time;

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. View fitness data\n");
        printf("2. Add new fitness data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &num_entries);

        if (num_entries == 1) {
            printf("\nFitness data:\n");
            for (int i = 0; i < num_entries; i++) {
                printf("Calories burned: %d\n", entries[i].calories);
                printf("Steps taken: %d\n", entries[i].steps);
                printf("Distance traveled: %d meters\n", entries[i].distance);
                printf("Duration of workout: %d seconds\n", entries[i].time);
                printf("\n");
            }
        } else if (num_entries == 2) {
            printf("\nEnter the number of calories burned: ");
            scanf("%d", &entries[num_entries-1].calories);

            printf("Enter the number of steps taken: ");
            scanf("%d", &entries[num_entries-1].steps);

            printf("Enter the distance traveled in meters: ");
            scanf("%d", &entries[num_entries-1].distance);

            printf("Enter the duration of the workout in seconds: ");
            scanf("%d", &entries[num_entries-1].time);

            num_entries++;
        } else if (num_entries == 3) {
            printf("\nExiting program...\n");
            break;
        } else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("\nTotal workout time: %ld seconds\n", elapsed_time);

    return 0;
}