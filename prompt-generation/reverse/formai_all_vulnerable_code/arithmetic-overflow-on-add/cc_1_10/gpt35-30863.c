//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Welcome message
    printf("Welcome to Time Travel Simulator!\n\n");

    // Random generator seed
    srand(time(NULL));

    // Time variables
    int hour = 0;
    int minute = 0;
    int day = 0;
    int month = 0;
    int year = 0;

    // Start and end year
    int start_year = 1980;
    int end_year = 2022;

    // Present time
    time_t now;
    struct tm *local;
    now = time(NULL);
    local = localtime(&now);

    // Assign present time values to variables
    hour = local->tm_hour;
    minute = local->tm_min;
    day = local->tm_mday;
    month = local->tm_mon+1;
    year = local->tm_year+1900;

    // Display present time
    printf("Present time: %02d:%02d %02d/%02d/%d\n",hour,minute,day,month,year);

    // User input prompt
    printf("\nEnter number of years to travel: ");
    int years_to_travel;
    scanf("%d",&years_to_travel);

    // Destination time calculation
    year = year + years_to_travel;

    // Handle end year limit
    if(year > end_year) {
        printf("Sorry, time travel limit exceeded. Maximum end year is %d\n", end_year);
        return 0;
    }

    // Randomize month and day within the year
    month = rand() % 12 + 1;
    day = rand() % 31 + 1;

    // Handle February and leap year
    if(month == 2) {
        if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            day = rand() % 29 + 1;
        }
        else {
            day = rand() % 28 + 1;
        }
    }

    // Display destination time
    printf("Destination time: %02d:%02d %02d/%02d/%d\n",hour,minute,day,month,year);

    return 0;
}