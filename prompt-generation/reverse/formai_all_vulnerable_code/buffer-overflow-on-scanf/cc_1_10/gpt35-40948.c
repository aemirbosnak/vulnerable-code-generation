//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 25

char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int days_in_month(int month, int year) {
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
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

void date_converter(char *input_date) {
    int day, month, year;
    char *token;
    char *delim = "/";
    char *input_copy = strdup(input_date);

    token = strtok(input_copy, delim);
    month = atoi(token);
    token = strtok(NULL, delim);
    day = atoi(token);
    token = strtok(NULL, delim);
    year = atoi(token);
    free(input_copy);

    printf("Input date: %s\n", input_date);
    printf("Converted to: %s %d, %d\n", months[month-1], day, year);
}

int main(void) {
    char input_date[MAX_LEN];

    printf("Enter date in MM/DD/YYYY format (e.g. 11/24/2021): ");
    scanf("%s", input_date);

    date_converter(input_date);

    return 0;
}