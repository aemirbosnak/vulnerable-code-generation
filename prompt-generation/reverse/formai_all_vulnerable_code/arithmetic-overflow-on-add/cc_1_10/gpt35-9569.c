//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to get day of week
int getDayOfWeek(int y, int m, int d) {
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

// function to check if given year is a leap year or not
int isLeapYear(int year) {
    if (year % 4 != 0) return 0;
    else if (year % 100 != 0) return 1;
    else if (year % 400 != 0) return 0;
    else return 1;
}

// function to convert date in string format to integer format
void convertDate(char *dateString, int *day, int *month, int *year) {
    char dayString[3];
    char monthString[3];
    char yearString[5];
    int i = 0, j = 0;
    while (dateString[i] != '/') {
        dayString[j] = dateString[i];
        i++;
        j++;
    }
    dayString[j] = '\0';
    j = 0;
    i++;
    while (dateString[i] != '/') {
        monthString[j] = dateString[i];
        i++;
        j++;
    }
    monthString[j] = '\0';
    j = 0;
    i++;
    while (dateString[i] != '\0') {
        yearString[j] = dateString[i];
        i++;
        j++;
    }
    yearString[j] = '\0';
    *day = atoi(dayString);
    *month = atoi(monthString);
    *year = atoi(yearString);
}

// function to convert integer format date to string format
void convertToDateString(int day, int month, int year, char *dateString) {
    char dayString[3];
    char monthString[3];
    char yearString[5];
    sprintf(dayString, "%d", day);
    sprintf(monthString, "%d", month);
    sprintf(yearString, "%d", year);
    strcat(dayString, "/");
    strcat(dayString, monthString);
    strcat(dayString, "/");
    strcat(dayString, yearString);
    strcpy(dateString, dayString);
}

// function to add given number of days to the given date
void addDaysToDate(int daysToAdd, int *day, int *month, int *year) {
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(*year)) daysInMonth[1] = 29;
    while (daysToAdd > 0) {
        if (*day + daysToAdd <= daysInMonth[*month - 1]) {
            *day += daysToAdd;
            daysToAdd = 0;
        } else {
            daysToAdd -= (daysInMonth[*month - 1] - *day + 1);
            *day = 1;
            *month += 1;
            if (*month > 12) {
                *month = 1;
                *year += 1;
                if (isLeapYear(*year)) daysInMonth[1] = 29;
                else daysInMonth[1] = 28;
            }
        }
    }
}

int main() {
    char dateString[11];
    printf("Enter a date in dd/mm/yyyy format: ");
    scanf("%s", dateString);
    int day, month, year;
    convertDate(dateString, &day, &month, &year);
    char dayOfWeek[10][50] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int dayIndex = getDayOfWeek(year, month, day);
    printf("The day of the week is %s.\n", dayOfWeek[dayIndex]);
    printf("How many days you want to add to the given date: ");
    int daysToAdd;
    scanf("%d", &daysToAdd);
    addDaysToDate(daysToAdd, &day, &month, &year);
    convertToDateString(day, month, year, dateString);
    printf("The new date after adding %d days is %s.\n", daysToAdd, dateString);
    return 0;
}