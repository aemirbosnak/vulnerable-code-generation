//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: intelligent
#include <stdio.h>
#include <time.h>

int main()
{
    // Get current year
    int currentYear = 0;
    time_t currentTime = time(NULL);
    struct tm *tm = localtime(&currentTime);
    currentYear = tm->tm_year + 1900;
    
    // Set the time machine year
    int timeMachineYear = 0;
    printf("Enter a year to travel to: ");
    scanf("%d", &timeMachineYear);
    
    // Check if time machine year is valid
    if (timeMachineYear < 0 || timeMachineYear > currentYear)
    {
        printf("Invalid year entered!\n");
        return 0;
    }
    
    // Travel through time!
    char travelDirection[10];
    printf("Travel forwards or backwards in time? (F/B): ");
    scanf("%s", &travelDirection);
    
    if (travelDirection[0] == 'F')
    {
        printf("Travelling to the year %d...\n\n", timeMachineYear);
        for (int year = currentYear; year <= timeMachineYear; year++)
        {
            printf("The year is now %d.\n", year);
            sleep(1); // Wait for 1 second
        }
    }
    else if (travelDirection[0] == 'B')
    {
        printf("Travelling to the year %d...\n\n", timeMachineYear);
        for (int year = currentYear; year >= timeMachineYear; year--)
        {
            printf("The year is now %d.\n", year);
            sleep(1); // Wait for 1 second
        }
    }
    else
    {
        printf("Invalid travel direction entered!\n");
        return 0;
    }
    
    printf("\nArrived at the year %d!\n", timeMachineYear);
    
    return 0;
}