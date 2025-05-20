//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: secure
#include <stdio.h>
#include <string.h>

int main()
{
    char input[50];
    int month, day, year;

    printf("Enter a date in natural language (e.g. December 5, 2022): ");
    fgets(input, 50, stdin);

    // Convert month to integer
    if (strstr(input, "January"))
        month = 1;
    else if (strstr(input, "February"))
        month = 2;
    else if (strstr(input, "March"))
        month = 3;
    else if (strstr(input, "April"))
        month = 4;
    else if (strstr(input, "May"))
        month = 5;
    else if (strstr(input, "June"))
        month = 6;
    else if (strstr(input, "July"))
        month = 7;
    else if (strstr(input, "August"))
        month = 8;
    else if (strstr(input, "September"))
        month = 9;
    else if (strstr(input, "October"))
        month = 10;
    else if (strstr(input, "November"))
        month = 11;
    else if (strstr(input, "December"))
        month = 12;

    // Get day
    char *day_ptr = strstr(input, " ") + 1;
    day_ptr = strstr(day_ptr, " ") + 1;
    day = atoi(day_ptr);

    // Get year
    char *year_ptr = strstr(input, " ") + 1;
    year_ptr = strstr(year_ptr, ",") + 2;
    year = atoi(year_ptr);

    // Print converted date
    printf("The converted date is: %d/%d/%d\n", month, day, year);

    return 0;
}