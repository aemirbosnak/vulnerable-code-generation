//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[20];
    char output[30] = "The converted date is: ";
    int month, day, year;
    int num_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char month_names[12][10] = {"January", "February", "March", "April", 
                                "May", "June", "July", "August", "September",
                                "October", "November", "December"};

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in the format 'Month Day, Year':\n");

    // Get user input
    fgets(input, 20, stdin);

    // Parse input
    sscanf(input, "%s %d, %d", month_names[0], &day, &year);

    // Determine month number
    for (int i = 0; i < 12; i++)
    {
        if (strcmp(month_names[0], month_names[i]) == 0)
        {
            month = i + 1;
            break;
        }
    }

    // Calculate number of days since January 1, 1900
    int num_years = year - 1900;
    int num_leap_years = (num_years - 1) / 4;
    int num_days_since_jan_1_1900 = num_years * 365 + num_leap_years;
    if (month > 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
    {
        num_days_since_jan_1_1900++;
    }
    for (int i = 0; i < month - 1; i++)
    {
        num_days_since_jan_1_1900 += num_days[i];
    }
    num_days_since_jan_1_1900 += day - 1;

    // Calculate day of the week
    int day_of_week = (num_days_since_jan_1_1900 + 1) % 7;

    // Format and print output
    sprintf(output + strlen(output), "%s %d, %d is a ", month_names[month - 1], day, year);
    switch (day_of_week)
    {
        case 0:
            strcat(output, "Sunday");
            break;
        case 1:
            strcat(output, "Monday");
            break;
        case 2:
            strcat(output, "Tuesday");
            break;
        case 3:
            strcat(output, "Wednesday");
            break;
        case 4:
            strcat(output, "Thursday");
            break;
        case 5:
            strcat(output, "Friday");
            break;
        case 6:
            strcat(output, "Saturday");
            break;
    }
    printf("%s\n", output);

    return 0;
}