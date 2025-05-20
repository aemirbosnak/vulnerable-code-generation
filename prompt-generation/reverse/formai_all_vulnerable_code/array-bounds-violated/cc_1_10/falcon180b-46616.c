//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LENGTH 64
#define MAX_MONTH_LENGTH 64
#define MAX_YEAR_LENGTH 64

// Function to convert a month number to its name
char *month_name(int month)
{
    static char *month_names[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    return month_names[month - 1];
}

// Function to convert a day number to its name
char *day_name(int day)
{
    static char *day_names[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
    };

    return day_names[day];
}

int main()
{
    char input_date[MAX_DATE_LENGTH];
    int day, month, year;

    // Get user input
    printf("Enter a date in the format DD/MM/YYYY: ");
    scanf("%s", input_date);

    // Parse the date
    if (sscanf(input_date, "%d/%d/%d", &day, &month, &year)!= 3)
    {
        printf("Invalid date format.\n");
        return 1;
    }

    // Convert the date to natural language
    char output_date[MAX_DATE_LENGTH];
    sprintf(output_date, "%s, %d %s %d", day_name(day), day, month_name(month), year);

    // Print the natural language date
    printf("The natural language date is: %s\n", output_date);

    return 0;
}