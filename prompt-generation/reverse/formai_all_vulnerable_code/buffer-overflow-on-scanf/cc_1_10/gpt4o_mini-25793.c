//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

void displayDate(Date date) {
    printf("Date: %04d-%02d-%02d\n", date.year, date.month, date.day);
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int year, int month) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0; // Invalid month
    }
}

Date travelTime(Date currentDate, int years, int months, int days) {
    Date newDate = currentDate;

    // Move the date forward by days
    newDate.day += days;
    while (newDate.day > getDaysInMonth(newDate.year, newDate.month)) {
        newDate.day -= getDaysInMonth(newDate.year, newDate.month);
        newDate.month++;
        if (newDate.month > 12) {
            newDate.month = 1;
            newDate.year++;
        }
    }

    // Move the date forward by months
    newDate.month += months;
    while (newDate.month > 12) {
        newDate.month -= 12;
        newDate.year++;
    }

    // Move the date forward by years
    newDate.year += years;

    return newDate;
}

void simulateTimeTravel() {
    Date currentDate;
    printf("Enter the current date (YYYY MM DD): ");
    scanf("%d %d %d", &currentDate.year, &currentDate.month, &currentDate.day);

    printf("You are currently in ");
    displayDate(currentDate);
    
    int years, months, days;
    printf("Enter how many years, months, and days you want to travel into the future (YYYY MM DD): ");
    scanf("%d %d %d", &years, &months, &days);
    
    Date traveledDate = travelTime(currentDate, years, months, days);
    printf("You have traveled to ");
    displayDate(traveledDate);
}

int main() {
    printf("Welcome to the Time Travel Simulator!\n");
    simulateTimeTravel();
    
    return 0;
}