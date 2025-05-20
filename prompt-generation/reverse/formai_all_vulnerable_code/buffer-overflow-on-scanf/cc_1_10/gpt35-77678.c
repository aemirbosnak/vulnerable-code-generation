//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: protected
#include <stdio.h>

// function to check if a year is a leap year
int isLeapYear(int year) {
    if (year % 4 != 0) {
        return 0;
    } else if (year % 100 != 0) {
        return 1;
    } else if (year % 400 != 0) {
        return 0;
    } else {
        return 1;
    }
}

// function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

// function to get the next day
void getNextDay(int *day, int *month, int *year) {
    // get the number of days in the current month
    int daysInMonth = getDaysInMonth(*month, *year);
    
    // increment the day
    (*day)++;
    
    // if the day is greater than the number of days in the month, go to the next month
    if (*day > daysInMonth) {
        (*day) = 1;
        (*month)++;
    }
    
    // if the month is greater than 12, go to the next year
    if (*month > 12) {
        (*month) = 1;
        (*year)++;
    }
}

int main() {
    // initialize the starting date
    int day = 1;
    int month = 1;
    int year = 1990;
    
    // ask the user how many days they want to travel
    int daysToTravel;
    printf("How many days do you want to travel? ");
    scanf("%d", &daysToTravel);
    
    // travel to the future
    for (int i = 0; i < daysToTravel; i++) {
        getNextDay(&day, &month, &year);
    }
    
    // print the new date
    printf("You have traveled to %02d/%02d/%04d\n", month, day, year);
    
    return 0;
}