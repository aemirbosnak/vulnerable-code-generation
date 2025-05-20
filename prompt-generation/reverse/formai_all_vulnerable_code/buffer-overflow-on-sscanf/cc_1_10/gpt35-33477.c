//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* months[] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"
};

int daysInMonth[] = {
    31, 28, 31, 30, 
    31, 30, 31, 31, 
    30, 31, 30, 31
};

typedef struct date {
    int day;
    int month;
    int year;
} Date;

int isLeapYear(int year) {
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return 1;
    }
    return 0;
}

int isValidDate(Date d) {
    if(d.year < 1 || d.month < 1 || d.month > 12 || d.day < 1) {
        return 0;
    }
    if(d.month == 2 && isLeapYear(d.year) && d.day > 29) {
        return 0;
    }
    if(d.day > daysInMonth[d.month - 1]) {
        return 0;
    }
    return 1;
}

Date getDateFromString(char* str) {
    char dayStr[3];
    char monthStr[10];
    char yearStr[5];
    int day;
    int month;
    int year;
    sscanf(str, "%s %s %s", dayStr, monthStr, yearStr);
    day = atoi(dayStr);
    year = atoi(yearStr);
    for(int i = 0; i < 12; i++) {
        if(strstr(months[i], monthStr)) {
            month = i + 1;
            break;
        }
    }
    Date d = {day, month, year};
    return d;
}

void printDate(Date d) {
    printf("%d %s %d", d.day, months[d.month - 1], d.year);
}

void convertDate(char* input) {
    char* ptr = strtok(input, " ");
    Date d1 = getDateFromString(ptr);
    ptr = strtok(NULL, " ");
    Date d2 = getDateFromString(ptr);
    if(isValidDate(d1) && isValidDate(d2)) {
        printf("\nDate 1: ");
        printDate(d1);
        printf("\n");
        printf("Date 2: ");
        printDate(d2);
        printf("\n");
    } else {
        printf("\nInput contains invalid dates!\n");
        return;
    }
    int diffYears = d2.year - d1.year;
    int diffMonths = d2.month - d1.month;
    int diffDays = d2.day - d1.day;
    if(diffYears == 0 && diffMonths == 0 && diffDays == 0) {
        printf("The two dates are the same!\n");
        return;
    }
    if(diffYears < 0 || (diffYears == 0 && diffMonths < 0) || 
    (diffYears == 0 && diffMonths == 0 && diffDays < 0)) {
        printf("Date 2 is earlier than Date 1!\n");
        return;
    }
    if(diffDays < 0) {
        diffMonths--;
        diffDays += daysInMonth[d1.month - 1];
    }
    if(diffMonths < 0) {
        diffYears--;
        diffMonths += 12;
    }
    if(diffYears > 0) {
        printf("%d year", diffYears);
        if(diffYears > 1) {
            printf("s");
        }
        printf(", ");
    }
    if(diffMonths > 0) {
        printf("%d month", diffMonths);
        if(diffMonths > 1) {
            printf("s");
        }
        printf(", ");
    }
    if(diffDays > 0) {
        printf("%d day", diffDays);
        if(diffDays > 1) {
            printf("s");
        }
    }
    printf("\n");
}

int main() {
    char input[100];
    printf("Enter two dates (date 1 and date 2) separated by space in the format 'DD Month YYYY': \n");
    fgets(input, 100, stdin);
    convertDate(input);
    return 0;
}