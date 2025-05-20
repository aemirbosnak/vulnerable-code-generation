//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void time_travel(int destination_year);
void display_current_time(int current_year);

// Global variables
int current_year = 2021;

int main() {
    int choice;
    while (1) {
        printf("Welcome to the Time Travel Simulator!\n");
        printf("Current year: %d\n", current_year);
        printf("Enter your choice:\n1. Time travel\n2. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            int destination_year;
            printf("Enter destination year: ");
            scanf("%d", &destination_year);
            time_travel(destination_year);
        } else if (choice == 2) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function to simulate time travel
void time_travel(int destination_year) {
    if (destination_year < current_year) {
        printf("Time travel to the past is not yet possible.\n");
    } else {
        printf("Preparing for time travel to the year %d...\n", destination_year);
        srand(time(0));
        int time_difference = destination_year - current_year;
        printf("Time difference: %d years\n", time_difference);
        for (int i = 0; i < time_difference; i++) {
            printf("Traveling through time...\n");
            current_year++;
            display_current_time(current_year);
        }
        printf("Arrived in the year %d!\n", current_year);
    }
}

// Function to display current time
void display_current_time(int current_year) {
    time_t now = time(0);
    struct tm *t = localtime(&now);
    printf("Current date and time: %s", asctime(t));
}