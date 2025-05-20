//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define the weekdays and months in a constant arrays
const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

//function to validate if the year is a leap year
int isLeap(int year) {
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}

//function to convert a date to its corresponding day number
int toDayNum(int day, int month, int year) {
    int dayNum = 0;
    int i;

    //calculate days in previous months
    for (i = 1; i < month; i++) {
        if (i == 2) {
            if (isLeap(year))
                dayNum += 29;
            else
                dayNum += 28;
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11)
            dayNum += 30;
        else
            dayNum += 31;
    }

    //add remaining days in current month
    dayNum += day;

    //add leap day if present and month is after february
    if (isLeap(year) && month > 2)
        dayNum += 1;

    return dayNum;
}

//function to convert a day number to its corresponding date 
void toDate(int dayNum, int year, int *month, int *day) {
    int daysInMonth, i;

    //if leap year, feb has 29 days instead of 28
    if (isLeap(year))
        daysInMonth = 29;
    else
        daysInMonth = 28;

    //calculate days in each month until we find the right one
    for (i = 1; i <= 12; i++) {
        if (i == 2)
            daysInMonth = isLeap(year) ? 29 : 28;
        else if (i == 4 || i == 6 || i == 9 || i == 11)
            daysInMonth = 30;
        else
            daysInMonth = 31;

        if (dayNum <= daysInMonth)
            break;

        dayNum -= daysInMonth;
    }

    *month = i;
    *day = dayNum;
}

int main() {
    //variable declarations
    char input[20];
    int day, month, year, dayNum;

    //get input from user
    printf("Enter a date (dd/mm/yyyy): ");
    fgets(input, 20, stdin);

    //parse the input string into day, month and year variables
    sscanf(input, "%d/%d/%d", &day, &month, &year);

    //get the day number for the given date
    dayNum = toDayNum(day, month, year);

    //get the corresponding date for the given day number
    toDate(dayNum, year, &month, &day);

    //print the resulting date and day of the week
    printf("Date: %s %d, %d\n", months[month-1], day, year);
    printf("Day: %s\n", days[dayNum % 7]);

    return 0;
}