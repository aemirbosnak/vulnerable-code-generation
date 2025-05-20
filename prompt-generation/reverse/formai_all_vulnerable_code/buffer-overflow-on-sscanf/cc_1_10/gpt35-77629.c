//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

void convertDate(char* str) {
    int day, month, year, daysInMonth;

    sscanf(str, "%d-%d-%d", &day, &month, &year);

    if(month < 1 || month > 12) {
        printf("\nInvalid month!\n");
        return;
    }

    if(day < 1 || day > 31) {
        printf("\nInvalid day!\n");
        return;
    }

    if(month == 2) {
        if(isLeapYear(year)) {
            daysInMonth = 29;
        } else {
            daysInMonth = 28;
        }
    } else if(month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }

    if(day > daysInMonth) {
        printf("\nInvalid day for the given month and year!\n");
        return;
    }

    int days = 0;

    for(int i = 1; i < month; i++) {
        if(i == 2) {
            if(isLeapYear(year)) {
                days += 29;
            } else {
                days += 28;
            }
        } else if(i == 4 || i == 6 || i == 9 || i == 11) {
            days += 30;
        } else {
            days += 31;
        }
    }

    days += day;

    printf("\n%d-%d-%d is the %d day of the year.\n", day, month, year, days);
}

int main() {
    char date[11];

    printf("Enter date in the format DD-MM-YYYY: ");
    scanf("%s", date);

    convertDate(date);

    return 0;
}