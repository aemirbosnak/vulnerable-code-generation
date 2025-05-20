//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // declare variables to hold user input
    int day, year;
    char month[10];

    // prompt user to enter a date in Natural Language format
    printf("Please enter a date in Natural Language format (e.g. January 1, 2022): ");
    scanf("%s %d, %d", month, &day, &year);

    // declare an array to hold the names of the months
    char months[12][10] = {"January", "February", "March", "April", "May", "June",
                           "July", "August", "September", "October", "November", "December"};

    // declare variables to hold the converted month and the number of days in the month
    int converted_month, days_in_month;

    // loop through the month array to find the index of the entered month
    for (int i = 0; i < 12; i++)
    {
        if (strcmp(month, months[i]) == 0)
        {
            converted_month = i + 1; // add 1 to match the month number notation (1-12)
            break;
        }
    }

    // switch statement to determine the number of days in the entered month
    switch (converted_month)
    {
        case 4:
        case 6:
        case 9:
        case 11:
            days_in_month = 30;
            break;
        case 2:
            // check if the entered year is a leap year
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
            {
                days_in_month = 29;
            }
            else
            {
                days_in_month = 28;
            }
            break;
        default:
            days_in_month = 31;
            break;
    }

    // output the converted date in yyyy-mm-dd format
    printf("%04d-%02d-%02d\n", year, converted_month, day);

    return 0;
}