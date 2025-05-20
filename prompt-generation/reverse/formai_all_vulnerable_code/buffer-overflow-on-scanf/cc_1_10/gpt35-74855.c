//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

enum Month {
    January = 1, February, March, April, May, June, July, August, September, October, November, December
};

/*
 * Function to check if a year is a leap year.
 * A year is a leap year if it is divisible by 4 but not by 100 or if it is divisible by 400.
 */
int is_leap(int year) {
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

/*
 * Function to get the number of days in a month for a given year.
 */
int month_days(int month, int year) {
    switch(month) {
        case February:
            if(is_leap(year))
                return 29;
            else
                return 28;
            break;
        case April:
        case June:
        case September:
        case November:
            return 30;
            break;
        default:
            return 31;
            break;
    }
}

/*
 * Function to convert a striing to a date struct.
 * Expects string to be in the format dd/mm/yyyy.
 */
struct Date string_to_date(char *str) {
    struct Date date;
    char *token;
    token = strtok(str, "/");
    date.day = atoi(token);
    token = strtok(NULL, "/");
    date.month = atoi(token);
    token = strtok(NULL, "/");
    date.year = atoi(token);
    return date;
}

/*
 * Function to convert a date struct to a string in the format dd/mm/yyyy.
 */
char *date_to_string(struct Date date) {
    char *str;
    str = (char*) malloc(11*sizeof(char)); // allocate 11 bytes for string (dd/mm/yyyy plus null)
    sprintf(str, "%02d/%02d/%04d", date.day, date.month, date.year);
    return str;
}

/*
 * Increase a date by a certain number of days.
 */
struct Date increase_days(struct Date date, int days) {
    int max_days;
    while(days > 0) {
        max_days = month_days(date.month, date.year) - date.day + 1;
        if(days >= max_days) {
            date.month++;
            if(date.month > December) {  // if we go over december, wrap around to January of next year
                date.month = January;
                date.year++;
            }
            date.day = 1;
            days -= max_days;
        } else {
            date.day += days;
            days = 0;
        }
    }
    return date;
}

/*
 * Decrease a date by a certain number of days.
 */
struct Date decrease_days(struct Date date, int days) {
    while(days > 0) {
        if(days >= date.day) {  // if remaining days is greater than number of days in month, we need to go back to previous month
            date.month--;
            if(date.month < January) {  // if we go before January, wrap around to December of previous year
                date.month = December;
                date.year--;
            }
            days -= date.day;
            date.day = month_days(date.month, date.year);
        } else {
            date.day -= days;
            days = 0;
        }
    }
    return date;
}

int main() {
    char str_date[11];
    int days, option;

    // get user input
    printf("Enter a date in the format dd/mm/yyyy: ");
    scanf("%s", str_date);
    printf("Enter an option:\n");
    printf("1. Add days to the date.\n");
    printf("2. Subtract days from the date.\n");
    scanf("%d", &option);
    printf("Enter number of days: ");
    scanf("%d", &days);

    // convert string to date struct
    struct Date date = string_to_date(str_date);

    // perform selected operation
    if(option == 1) {
        date = increase_days(date, days);
    } else if(option == 2) {
        date = decrease_days(date, days);
    } else {
        printf("Invalid option!");
        return 0;
    }

    // convert date struct to string and print result
    char *new_date = date_to_string(date);
    printf("Result: %s\n", new_date);

    // free memory
    free(new_date);

    return 0;
}