//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: relaxed
#include <stdio.h>
#include <time.h>

int main() {
    time_t currTime;
    struct tm travelTime;
    int year, month, day, hour, minute;
    
    // Get user input for the date and time to travel to
    printf("Enter the year to travel to: ");
    scanf("%d", &year);
    printf("Enter the month to travel to: ");
    scanf("%d", &month);
    printf("Enter the day to travel to: ");
    scanf("%d", &day);
    printf("Enter the hour to travel to: ");
    scanf("%d", &hour);
    printf("Enter the minute to travel to: ");
    scanf("%d", &minute);
    
    // Set the time and date to travel to
    travelTime.tm_year = year - 1900; // years since 1900
    travelTime.tm_mon = month - 1; // months since January (0-11)
    travelTime.tm_mday = day; // day of the month (1-31)
    travelTime.tm_hour = hour; // hours since midnight (0-23)
    travelTime.tm_min = minute; // minutes after the hour (0-59)
    travelTime.tm_sec = 0; // seconds after the minute (0-60)
    
    // Convert the time struct to time_t format
    currTime = mktime(&travelTime);
    
    // Get the current time in time_t format
    time_t currentTime = time(NULL);
    
    // Calculate the time difference in seconds
    double timeDiff = difftime(currTime, currentTime);
    
    printf("\nInitializing time travel...");
    fflush(stdout);
    
    // Wait for 3 seconds
    sleep(3);
    
    printf("\nYou have successfully traveled through time!\n");
    fflush(stdout);
    
    // Check whether the time travel was in the past or future
    if (timeDiff < 0) {
        printf("You have traveled back in time by %.0f seconds.\n", -timeDiff);
        fflush(stdout);
    } else {
        printf("You have traveled forward in time by %.0f seconds.\n", timeDiff);
        fflush(stdout);
    }
    
    // Convert the travel time to a string and print it out
    char buffer[80];
    strftime(buffer, 80, "The date and time you have traveled to is: %c", &travelTime);
    printf("%s\n", buffer);
    
    return 0;
}