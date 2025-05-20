//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct to hold the date
typedef struct
{
    int day;
    int month;
    int year;
} Date;

// Function to convert a string to a date
Date stringToDate(char *str)
{
    Date date;

    // Get the day
    date.day = atoi(strtok(str, "/"));

    // Get the month
    date.month = atoi(strtok(NULL, "/"));

    // Get the year
    date.year = atoi(strtok(NULL, "/"));

    return date;
}

// Function to convert a date to a string
char *dateToString(Date date)
{
    char *str = malloc(11);

    // Convert the day to a string
    sprintf(str, "%d/", date.day);

    // Convert the month to a string
    sprintf(str, "%s%d/", str, date.month);

    // Convert the year to a string
    sprintf(str, "%s%d", str, date.year);

    return str;
}

// Function to compare two dates
int compareDates(Date date1, Date date2)
{
    if (date1.year != date2.year)
    {
        return date1.year - date2.year;
    }
    else if (date1.month != date2.month)
    {
        return date1.month - date2.month;
    }
    else
    {
        return date1.day - date2.day;
    }
}

// Function to print the date in a different format
void printDate(Date date)
{
    printf("%d-%d-%d\n", date.day, date.month, date.year);
}

// Main function
int main()
{
    // Get the date from the user
    char *str = malloc(11);
    printf("Enter the date in the format dd/mm/yyyy: ");
    scanf("%s", str);

    // Convert the string to a date
    Date date = stringToDate(str);

    // Print the date in a different format
    printDate(date);

    return 0;
}