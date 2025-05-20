//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define DAYS_IN_MONTH(month, year) (month == 2 && ((year % 4 == 0 && year % 100!= 0) || year % 400 == 0))? 29 : (month == 4 || month == 6 || month == 9 || month == 11)? 30 : 31

int is_valid_date(int day, int month, int year) {
    if (month < 1 || month > 12) {
        return 0;
    }

    switch (month) {
        case 2:
            if (day > DAYS_IN_MONTH(month, year)) {
                return 0;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day > 30) {
                return 0;
            }
            break;
        default:
            if (day > 31) {
                return 0;
            }
            break;
    }

    return 1;
}

int main() {
    char input[MAX_LENGTH];
    int day, month, year;

    printf("Enter a date in the format 'DD/MM/YYYY': ");
    fgets(input, MAX_LENGTH, stdin);

    sscanf(input, "%d/%d/%d", &day, &month, &year);

    if (is_valid_date(day, month, year)) {
        printf("Valid date.\n");
    } else {
        printf("Invalid date.\n");
    }

    return 0;
}