//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

int main() {
    // Set up variables
    time_t current_time;
    struct tm *time_info;
    char time_string[9];
    int current_year, target_year, starting_year;
    bool travel_forward = true;

    // Get current year
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_string, sizeof(time_string), "%Y", time_info);
    current_year = atoi(time_string);
    
    // Get starting year
    printf("Enter starting year: ");
    scanf("%d", &starting_year);
    
    // Determine time travel direction
    if (current_year < starting_year) {
        printf("Traveling forward in time!\n");
    } else {
        printf("Traveling backward in time!\n");
        travel_forward = false;
    }
    
    // Get target year
    printf("Enter target year: ");
    scanf("%d", &target_year);

    // Time travel loop
    for (int i = starting_year; ((travel_forward && i <= target_year) || (!travel_forward && i >= target_year)); travel_forward ? i++ : i--) {
        // Clear console
        system("clear");

        // Display current year
        printf("Year: %d\n\n", i);
        if (i == current_year) {
            printf("You are in the present!\n");
        } else if (i > current_year) {
            printf("You are currently in the future!\n");
        } else {
            printf("You are currently in the past!\n");
        }

        // Sleep for one second to simulate time passing
        sleep(1);
    }

    // Print final message
    printf("You have arrived in the year %d!\n", target_year);

    return 0;
}