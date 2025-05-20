//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
    //initialize variables
    int current_year = 2021, target_year, travel_duration, elapsed_time = 0;
    bool traveling = true;
    
    //ask user for target year and travel duration
    printf("Welcome to Time Travel Simulator!\n");
    printf("What year would you like to travel to? (enter a year after 2021): ");
    scanf("%d", &target_year);
    printf("How many years would you like to travel for?: ");
    scanf("%d", &travel_duration);
    
    //initialize time variables
    time_t current_time;
    struct tm *time_info;
    char time_str[9];
    
    //get current time and print it
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_str, sizeof(time_str), "%H:%M:%S", time_info);
    printf("Current time is: %s\n", time_str);
    
    //simulate time travel
    while (traveling) {
        //update current year and elapsed time
        current_year += 1;
        elapsed_time += 1;
        
        //check if target year is reached
        if (current_year == target_year) {
            traveling = false;
            printf("You have arrived in the year %d after traveling for %d years!\n", target_year, travel_duration);
        }

        //wait for 1 second to simulate time travel
        sleep(1);

        //print current year
        printf("Current year: %d\n", current_year);
    }
    
    //print total elapsed time
    printf("Total elapsed time: %d seconds\n", elapsed_time);
    
    return 0;
}