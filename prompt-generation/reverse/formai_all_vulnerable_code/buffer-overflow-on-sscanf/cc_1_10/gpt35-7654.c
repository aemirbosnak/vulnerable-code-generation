//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to check if provided year is a leap year
int isLeapYear(int year)
{
    if(year%4==0 && (year%100!=0 || year%400==0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to get the number of days in a month of a given year
int daysInMonth(int year, int month)
{
    if(month==2)
    {
        if(isLeapYear(year))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    else if(month==4 || month==6 || month==9 || month==11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

int main()
{
    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("Please enter a date in the format dd-mm-yyyy: ");
    
    // Taking input from user in the given format
    char input[11];
    fgets(input, 11, stdin);
    
    // Converting input to date and storing it in variables
    int day, month, year;
    sscanf(input, "%d-%d-%d", &day, &month, &year);
    
    // Checking if the provided date is valid
    if(day<1 || day>31 || month<1 || month>12)
    {
        printf("\nError: Invalid Date entered. Please try again.\n");
        return 0;
    }
    if(day>daysInMonth(year, month))
    {
        printf("\nError: Invalid Date entered. Please try again.\n");
        return 0;
    }
    
    // Getting the current time
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    
    // Calculating the time difference between current time and provided time
    struct tm travelTime = {0};
    travelTime.tm_hour = localTime->tm_hour;
    travelTime.tm_min = localTime->tm_min;
    travelTime.tm_sec = localTime->tm_sec;
    travelTime.tm_mday = day;
    travelTime.tm_mon = month-1;
    travelTime.tm_year = year-1900;
    
    // Checking if the provided date is in the past or the future
    if(mktime(&travelTime) < currentTime)
    {
        printf("\nYou have traveled back in time to the date: %02d-%02d-%02d \n", day, month, year);
    }
    else
    {
        printf("\nYou have traveled forward in time to the date: %02d-%02d-%02d \n", day, month, year);
    }
    
    printf("\nTime Travel Successful! Enjoy your trip!\n\n");
    
    return 0;
}