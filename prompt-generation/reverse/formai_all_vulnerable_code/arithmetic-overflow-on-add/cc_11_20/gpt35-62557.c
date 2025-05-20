//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include <stdio.h>

void timeTravel(int year, int month, int day, int hour, int minute, int second, int iteration)
{
    if(iteration == 0)
    {
        printf("Travel complete! Final date and time: %d/%d/%d %02d:%02d:%02d\n", year, month, day, hour, minute, second);
        return;
    }

    second++;
    if(second == 60)
    {
        second = 0;
        minute++;
    }
    if(minute == 60)
    {
        minute = 0;
        hour++;
    }
    if(hour == 24)
    {
        hour = 0;
        day++;
    }
    if(day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
    {
        day = 1;
        month++;
    }
    else if(day == 28 && month == 2)
    {
        day = 1;
        month++;
    }
    else if(day == 30 && (month == 4 || month == 6 || month == 9 || month == 11))
    {
        day = 1;
        month++;
    }
    if(month == 13)
    {
        month = 1;
        year++;
    }

    printf("Traveling through time... Current date and time: %d/%d/%d %02d:%02d:%02d\n", year, month, day, hour, minute, second);
    timeTravel(year, month, day, hour, minute, second, iteration - 1);
}

int main()
{
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter a date and time in the format YYYY MM DD HH MM SS: ");
    int year, month, day, hour, minute, second, iteration;
    scanf("%d %d %d %d %d %d", &year, &month, &day, &hour, &minute, &second);
    printf("Enter the number of iterations to travel through time: ");
    scanf("%d", &iteration);

    printf("\nStarting time travel...\n\n");
    timeTravel(year, month, day, hour, minute, second, iteration);

    return 0;
}