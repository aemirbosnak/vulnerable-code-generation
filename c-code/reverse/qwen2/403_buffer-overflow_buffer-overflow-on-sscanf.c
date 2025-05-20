#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12) return 0;
    if (day < 1) return 0;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return 0;
    if (month == 2) {
        if (isLeapYear(year)) {
            if (day > 29) return 0;
        } else {
            if (day > 28) return 0;
        }
    } else {
        if (day > 31) return 0;
    }
    return 1;
}

int main() {
    char input[50];
    int day, month, year;

    printf("Enter a date in the format DD-MM-YYYY: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d-%d-%d", &day, &month, &year);

    if (!isValidDate(day, month, year)) {
        printf("Invalid date. Please enter a valid date.\n");
        return 1;
    }

    printf("Time travel to %d-%02d-%04d confirmed!\n", day, month, year);

    return 0;
}
