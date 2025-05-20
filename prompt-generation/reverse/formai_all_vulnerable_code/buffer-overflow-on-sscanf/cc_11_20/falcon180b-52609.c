//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_DATE_LENGTH 100
#define MAX_MONTH_LENGTH 9
#define MAX_YEAR_LENGTH 4

int main() {
    char input_date[MAX_DATE_LENGTH];
    char month[MAX_MONTH_LENGTH];
    char day[MAX_DATE_LENGTH];
    char year[MAX_YEAR_LENGTH];
    struct tm date_struct;

    // Prompt the user to enter a date in the format "MM/DD/YYYY"
    printf("Enter a date in the format \"MM/DD/YYYY\": ");
    fgets(input_date, MAX_DATE_LENGTH, stdin);

    // Extract the month, day, and year from the input date
    sscanf(input_date, "%s %s %s", month, day, year);

    // Convert the month to an integer value
    int month_num = atoi(month);

    // Check if the input date is valid
    if (strlen(month)!= 2 || strlen(day)!= 2 || strlen(year)!= 4) {
        printf("Invalid date format.\n");
        return 1;
    }
    if (month_num < 1 || month_num > 12) {
        printf("Invalid month.\n");
        return 1;
    }
    if (isdigit(month[0]) == 0 || isdigit(month[1]) == 0 || isdigit(day[0]) == 0 || isdigit(day[1]) == 0 || isdigit(year[0]) == 0 || isdigit(year[1]) == 0 || isdigit(year[2]) == 0 || isdigit(year[3]) == 0) {
        printf("Invalid date.\n");
        return 1;
    }

    // Set the date components in the tm structure
    date_struct.tm_mon = month_num - 1;
    date_struct.tm_mday = atoi(day);
    date_struct.tm_year = atoi(year) - 1900;

    // Check if the input date is a valid date
    time_t input_time = mktime(&date_struct);
    if (input_time == -1) {
        printf("Invalid date.\n");
        return 1;
    }

    // Convert the date to a natural language format
    char natural_date[MAX_DATE_LENGTH];
    strftime(natural_date, MAX_DATE_LENGTH, "Today is %A, %B %d, %Y.", &date_struct);

    // Print the natural language date
    printf("The natural language date is: %s\n", natural_date);

    return 0;
}