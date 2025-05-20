//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define MAX_TIME_TRAVELS 100
#define TIME_TRAVEL_DELAY 1000000  // 1 second delay

int main() {
    char input[100];
    int choice;
    time_t current_time;
    struct tm *current_tm;
    int num_time_travels = 0;

    printf("Welcome to the Time Travel Simulator!\n");

    // Initialize random seed
    srand(time(NULL));

    // Get current time
    time(&current_time);
    current_tm = localtime(&current_time);

    // Print current date and time
    printf("Current date and time: %s", asctime(current_tm));

    // Main loop
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Time travel to the future\n");
        printf("2. Time travel to the past\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_time_travels >= MAX_TIME_TRAVELS) {
                    printf("You have reached the maximum number of time travels.\n");
                } else {
                    int num_years = rand() % 100;
                    time_t future_time = current_time + num_years * 365 * 24 * 60 * 60;
                    struct tm *future_tm = localtime(&future_time);
                    printf("You have traveled to the future! It is now %s.\n", asctime(future_tm));
                    num_time_travels++;
                }
                break;
            case 2:
                if (num_time_travels >= MAX_TIME_TRAVELS) {
                    printf("You have reached the maximum number of time travels.\n");
                } else {
                    int num_years = rand() % 100;
                    time_t past_time = current_time - num_years * 365 * 24 * 60 * 60;
                    struct tm *past_tm = localtime(&past_time);
                    printf("You have traveled to the past! It is now %s.\n", asctime(past_tm));
                    num_time_travels++;
                }
                break;
            case 3:
                printf("Exiting Time Travel Simulator...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        usleep(TIME_TRAVEL_DELAY);
    }

    return 0;
}