//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* month_name(int month) {
    char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[month];
}

int days_in_month(int year, int month) {
    if (month == 2) {
        if (year % 4 == 0 && year % 100!= 0 || year % 400 == 0) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int main() {
    char input[100];
    printf("Enter a date (MM/DD/YYYY): ");
    scanf("%s", input);

    int day, month, year;
    int i = 0;
    while (input[i]!= '/') {
        if (!isdigit(input[i])) {
            printf("Invalid date format.\n");
            return 1;
        }
        day = day * 10 + input[i] - '0';
        i++;
    }
    i++;
    while (input[i]!= '/') {
        if (!isdigit(input[i])) {
            printf("Invalid date format.\n");
            return 1;
        }
        month = month * 10 + input[i] - '0';
        i++;
    }
    i++;
    while (input[i]!= '\0') {
        if (!isdigit(input[i])) {
            printf("Invalid date format.\n");
            return 1;
        }
        year = year * 10 + input[i] - '0';
        i++;
    }

    if (day < 1 || day > days_in_month(year, month)) {
        printf("Invalid day.\n");
        return 1;
    }

    printf("The date %s is %s %d, %d.\n", input, month_name(month), day, year);

    return 0;
}