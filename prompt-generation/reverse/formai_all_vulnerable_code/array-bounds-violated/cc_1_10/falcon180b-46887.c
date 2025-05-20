//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
char *week_days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int main() {
    char date_str[100];
    char input_str[100];
    int day, month, year;
    int len;
    char *token;
    char *week_day_str;
    time_t t;
    struct tm *tm;

    printf("Enter a date in the format DD/MM/YYYY: ");
    fgets(date_str, sizeof(date_str), stdin);

    len = strlen(date_str);
    if (len!= 10) {
        printf("Invalid date format.\n");
        return 1;
    }

    sscanf(date_str, "%d/%d/%d", &day, &month, &year);

    if (year < 1000 || year > 9999) {
        printf("Invalid year.\n");
        return 1;
    }

    if (month < 1 || month > 12) {
        printf("Invalid month.\n");
        return 1;
    }

    if (day < 1 || day > 31) {
        printf("Invalid day.\n");
        return 1;
    }

    tm = localtime(&t);
    tm->tm_year = year - 1900;
    tm->tm_mon = month - 1;
    tm->tm_mday = day;

    t = mktime(tm);
    if (t == -1) {
        printf("Invalid date.\n");
        return 1;
    }

    t += 60 * 60 * 24; // Add one day

    tm = localtime(&t);
    week_day_str = week_days[tm->tm_wday];

    printf("The date %s is a %s.\n", date_str, week_day_str);

    return 0;
}