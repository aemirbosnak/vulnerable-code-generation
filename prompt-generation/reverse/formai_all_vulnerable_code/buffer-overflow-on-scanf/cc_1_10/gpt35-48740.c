//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if(year % 4 == 0) {
        if(year % 100 == 0) {
            if(year % 400 == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
}

// Function to convert a date to its corresponding day of the year
int getDayOfYear(int day, int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfYear = 0;
    
    for(int i = 0; i < month - 1; i++) {
        dayOfYear += daysInMonth[i];
    }
    
    if(month > 2 && isLeapYear(year)) {
        dayOfYear += 1;
    }
    
    dayOfYear += day;
    
    return dayOfYear;
}

// Function to convert a day of the year to its corresponding date
void getDay(int dayOfYear, int year, int* day, int* month) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if(isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
    
    int i;
    for(i = 0; i < 12; i++) {
        if(dayOfYear <= daysInMonth[i]) {
            break;
        }
        
        dayOfYear -= daysInMonth[i];
    }
    
    *day = dayOfYear;
    *month = i + 1;
}

int main() {
    int day, month, year;
    
    printf("Enter the date (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);
    
    int dayOfYear = getDayOfYear(day, month, year);
    
    printf("Day of the year: %d\n", dayOfYear);
    
    int newYearDay;
    if(isLeapYear(year)) {
        newYearDay = 366;
    }
    else {
        newYearDay = 365;
    }
    
    int remainingDays = newYearDay - dayOfYear;
    
    int newYear, newMonth, newDay;
    getDay(remainingDays, year + 1, &newDay, &newMonth);
    newYear = year + 1;
    
    printf("Date of next year: %d %d %d\n", newDay, newMonth, newYear);
    
    return 0;
}