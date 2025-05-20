//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
char *get_month(int month);
char *get_day_of_week(int day_of_week);
void display_date(int day, int month, int year);

int main() {
    int day, month, year;

    // Get user input for date
    printf("Enter the day (1-31): ");
    scanf("%d", &day);
    printf("Enter the month (1-12): ");
    scanf("%d", &month);
    printf("Enter the year (e.g. 2022): ");
    scanf("%d", &year);

    // Convert to natural language format
    char *month_str = get_month(month);
    char *day_of_week = get_day_of_week(day);

    // Display the date in natural language format
    printf("\nToday is %s, %s %d, %d.\n", day_of_week, month_str, day, year);

    return 0;
}

// Function to get the name of the month
char *get_month(int month) {
    switch (month) {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "Invalid month";
    }
}

// Function to get the name of the day of the week
char *get_day_of_week(int day_of_week) {
    switch (day_of_week) {
        case 1: return "Sunday";
        case 2: return "Monday";
        case 3: return "Tuesday";
        case 4: return "Wednesday";
        case 5: return "Thursday";
        case 6: return "Friday";
        case 7: return "Saturday";
        default: return "Invalid day of the week";
    }
}

// Function to display the date in natural language format
void display_date(int day, int month, int year) {
    printf("Today is %s, %s %d, %d.\n", get_day_of_week(day), get_month(month), day, year);
}