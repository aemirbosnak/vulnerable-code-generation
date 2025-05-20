//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: happy
// Happy Date Converter Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

// Function to validate month input
int isValidMonth(int month) {
    if (month < 1 || month > 12) {
        return 0;
    }
    return 1;
}

// Function to validate day input for given month and year
int isValidDay(int day, int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    return day <= daysInMonth[month - 1];
}

// Function to convert string date to Date struct
Date stringToDate(char* dateStr) {
    Date result;
    int year, month, day;
    sscanf(dateStr, "%d/%d/%d", &month, &day, &year);

    if (isValidMonth(month) && isValidDay(day, month, year)) {
        result.year = year;
        result.month = month;
        result.day = day;
    } else {
        printf("Invalid date: %s\n", dateStr);
        exit(1);
    }

    return result;
}

int main() {
    char dateStr[30];
    Date myBirthday;

    printf("Enter your birthday in format MM/DD/YYYY: ");
    fgets(dateStr, sizeof(dateStr), stdin);
    dateStr[strcspn(dateStr, "\n")] = '\0';

    myBirthday = stringToDate(dateStr);

    printf("Your birthday is: %02d/%02d/%d\n", myBirthday.month, myBirthday.day, myBirthday.year);

    return 0;
}