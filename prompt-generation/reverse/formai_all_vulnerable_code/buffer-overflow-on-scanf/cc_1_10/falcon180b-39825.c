//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999
#define MIN_YEAR 1900

// Function prototypes
int main();
void time_travel();

int main() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter your destination year (between %d and %d): ", MIN_YEAR, MAX_YEAR);
    int year;
    scanf("%d", &year);
    time_travel(year);
    return 0;
}

void time_travel(int year) {
    struct tm current_time;
    time_t now;
    char* destination_time;

    // Get current time
    now = time(NULL);
    localtime_r(&now, &current_time);

    // Set destination time
    current_time.tm_year = year - 1900;
    current_time.tm_mon = 0;
    current_time.tm_mday = 1;
    destination_time = asctime(&current_time);

    // Time travel effect
    for (int i = 0; i < 10; i++) {
        printf("Time travel in progress...\n");
        for (int j = 0; j < 50; j++) {
            printf(".");
            fflush(stdout);
            usleep(100000);
        }
        printf("\n");
    }

    // Arrive at destination
    printf("You have arrived at the year %d!\n", year);
    printf("The current date and time is: %s", destination_time);
}