//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TIME_MAX 10000
#define TIME_STEP 1

// Time travel function
void time_travel(int time) {
    printf("Time travel initiated...\n");
    for (int i = 0; i < time; i++) {
        printf("Traveling through time...\n");
        fflush(stdout);
        usleep(TIME_STEP);
    }
    printf("Time travel successful!\n\n");
}

// Main function
int main() {
    int choice;
    do {
        printf("Welcome to the Time Travel Simulator!\n");
        printf("Please choose an option:\n");
        printf("1. Time travel\n");
        printf("2. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the amount of time you want to travel (in seconds): ");
                int time = 0;
                scanf("%d", &time);
                if (time > 0 && time <= TIME_MAX) {
                    time_travel(time);
                } else {
                    printf("Invalid time entered.\n");
                }
                break;
            case 2:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice entered.\n");
        }
        printf("\nPress enter to continue...\n");
        fflush(stdout);
        getchar();
    } while (choice!= 2);
    return 0;
}