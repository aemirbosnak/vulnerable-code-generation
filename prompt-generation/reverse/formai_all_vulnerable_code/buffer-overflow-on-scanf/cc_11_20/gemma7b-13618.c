//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_TIME 10

int main()
{
    int year, month, day, hour, minute, second;
    int i, j;
    char message[200];

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter the year, month, day, hour, and minute you want to travel to:");
    scanf("%d %d %d %d %d", &year, &month, &day, &hour, &minute);

    // Validate the input
    if (year < 1 || year > MAX_TIME)
    {
        printf("Invalid year. Please try again.\n");
        return 1;
    }
    if (month < 1 || month > 12)
    {
        printf("Invalid month. Please try again.\n");
        return 1;
    }
    if (day < 1 || day > 31)
    {
        printf("Invalid day. Please try again.\n");
        return 1;
    }
    if (hour < 0 || hour > 23)
    {
        printf("Invalid hour. Please try again.\n");
        return 1;
    }
    if (minute < 0 || minute > 59)
    {
        printf("Invalid minute. Please try again.\n");
        return 1;
    }

    // Create a timeline
    printf("Here is your timeline:");
    for (i = year; i <= year + 1; i++)
    {
        for (j = 1; j <= 12; j++)
        {
            printf("%d/%d/ - ", i, j);
        }
    }

    // Print the message at the specified time
    printf("\n");
    printf("It is %d %d %d %d %d %d, %s.\n", year, month, day, hour, minute, second, message);

    return 0;
}