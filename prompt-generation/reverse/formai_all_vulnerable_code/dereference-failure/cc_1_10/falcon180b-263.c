//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 20
#define MONTH_NAMES_LENGTH 12

typedef struct {
    char *month_name;
    int month_number;
} Month;

Month months[MONTH_NAMES_LENGTH] = {
    {"January", 1},
    {"February", 2},
    {"March", 3},
    {"April", 4},
    {"May", 5},
    {"June", 6},
    {"July", 7},
    {"August", 8},
    {"September", 9},
    {"October", 10},
    {"November", 11},
    {"December", 12}
};

int is_valid_date(int day, int month, int year) {
    if (month < 1 || month > 12) {
        return 0;
    }

    switch (month) {
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

    if (month == 2) {
        if (day > 29 &&!(year % 4 == 0 && (year % 100!= 0 || year % 400 == 0))) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[100];
    char *token;
    int day, month, year;

    printf("Enter a date in the format DD/MM/YYYY: ");
    fgets(input, sizeof(input), stdin);

    token = strtok(input, "/");
    day = atoi(token);

    token = strtok(NULL, "/");
    month = atoi(token);

    token = strtok(NULL, "/");
    year = atoi(token);

    if (!is_valid_date(day, month, year)) {
        printf("Invalid date\n");
        return 1;
    }

    printf("Date entered: %d/%s/%d\n", day, months[month - 1].month_name, year);

    return 0;
}