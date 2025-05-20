//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LEN 20

int main()
{
    char date_str[MAX_DATE_LEN];
    int year, month, day;

    printf("Enter a date in the format YYYY-MM-DD: ");
    scanf("%s", date_str);

    // Validate the date format
    if (strlen(date_str) != 10)
    {
        printf("Invalid date format!\n");
        return 1;
    }

    // Extract the year, month, and day
    year = atoi(&date_str[0]);
    month = atoi(&date_str[5]);
    day = atoi(&date_str[8]);

    // Check if the date is valid
    if (year < 1 || year > 2000)
    {
        printf("Invalid year!\n");
        return 1;
    }

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

    // Convert the date to a number
    int date_num = (year * 10000) + (month * 100) + day;

    // Print the date number
    printf("Date number: %d\n", date_num);

    return 0;
}