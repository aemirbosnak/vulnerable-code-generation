//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function to check if input is a valid date
int is_valid_date(int day, int month, int year) {
    if (month < 1 || month > 12) {
        return 0;
    }
    switch (month) {
        case 4:
        case 6:
        case 9:
        case 11:
            if (day < 1 || day > 30) {
                return 0;
            }
            break;
        default:
            if (day < 1 || day > 31) {
                return 0;
            }
            break;
    }
    if (year < 1000 || year > 9999) {
        return 0;
    }
    return 1;
}

// Function to convert date to natural language format
void date_to_natural_language(int day, int month, int year) {
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Today is %s %d, %d\n", months[month - 1], day, year);
}

int main() {
    int day, month, year;
    printf("Please enter the current date in the format DD/MM/YYYY: ");
    if (scanf("%d/%d/%d", &day, &month, &year)!= 3) {
        printf("Invalid input\n");
        return 1;
    }
    if (!is_valid_date(day, month, year)) {
        printf("Invalid date\n");
        return 1;
    }
    date_to_natural_language(day, month, year);
    return 0;
}