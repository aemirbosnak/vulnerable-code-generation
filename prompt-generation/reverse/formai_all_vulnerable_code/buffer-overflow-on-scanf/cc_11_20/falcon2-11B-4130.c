//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_date(char *date, char *format) {
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days_in_week[7] = {0, 1, 2, 3, 4, 5, 6};
    int days_in_year = 365;

    char* date_parts[3] = {strtok(date, " "), strtok(NULL, " "), strtok(NULL, " ")};
    char* month_parts[3] = {strtok(date_parts[0], "-"), strtok(NULL, "-"), strtok(NULL, "-")};
    char* day_parts[3] = {strtok(date_parts[1], " "), strtok(NULL, " "), strtok(NULL, " ")};

    int month = atoi(month_parts[0]) - 1;
    int day = atoi(day_parts[0]) - 1;
    int year = atoi(date_parts[2]);

    if (strcmp(month_parts[1], "January") == 0) {
        month = 0;
    } else if (strcmp(month_parts[1], "February") == 0) {
        month = 1;
    } else if (strcmp(month_parts[1], "March") == 0) {
        month = 2;
    } else if (strcmp(month_parts[1], "April") == 0) {
        month = 3;
    } else if (strcmp(month_parts[1], "May") == 0) {
        month = 4;
    } else if (strcmp(month_parts[1], "June") == 0) {
        month = 5;
    } else if (strcmp(month_parts[1], "July") == 0) {
        month = 6;
    } else if (strcmp(month_parts[1], "August") == 0) {
        month = 7;
    } else if (strcmp(month_parts[1], "September") == 0) {
        month = 8;
    } else if (strcmp(month_parts[1], "October") == 0) {
        month = 9;
    } else if (strcmp(month_parts[1], "November") == 0) {
        month = 10;
    } else if (strcmp(month_parts[1], "December") == 0) {
        month = 11;
    } else {
        printf("Invalid month name\n");
        return;
    }

    if (strcmp(day_parts[1], "th") == 0) {
        day += 1;
    } else if (strcmp(day_parts[1], "st") == 0) {
        day += 2;
    } else if (strcmp(day_parts[1], "nd") == 0) {
        day += 3;
    } else if (strcmp(day_parts[1], "rd") == 0) {
        day += 4;
    } else {
        printf("Invalid day name\n");
        return;
    }

    if (strcmp(date_parts[2], "yesterday") == 0) {
        day -= 1;
    } else if (strcmp(date_parts[2], "today") == 0) {
        day = 1;
    } else if (strcmp(date_parts[2], "tomorrow") == 0) {
        day += 1;
    } else if (strcmp(date_parts[2], "next week") == 0) {
        day += 7;
    } else if (strcmp(date_parts[2], "next month") == 0) {
        day += days_in_month[month];
    } else if (strcmp(date_parts[2], "next year") == 0) {
        day += days_in_year;
    } else {
        printf("Invalid date expression\n");
        return;
    }

    if (month == 2 && (year % 4 == 0 || (year % 100 == 0 && year % 400!= 0))) {
        if (day > 29) {
            day -= 1;
            year -= 1;
        }
    }

    char date_format[20];
    strcpy(date_format, "%d-%d-%d");
    strftime(date_format, 19, "%Y-%m-%d", localtime(&day));

    printf("%s\n", date_format);
}

int main() {
    char date[20];
    char format[20];

    printf("Enter a natural language date (e.g. \"yesterday\", \"tomorrow\", \"next week\", etc.): ");
    scanf("%s", date);

    printf("Enter the desired date format (e.g. \"%d-%m-%Y\", \"%Y-%m-%d\", etc.): ");
    scanf("%s", format);

    convert_date(date, format);

    return 0;
}