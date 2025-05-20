//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME 1000000000
#define TIME_INCREMENT 1

int main() {
    int time = 0;
    int choice;
    int i;
    int start_time;
    int end_time;
    int time_travel;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You are currently in the year %d.\n", time);

    do {
        printf("What would you like to do?\n");
        printf("1. Travel forward in time\n");
        printf("2. Travel backward in time\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many years forward do you want to travel?\n");
                scanf("%d", &time_travel);
                time += time_travel;
                if (time > MAX_TIME) {
                    printf("You can't travel any further in time!\n");
                    time = MAX_TIME;
                }
                printf("You are now in the year %d.\n", time);
                break;

            case 2:
                printf("How many years backward do you want to travel?\n");
                scanf("%d", &time_travel);
                time -= time_travel;
                if (time < 0) {
                    printf("You can't travel any further in time!\n");
                    time = 0;
                }
                printf("You are now in the year %d.\n", time);
                break;

            case 3:
                printf("Thank you for using the Time Travel Simulator!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= 3);

    return 0;
}