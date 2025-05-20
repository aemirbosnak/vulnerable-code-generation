//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *current_tm;
    
    // Getting the current time
    current_time = time(NULL);
    current_tm = localtime(&current_time);
    
    // Presenting the current time
    printf("Current Date and Time:\n");
    printf("%02d/%02d/%04d at %02d:%02d:%02d\n\n", 
           current_tm->tm_mday, current_tm->tm_mon + 1, current_tm->tm_year + 1900, 
           current_tm->tm_hour, current_tm->tm_min, current_tm->tm_sec);
    
    // Asking for the user's destination time
    printf("Please enter the desired year, month, day, hour, minute and second:\n");
    int year, month, day, hour, minute, second;
    scanf("%d %d %d %d %d %d", &year, &month, &day, &hour, &minute, &second);
    
    // Creating the target time structure
    struct tm target_tm = {0};
    target_tm.tm_year = year - 1900;
    target_tm.tm_mon = month - 1;
    target_tm.tm_mday = day;
    target_tm.tm_hour = hour;
    target_tm.tm_min = minute;
    target_tm.tm_sec = second;
    
    // Converting the target time to time_t format
    time_t target_time = mktime(&target_tm);
    
    // Calculating the time difference
    double seconds_diff = difftime(target_time, current_time);
    
    // Displaying the time difference
    printf("Time difference: %.0f seconds\n\n", seconds_diff);
    
    // If the target time is in the past, ask the user if they want to go back in time
    if (seconds_diff < 0) {
        printf("You entered a time in the past. Would you like to go back in time? (y/n)\n");
        char choice;
        scanf(" %c", &choice);
        
        // If yes, update the time difference and target time accordingly
        if (choice == 'y' || choice == 'Y') {
            seconds_diff *= -1;
            target_time = current_time - seconds_diff;
            target_tm = *localtime(&target_time);
            printf("\nTravelling back in time...\n\n");
        } else {
            printf("\nThank you for using the time travel simulator.\n");
            return 0;
        }
    }
    
    // Displaying a countdown to the target time
    printf("\nTravelling to the destination time...\n\n");
    for (int i = 1; i <= seconds_diff; i++) {
        int remaining_seconds = (int) seconds_diff - i;
        printf("%d seconds remaining until arrival\n", remaining_seconds);
        sleep(1);
    }
    
    // Presenting the target time
    printf("\nArrived at the destination time:\n");
    printf("%02d/%02d/%04d at %02d:%02d:%02d\n", 
           target_tm.tm_mday, target_tm.tm_mon + 1, target_tm.tm_year + 1900, 
           target_tm.tm_hour, target_tm.tm_min, target_tm.tm_sec);
    
    return 0;
}