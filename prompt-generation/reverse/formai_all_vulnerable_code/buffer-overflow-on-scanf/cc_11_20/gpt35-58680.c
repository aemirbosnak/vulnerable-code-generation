//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

int getMonthCode(int month, int year) {
    // this function will return the month code based on the given month and year
    int code = 0;
    if (month == 1 || month == 10) {
        code = 0;
    } else if (month == 2 || month == 3 || month == 11) {
        code = 3;
    } else if (month == 4 || month == 7) {
        code = 6;
    } else if (month == 5) {
        code = 1;
    } else if (month == 6) {
        code = 4;
    } else if (month == 8) {
        code = 2;
    } else if (month == 9 || month == 12) {
        code = 5;
    }
    if (year % 4 == 0 && month <= 2) {
        code--;
    }
    return code;
}

int main() {
    int day, month, year, dayCode, monthCode, yearCode, centuryCode, dateCode, totalDays;
    printf("Enter date (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);

    // calculate day code
    dayCode = day % 7;

    // calculate month code
    monthCode = getMonthCode(month, year);

    // calculate year code and century code
    yearCode = year % 100;
    centuryCode = year / 100;
    if (centuryCode % 4 == 0) {
        centuryCode = 6;
    } else if (centuryCode % 4 == 1) {
        centuryCode = 4;
    } else if (centuryCode % 4 == 2) {
        centuryCode = 2;
    } else if (centuryCode % 4 == 3) {
        centuryCode = 0;
    }
    yearCode = yearCode + (yearCode/4);
    yearCode = yearCode + centuryCode;

    // calculate date code
    dateCode = dayCode + monthCode + yearCode;
    totalDays = dateCode % 7;

    // print the day of the week
    printf("The date %02d-%02d-%04d is a ", day, month, year);
    switch(totalDays) {
        case 0:
            printf("Sunday.\n");
            break;
        case 1:
            printf("Monday.\n");
            break;
        case 2:
            printf("Tuesday.\n");
            break;
        case 3:
            printf("Wednesday.\n");
            break;
        case 4:
            printf("Thursday.\n");
            break;  
        case 5:
            printf("Friday.\n");
            break;
        case 6:
            printf("Saturday.\n");
            break;          
    }
    return 0;
}