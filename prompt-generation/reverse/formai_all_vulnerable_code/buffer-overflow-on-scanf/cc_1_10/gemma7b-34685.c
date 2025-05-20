//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LENGTH 100

int main()
{
    char date_string[MAX_DATE_LENGTH];
    printf("Enter a date in the format MM/DD/YY: ");
    scanf("%s", date_string);

    // Validate the date string
    if (strlen(date_string) < 10)
    {
        printf("Invalid date format!\n");
        return 1;
    }

    // Split the date string into month, day, and year
    char *month_ptr = strchr(date_string, '/');
    char *day_ptr = strchr(month_ptr + 1, '/');
    char *year_ptr = strchr(day_ptr + 1, '\0');

    // Convert the month, day, and year to integers
    int month = atoi(month_ptr);
    int day = atoi(day_ptr);
    int year = atoi(year_ptr);

    // Check if the date is valid
    if (month < 1 || month > 12)
    {
        printf("Invalid month!\n");
        return 1;
    }
    if (day < 1 || day > 31)
    {
        printf("Invalid day!\n");
        return 1;
    }
    if (year < 1900)
    {
        printf("Invalid year!\n");
        return 1;
    }

    // Print the converted date
    printf("The date you entered is: %d/%d/%d\n", month, day, year);

    return 0;
}