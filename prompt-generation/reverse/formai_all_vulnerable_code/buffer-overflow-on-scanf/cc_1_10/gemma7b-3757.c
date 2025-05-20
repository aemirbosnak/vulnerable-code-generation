//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *month_name(int month)
{
    switch (month)
    {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
    }
}

int main()
{
    char date_str[20];
    printf("Enter the date in the format YYYY-MM-DD: ");
    scanf("%s", date_str);

    // Validate the input
    if (strlen(date_str) != 10)
    {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    int year, month, day;
    year = atoi(date_str);
    month = atoi(date_str + 5);
    day = atoi(date_str + 8);

    // Create a time structure
    time_t t = mktime(NULL);
    struct tm *tm = localtime(&t);

    // Set the time structure parameters
    tm->tm_year = year - 1900;
    tm->tm_mon = month - 1;
    tm->tm_mday = day;

    // Convert the time structure to a date string
    char date_out[100];
    strftime(date_out, 100, "On %A, %B %d, %Y", tm);

    // Print the date
    printf("The date is: %s\n", date_out);

    return 0;
}