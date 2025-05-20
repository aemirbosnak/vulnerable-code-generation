//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int getMonthDays(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int dateToDays(int day, int month, int year) {
    int days = 0;
    for (int i = 1; i < year; i++) {
        days += isLeapYear(i) ? 366 : 365;
    }
    for (int i = 1; i < month; i++) {
        days += getMonthDays(i, year);
    }
    days += day;
    return days;
}

void daysToDate(int days, int* day, int* month, int* year) {
    int daysInYear;
    for (*year = 1; ; (*year)++) {
        daysInYear = isLeapYear(*year) ? 366 : 365;
        if (days < daysInYear) {
            break;
        }
        days -= daysInYear;
    }  
    for (*month = 1; ; (*month)++) {
        int daysInMonth = getMonthDays(*month, *year);
        if (days < daysInMonth) {
            break;
        }
        days -= daysInMonth;
    }  
    *day = days;
}

int main() {
    int day1, month1, year1, day2, month2, year2;
    char dateStr[11];
    char* delim = "-";

    printf("Enter the date in format DD-MM-YYYY:\n");
    scanf("%s", dateStr);

    char* str = strtok(dateStr, delim);
    day1 = atoi(str);

    str = strtok(NULL, delim);
    month1 = atoi(str);

    str = strtok(NULL, delim);
    year1 = atoi(str);

    printf("Enter the number of days to add:\n");
    scanf("%d", &day2);

    daysToDate(dateToDays(day1, month1, year1) + day2, &day2, &month2, &year2);

    printf("Result: %d-%02d-%02d\n", day2, month2, year2);

    return 0;
}