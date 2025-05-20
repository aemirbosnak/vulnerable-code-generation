//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t current_time;
    struct tm * time_info;
    char time_string[50];
    int year, month, day, hour, minute, second, is_valid_date;

    // Getting current time
    time(&current_time);
    time_info = localtime(&current_time);

    // Displaying current time
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info );
    printf("Current Time: %s\n\n", time_string);
    
    // Getting user input for travel date
    do {
        printf("Enter the future date and time (yyyy-mm-dd hh:mm:ss): ");
        scanf("%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);

        // Validating input date
        if (year < 1900 || year > 3000 || month < 1 || month > 12 || day < 1 || day > 31 || hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59){
            is_valid_date = 0;
            printf("Invalid date and time. ");
        } else {
            is_valid_date = 1;
        }
    } while (is_valid_date == 0);
    
    // Creating time struct for future date
    time_info->tm_year = year - 1900;
    time_info->tm_mon = month - 1;
    time_info->tm_mday = day;
    time_info->tm_hour = hour;
    time_info->tm_min = minute; 
    time_info->tm_sec = second;

    // Converting future date and time to epoch time
    time_t future_time = mktime(time_info);

    // Difference in seconds between future time and current time
    int time_diff = difftime(future_time, current_time);

    // Displaying time travel message
    if (time_diff == 0){
        printf("You have successfully traveled through time! You are now in the same time and date as before.\n");
    } else if (time_diff < 0){
        printf("Traveling back in time... You have traveled %d seconds back in time from %s to %s\n", -1 * time_diff, time_string, asctime(time_info));
    } else {
        printf("Traveling to the future... You will reach your destination in %d seconds on %s\n", time_diff, asctime(time_info));
    }

    return 0;
}