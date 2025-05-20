//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t now;
    struct tm *current_time;
    int current_year;
    
    time(&now); // get current time
    current_time = localtime(&now); // convert current time to local time
    current_year = current_time->tm_year + 1900; // get current year
    
    // output current year and prompt user for year to travel to
    printf("The current year is %d.\n", current_year);
    printf("What year would you like to travel to? ");
    
    int target_year;
    scanf("%d", &target_year);
    
    // ensure target year is not before current year
    if (target_year < current_year) {
        printf("Sorry, time travel to the past is not possible.\n");
        return 1;
    }
    
    // travel through time year by year
    for (int year = current_year; year <= target_year; year++) {
        printf("Year %d...\n", year);
        printf("You travel back in time...\n");
        
        // sleep for 1 second to simulate time travel
        struct timespec sleep_time;
        sleep_time.tv_sec = 1;
        sleep_time.tv_nsec = 0;
        nanosleep(&sleep_time, NULL);
        
        printf("You have arrived in %d!\n", year);
        printf("What would you like to do?\n");
        printf("1. Observe historical events\n");
        printf("2. Interact with historical figures\n");
        printf("3. Collect historical artifacts\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("You observe the historical events of %d.\n", year);
                break;
            case 2:
                printf("You interact with historical figures of %d.\n", year);
                break;
            case 3:
                printf("You collect historical artifacts from %d.\n", year);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    
    printf("You have returned to the present day.\n");
    
    return 0;
}