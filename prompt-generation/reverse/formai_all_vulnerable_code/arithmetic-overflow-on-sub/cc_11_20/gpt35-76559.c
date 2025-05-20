//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    time_t now;
    struct tm *timenow;

    time(&now);  // Get the system time
    timenow = localtime(&now); // Convert the system time to local time

    printf("\nWelcome to the Time Travel Simulator Program!\n");

    int year, month, day;
    printf("\nEnter the desired year to travel: ");
    scanf("%d", &year);
    printf("\nEnter the desired month to travel: ");
    scanf("%d", &month);
    printf("\nEnter the desired day to travel: ");
    scanf("%d", &day);

    // Checking if the given date is valid
    if (year < timenow->tm_year+1900 || (year == timenow->tm_year+1900 && month < timenow->tm_mon+1) || (year == timenow->tm_year+1900 && month == timenow->tm_mon+1 && day <= timenow->tm_mday))
    {
        printf("\nSorry, you cannot travel to the past!");
        return 0;
    }
    else if (month < 1 || month > 12 || day < 1 || day > 31)
    {
        printf("\nThe given date is invalid. Please enter a valid date!");
        return 1;
    }

    // Converting the given date to time_t format
    struct tm traveltime = {0};
    traveltime.tm_year = year-1900;
    traveltime.tm_mon = month-1;
    traveltime.tm_mday = day;
    time_t travel = mktime(&traveltime);

    // Getting the time difference between current time and the desired time
    int diff = (int) difftime(travel, now);
    int sec=0,min=0,hr=0;

    while (diff>=3600) // To convert the time difference to hours, minutes and seconds
    {
        hr++;
        diff-=3600;
    }
    while (diff>=60)
    {
        min++;
        diff-=60;
    }
    sec=diff;

    printf("\nCurrent time: %s", asctime(timenow)); // Printing the current time
    printf("\nTravelling to %d-%d-%d...\n",day,month,year);
    printf("\nTime difference: %d hours %d minutes %d seconds", hr,min,sec);
    
    // Delaying the execution to simulate time travel
    printf("\n\nStarting time travel...");
    for(int i=3;i>=1;i--)
    {
        printf("\n\n%d",i);
        sleep(1);
    }
    printf("\n\nWelcome to %d-%d-%d!",day,month,year);

    return 0;
}