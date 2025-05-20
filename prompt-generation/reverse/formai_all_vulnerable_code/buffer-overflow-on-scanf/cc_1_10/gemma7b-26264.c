//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char date_string[200];
    int year, month, day;
    int invalid_flag = 0;

    printf("Enter a date in the format YYYY-MM-DD:** ");
    scanf("%s", date_string);

    // Parse the date string
    year = atoi(&date_string[0]);
    month = atoi(&date_string[5]);
    day = atoi(&date_string[8]);

    // Validate the date
    if (year < 1000 || year > 2023)
    {
        invalid_flag = 1;
        printf("Invalid year.\n");
    }
    if (month < 1 || month > 12)
    {
        invalid_flag = 1;
        printf("Invalid month.\n");
    }
    if (day < 1 || day > 31)
    {
        invalid_flag = 1;
        printf("Invalid day.\n");
    }

    // Convert the date to a human-readable string
    char date_message[200];
    sprintf(date_message, "The date you entered is: %d-%d-%d", year, month, day);

    // Print the date message
    if (!invalid_flag)
    {
        printf("%s\n", date_message);
    }
    else
    {
        printf("Invalid date.\n");
    }

    return 0;
}