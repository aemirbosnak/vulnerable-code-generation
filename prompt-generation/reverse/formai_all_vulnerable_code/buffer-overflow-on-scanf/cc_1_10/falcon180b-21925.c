//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int get_day_of_week(int day, int month, int year)
{
    struct tm date = {0};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;

    time_t t = mktime(&date);
    return (int) (t % 7);
}

int get_month_name(int month)
{
    switch (month) {
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 7;
        case 8:
            return 8;
        case 9:
            return 9;
        case 10:
            return 10;
        case 11:
            return 11;
        case 12:
            return 12;
        default:
            return 0;
    }
}

int main()
{
    int day, month, year;
    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    int day_of_week = get_day_of_week(day, month, year);
    char *month_name = get_month_name(month);

    printf("Today is %s, %d %s %d\n",
           month_name, day, (day_of_week == 0)? "Sunday" : "", year);

    return 0;
}