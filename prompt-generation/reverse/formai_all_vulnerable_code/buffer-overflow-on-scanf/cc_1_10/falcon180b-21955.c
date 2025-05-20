//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define MONTHS 12

struct tm get_date(char* input);
int validate_date(char* input);
int convert_to_number(char* input);
int is_valid_month(int month);

int main() {
    char input[MAX_LENGTH];
    printf("Enter a date in the format of 'dd/mm/yyyy': ");
    scanf("%s", input);
    
    if (validate_date(input)) {
        struct tm date = get_date(input);
        printf("The date '%s' is %d/%d/%d.\n", input, date.tm_mday, date.tm_mon + 1, date.tm_year + 1900);
    } else {
        printf("Invalid date.\n");
    }

    return 0;
}

struct tm get_date(char* input) {
    struct tm date = {0};
    int day, month, year;
    int i = 0;
    while (input[i]!= '/') {
        if (isdigit(input[i])) {
            if (i == 0) {
                day = input[i] - '0';
            } else if (i == 2) {
                month = input[i] - '0';
            } else if (i == 5) {
                year = input[i] - '0';
            }
        }
        i++;
    }
    date.tm_mday = day;
    date.tm_mon = month - 1;
    date.tm_year = year - 1900;
    return date;
}

int validate_date(char* input) {
    int i = 0;
    while (input[i]!= '\0') {
        if (!isdigit(input[i]) && input[i]!= '/') {
            return 0;
        }
        i++;
    }
    return 1;
}

int convert_to_number(char* input) {
    int i = 0;
    int number = 0;
    while (input[i]!= '\0') {
        if (isdigit(input[i])) {
            number = number * 10 + input[i] - '0';
        } else {
            return 0;
        }
        i++;
    }
    return number;
}

int is_valid_month(int month) {
    if (month < 1 || month > 12) {
        return 0;
    }
    return 1;
}