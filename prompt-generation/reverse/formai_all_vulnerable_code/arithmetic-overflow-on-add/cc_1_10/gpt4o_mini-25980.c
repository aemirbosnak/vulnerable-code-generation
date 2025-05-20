//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

// Function to check if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a month
int daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isLeapYear(year) ? 29 : 28;
        default: return 0; // Invalid month
    }
}

// Function to add time jumps
void timeTravel(Date *date, int years, int months, int days) {
    // Adjust months
    date->year += years;
    date->month += months;
    
    // Adjust year and months
    while (date->month > 12) {
        date->month -= 12;
        date->year++;
    }
    
    // Adjust days
    date->day += days;
    while (date->day > daysInMonth(date->month, date->year)) {
        date->day -= daysInMonth(date->month, date->year);
        date->month++;
        if (date->month > 12) {
            date->month = 1;
            date->year++;
        }
    }
}

// Function to display date
void displayDate(const Date *date) {
    printf("Time Travel Result: %04d-%02d-%02d\n", date->year, date->month, date->day);
}

int main() {
    Date currentDate;
    int years, months, days;
    char direction[10];

    // Input current date
    printf("Enter current date (YYYY MM DD): ");
    scanf("%d %d %d", &currentDate.year, &currentDate.month, &currentDate.day);
    
    // Input direction of time travel
    printf("Would you like to travel forward or backward in time? (Enter 'forward' or 'backward'): ");
    scanf("%s", direction);

    // Input time jumps
    printf("Enter years, months, and days to travel:\n");
    printf("Years: "); scanf("%d", &years);
    printf("Months: "); scanf("%d", &months);
    printf("Days: "); scanf("%d", &days);
    
    // Adjust signs based on travel direction
    if (strcmp(direction, "backward") == 0) {
        years = -years;
        months = -months;
        days = -days;
    }

    // Perform the time travel
    timeTravel(&currentDate, years, months, days);
    
    // Display the result
    displayDate(&currentDate);

    return 0;
}