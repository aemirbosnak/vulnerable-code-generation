//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: romantic
#include <stdio.h>
#include <string.h>

// Function to calculate the number of days in a given month
int getDaysInMonth(int month, int year) {
    int days;
    if (month == 2) {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            days = 29;
        else
            days = 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days = 30;
    } else {
        days = 31;
    }
    return days;
}

// Function to convert the date from natural language to numeric
void convertToDate(char date[]) {
    int day, month, year;
    char monthName[10];
    sscanf(date, "%d %s %d", &day, monthName, &year);

    if (strcasecmp(monthName, "January") == 0)
        month = 1;
    else if (strcasecmp(monthName, "February") == 0)
        month = 2;
    else if (strcasecmp(monthName, "March") == 0)
        month = 3;
    else if (strcasecmp(monthName, "April") == 0)
        month = 4;
    else if (strcasecmp(monthName, "May") == 0)
        month = 5;
    else if (strcasecmp(monthName, "June") == 0)
        month = 6;
    else if (strcasecmp(monthName, "July") == 0)
        month = 7;
    else if (strcasecmp(monthName, "August") == 0)
        month = 8;
    else if (strcasecmp(monthName, "September") == 0)
        month = 9;
    else if (strcasecmp(monthName, "October") == 0)
        month = 10;
    else if (strcasecmp(monthName, "November") == 0)
        month = 11;
    else
        month = 12;

    printf("\nAh, the %d", day);
    switch (day % 10)
    {
        case 1:
            printf("st");
            break;
        case 2:
            printf("nd");
            break;
        case 3:
            printf("rd");
            break;
        default:
            printf("th");
            break;
    }
    printf(" day of ");

    switch (month)
    {
        case 1:
            printf("January");
            break;
        case 2:
            printf("February");
            break;
        case 3:
            printf("March");
            break;
        case 4:
            printf("April");
            break;
        case 5:
            printf("May");
            break;
        case 6:
            printf("June");
            break;
        case 7:
            printf("July");
            break;
        case 8:
            printf("August");
            break;
        case 9:
            printf("September");
            break;
        case 10:
            printf("October");
            break;
        case 11:
            printf("November");
            break;
        default:
            printf("December");
            break;
    }

    printf(", ");
    // Handle the year in a romantic way.
    if (year > 2021) {
        printf("a year that seems so far away, but closer every time I get to see you.");
    } else if (year == 2021) {
        printf("what a year it has been, full of challenges and yet full of amazing moments shared with you.");
    } else if (year < 2021) {
        printf("a year that reminds me how lucky I am to have you in my life, every day.");
    }

    int daysInMonth = getDaysInMonth(month, year);
    printf(" This month has %d days!", daysInMonth);
}

int main() {
    char date[20];
    printf("Enter a date in natural language (e.g. 20th January 2022): ");
    fgets(date, 20, stdin);

    convertToDate(date);

    return 0;
}