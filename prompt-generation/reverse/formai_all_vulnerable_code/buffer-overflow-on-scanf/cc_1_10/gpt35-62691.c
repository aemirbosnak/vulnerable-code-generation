//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message and program description
    printf("Welcome to the Time Travel Simulator!\n");
    printf("This program will take you on a journey through time.\n\n");
    
    // Get user input for year to travel to
    int year;
    printf("What year would you like to travel to? (please enter four digits): ");
    scanf("%d", &year);
    printf("Travelling to year %d...\n\n", year);
    
    // Get current time and calculate time difference
    time_t current_time = time(NULL);
    struct tm *now = localtime(&current_time);
    int years_diff = year - (now->tm_year + 1900);
    
    // Print time difference
    printf("Time difference: %d years\n\n", years_diff);
    
    // Travel forwards or backwards in time
    if (years_diff > 0) {
        printf("Travelling forwards in time...\n\n");
        for (int i = 0; i <= years_diff; i++) {
            printf("Year: %d\n", (now->tm_year + i + 1900));
            // Add delay for dramatic effect
            if (i % 10 == 0) {
                printf(".......\n");
                system("sleep 1");
            }
        }
    } else {
        printf("Travelling backwards in time...\n\n");
        for (int i = 0; i <= abs(years_diff); i++) {
            printf("Year: %d\n", (now->tm_year - i + 1900));
            // Add delay for dramatic effect
            if (i % 10 == 0) {
                printf(".......\n");
                system("sleep 1");
            }
        }
    }
    
    // Final message upon arrival at destination
    printf("\n\nArrived at your destination year of %d!\n", year);
    printf("Thank you for using the Time Travel Simulator!\n");
    
    return 0;
}