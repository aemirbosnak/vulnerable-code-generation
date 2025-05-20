//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t now = time(NULL);
    struct tm *date_time = localtime(&now);
    char day_of_week[10] = "";
    char month_name[10] = "";
    int day = date_time->tm_mday;
    int month = date_time->tm_mon + 1;
    int year = date_time->tm_year + 1900;
    int hour = date_time->tm_hour;
    int minute = date_time->tm_min;
    int second = date_time->tm_sec;

    switch(date_time->tm_wday) {
        case 0:
            strcpy(day_of_week, "Sunday");
            break;
        case 1:
            strcpy(day_of_week, "Monday");
            break;
        case 2:
            strcpy(day_of_week, "Tuesday");
            break;
        case 3:
            strcpy(day_of_week, "Wednesday");
            break;
        case 4:
            strcpy(day_of_week, "Thursday");
            break;
        case 5:
            strcpy(day_of_week, "Friday");
            break;
        case 6:
            strcpy(day_of_week, "Saturday");
            break;
    }

    switch(month) {
        case 1:
            strcpy(month_name, "January");
            break;
        case 2:
            strcpy(month_name, "February");
            break;
        case 3:
            strcpy(month_name, "March");
            break;
        case 4:
            strcpy(month_name, "April");
            break;
        case 5:
            strcpy(month_name, "May");
            break;
        case 6:
            strcpy(month_name, "June");
            break;
        case 7:
            strcpy(month_name, "July");
            break;
        case 8:
            strcpy(month_name, "August");
            break;
        case 9:
            strcpy(month_name, "September");
            break;
        case 10:
            strcpy(month_name, "October");
            break;
        case 11:
            strcpy(month_name, "November");
            break;
        case 12:
            strcpy(month_name, "December");
            break;
    }

    printf("Today is %s, the %dth day of %s, in the year of our Lord %d.\n", day_of_week, day, month_name, year);
    printf("The time is %02d:%02d:%02d.\n", hour, minute, second);

    return 0;
}