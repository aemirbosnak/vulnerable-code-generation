//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: mathematical
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char date[100];
    printf("Enter a date in the format DD/MM/YYYY: ");
    fgets(date, sizeof(date), stdin);

    // Convert month to its corresponding numeric value
    int month = 0;
    for (int i = 0; i < strlen(date); i++)
    {
        if (date[i] >= '0' && date[i] <= '9')
        {
            month *= 10;
            month += date[i] - '0';
        }
        else if (date[i] >= 'A' && date[i] <= 'Z')
        {
            month *= 10;
            month += (date[i] - 'A' + 11);
        }
    }

    // Convert day and year to their corresponding numeric values
    int day = 0;
    int year = 0;
    for (int i = strlen(date) - 1; i >= 0; i--)
    {
        if (date[i] >= '0' && date[i] <= '9')
        {
            day *= 10;
            day += date[i] - '0';
        }
        else if (date[i] >= '0' && date[i] <= '9')
        {
            year *= 10;
            year += date[i] - '0';
        }
    }

    // Calculate the day of the week
    int dow = (year % 100) + (year / 100) + (month + 1) / 12 + day / 7;

    // Convert day of the week to its corresponding text
    char* dow_text[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    printf("The date %s is a %s.\n", date, dow_text[dow]);

    return 0;
}