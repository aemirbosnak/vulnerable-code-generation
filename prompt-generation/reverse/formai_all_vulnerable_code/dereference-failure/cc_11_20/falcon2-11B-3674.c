//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void convert_date(char *date, struct tm *result) {
    /* convert natural language date to standard date format */
    int year, month, day;
    char *month_name;
    char *day_name;

    /* parse the date string */
    year = atoi(date + 0);
    month = atoi(date + 3);
    day = atoi(date + 6);

    /* convert month name to number */
    month_name = strtok(date + 9, " ");
    if (strlen(month_name) == 3) {
        month_name[2] = '\0';
    }
    if (strcasecmp(month_name, "January") == 0) {
        month = 1;
    } else if (strcasecmp(month_name, "February") == 0) {
        month = 2;
    } else if (strcasecmp(month_name, "March") == 0) {
        month = 3;
    } else if (strcasecmp(month_name, "April") == 0) {
        month = 4;
    } else if (strcasecmp(month_name, "May") == 0) {
        month = 5;
    } else if (strcasecmp(month_name, "June") == 0) {
        month = 6;
    } else if (strcasecmp(month_name, "July") == 0) {
        month = 7;
    } else if (strcasecmp(month_name, "August") == 0) {
        month = 8;
    } else if (strcasecmp(month_name, "September") == 0) {
        month = 9;
    } else if (strcasecmp(month_name, "October") == 0) {
        month = 10;
    } else if (strcasecmp(month_name, "November") == 0) {
        month = 11;
    } else if (strcasecmp(month_name, "December") == 0) {
        month = 12;
    }

    /* convert day name to number */
    day_name = strtok(NULL, " ");
    if (strcasecmp(day_name, "Monday") == 0) {
        day = 0;
    } else if (strcasecmp(day_name, "Tuesday") == 0) {
        day = 1;
    } else if (strcasecmp(day_name, "Wednesday") == 0) {
        day = 2;
    } else if (strcasecmp(day_name, "Thursday") == 0) {
        day = 3;
    } else if (strcasecmp(day_name, "Friday") == 0) {
        day = 4;
    } else if (strcasecmp(day_name, "Saturday") == 0) {
        day = 5;
    } else if (strcasecmp(day_name, "Sunday") == 0) {
        day = 6;
    }

    /* set the date */
    result->tm_year = year;
    result->tm_mon = month - 1;
    result->tm_mday = day;
}

int main(void) {
    char date[20];
    struct tm result;

    printf("Enter a natural language date: ");
    scanf("%s", date);
    convert_date(date, &result);
    printf("Standard date: %04d-%02d-%02d\n", result.tm_year + 1900, result.tm_mon + 1, result.tm_mday);
    return 0;
}