//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DATE_LEN 20

typedef struct Date
{
    int year;
    int month;
    int day;
} Date;

void convert_date(Date *date, char *date_str)
{
    char *month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    char *day_names[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    int i, year, month, day;

    date_str = strchr(date_str, '-') ? strchr(date_str, '-') : date_str;

    year = atoi(date_str);
    date_str = strchr(date_str, '-') ? strchr(date_str, '-') : date_str;

    month = atoi(date_str);
    date_str = strchr(date_str, '-') ? strchr(date_str, '-') : date_str;

    day = atoi(date_str);

    date->year = year;
    date->month = month;
    date->day = day;

    printf("%s, %s %d, %d", day_names[date->day - 1], month_names[date->month - 1], date->day, date->year);
}

int main()
{
    Date date;
    char date_str[] = "November 23, 2023";

    convert_date(&date, date_str);

    printf("\nDate converted: %s", date.year);
    printf(", %s, %d", date.month, date.day);

    return 0;
}