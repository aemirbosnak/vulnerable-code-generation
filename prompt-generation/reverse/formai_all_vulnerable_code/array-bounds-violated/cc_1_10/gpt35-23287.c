//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int year = 2021, month = 10, day = 28, hour = 12, minute = 0;
    char input[50];

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You are currently in the year %d, month %d, day %d, at %02d:%02d\n", year, month, day, hour, minute);

    while(1)
    {
        printf("Enter a command: ");
        fgets(input, 50, stdin);

        // Remove newline character from input
        input[strlen(input) - 1] = '\0';

        if(!strcmp(input, "travel"))
        {
            int travelYear, travelMonth, travelDay, travelHour, travelMinute;

            printf("Enter the year to travel to (yyyy): ");
            scanf("%d", &travelYear);
            getchar(); // Remove newline character from input buffer

            printf("Enter the month to travel to (mm): ");
            scanf("%d", &travelMonth);
            getchar(); // Remove newline character from input buffer

            printf("Enter the day to travel to (dd): ");
            scanf("%d", &travelDay);
            getchar(); // Remove newline character from input buffer

            printf("Enter the hour to travel to (hh): ");
            scanf("%d", &travelHour);
            getchar(); // Remove newline character from input buffer

            printf("Enter the minute to travel to (mm): ");
            scanf("%d", &travelMinute);
            getchar(); // Remove newline character from input buffer

            printf("Traveling to %d/%02d/%02d, %02d:%02d!\n", travelYear, travelMonth, travelDay, travelHour, travelMinute);

            year = travelYear;
            month = travelMonth;
            day = travelDay;
            hour = travelHour;
            minute = travelMinute;
        }
        else if(!strcmp(input, "wait"))
        {
            int minutes;

            printf("Enter the number of minutes to wait: ");
            scanf("%d", &minutes);
            getchar(); // Remove newline character from input buffer

            int daysToAdd = (hour * 60 + minute + minutes) / 1440;
            int minutesToAdd = (hour * 60 + minute + minutes) % 1440;

            day += daysToAdd;
            hour = minutesToAdd / 60;
            minute = minutesToAdd % 60;

            printf("Waiting for %d minutes...\n", minutes);
            printf("It is now %d/%02d/%02d, %02d:%02d!\n", year, month, day, hour, minute);
        }
        else if(!strcmp(input, "help"))
        {
            printf("Commands:\n");
            printf("- travel: travel to a specific date and time\n");
            printf("- wait: wait for a certain amount of time\n");
            printf("- help: display available commands\n");
            printf("- quit: exit the program\n");
        }
        else if(!strcmp(input, "quit"))
        {
            printf("Goodbye!\n");
            break;
        }
        else
        {
            printf("Invalid command. Type 'help' for available commands.\n");
        }
    }

    return 0;
}