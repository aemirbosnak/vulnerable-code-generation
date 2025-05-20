//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATE_LENGTH 20

struct date {
    int day;
    int month;
    int year;
};

struct date parse_date(char* date_str) {
    struct date date;
    char* token;
    int count = 0;

    token = strtok(date_str, " ");
    while (token!= NULL) {
        switch (count) {
            case 0:
                date.day = atoi(token);
                break;
            case 1:
                date.month = atoi(token);
                break;
            case 2:
                date.year = atoi(token);
                break;
            default:
                break;
        }
        count++;
        token = strtok(NULL, " ");
    }

    return date;
}

char* format_date(struct date date) {
    char* date_str;
    char* month_str;
    char* day_str;

    switch (date.month) {
        case 1:
            month_str = "January";
            break;
        case 2:
            month_str = "February";
            break;
        case 3:
            month_str = "March";
            break;
        case 4:
            month_str = "April";
            break;
        case 5:
            month_str = "May";
            break;
        case 6:
            month_str = "June";
            break;
        case 7:
            month_str = "July";
            break;
        case 8:
            month_str = "August";
            break;
        case 9:
            month_str = "September";
            break;
        case 10:
            month_str = "October";
            break;
        case 11:
            month_str = "November";
            break;
        case 12:
            month_str = "December";
            break;
    }

    date_str = malloc(MAX_DATE_LENGTH);
    sprintf(date_str, "%s %d, %d", month_str, date.day, date.year);

    return date_str;
}

int main() {
    char* input_date;
    struct date date;
    char* formatted_date;

    printf("Enter a date in the format dd/mm/yyyy: ");
    scanf("%s", input_date);

    date = parse_date(input_date);
    formatted_date = format_date(date);

    printf("Formatted date: %s\n", formatted_date);

    return 0;
}