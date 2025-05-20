//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LENGTH 20

struct tm get_date_from_string(const char *date_string) {
    struct tm date;
    strptime(date_string, "%d %b %Y", &date);
    return date;
}

char *get_day_of_week(time_t date) {
    static char days_of_week[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days_of_week[(date % 7) + 1];
}

char *get_month_name(int month) {
    static char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[month];
}

int main() {
    char date_string[MAX_DATE_LENGTH];
    struct tm date;
    time_t seconds_since_epoch;
    int year, month, day;

    printf("Enter a date in the format DD/MM/YYYY: ");
    scanf("%s", date_string);

    if (strlen(date_string)!= 10 || sscanf(date_string, "%d/%d/%d", &day, &month, &year)!= 3) {
        printf("Invalid date format.\n");
        exit(1);
    }

    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    date.tm_hour = 0;
    date.tm_min = 0;
    date.tm_sec = 0;

    time(&seconds_since_epoch);
    mktime(&date);

    printf("Today is %s, %d %s %d.\n", get_day_of_week(time(NULL)), day, get_month_name(date.tm_mon + 1), year + 1900);

    return 0;
}