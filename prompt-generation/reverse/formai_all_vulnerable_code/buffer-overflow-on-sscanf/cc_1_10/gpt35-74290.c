//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: careful
#include <stdio.h>
#include <string.h>

int monthToInt(char month[]);
int daysInMonth(int month, int year);
int isLeapYear(int year);
char* intToMonth(int month);

int main() {
    int day, year, month;
    char date[12];
    printf("Enter date in natural language format (e.g. January 1, 2022): ");
    fgets(date, 12, stdin);

    // Parsing the input
    char monthName[10];
    sscanf(date, "%s %d, %d", monthName, &day, &year);
    month = monthToInt(monthName);

    // Date validation
    if (month == 0 || day < 1 || day > daysInMonth(month, year)) {
        printf("Invalid date\n");
        return 1;
    }

    // Converting to ISO date format
    printf("Input date: %s", date);
    printf("Output date: %04d-%02d-%02d\n", year, month, day);
    return 0;
}

int monthToInt(char month[]) {
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < 12; i++) {
        if (strcmp(month, months[i]) == 0) {
            return i + 1;
        }
    }
    return 0;
}

int daysInMonth(int month, int year) {
    int days[12] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[month - 1];
}

int isLeapYear(int year) {
    if (year % 400 == 0) {
        return 1;
    } else if (year % 100 == 0) {
        return 0;
    } else if (year % 4 == 0) {
        return 1;
    } else {
        return 0;
    }
}

char* intToMonth(int month) {
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[month - 1];
}