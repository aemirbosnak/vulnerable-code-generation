//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LEN 100

struct tm get_current_time() {
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);
    return *timeinfo;
}

char* get_day_name(int day) {
    static char days[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days[day];
}

char* get_month_name(int month) {
    static char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[month];
}

void convert_date(int day, int month, int year) {
    char date_str[MAX_LEN];
    struct tm date_time;

    date_time.tm_mday = day;
    date_time.tm_mon = month - 1;
    date_time.tm_year = year - 1900;
    date_time.tm_wday = get_day_name(date_time.tm_wday);
    date_time.tm_mon = get_month_name(date_time.tm_mon);

    strftime(date_str, MAX_LEN, "Today is %A, %B %d, %Y", &date_time);
    printf("%s\n", date_str);
}

int main() {
    int day, month, year;

    printf("Enter the current day (1-31): ");
    scanf("%d", &day);

    printf("Enter the current month (1-12): ");
    scanf("%d", &month);

    printf("Enter the current year (e.g. 2021): ");
    scanf("%d", &year);

    convert_date(day, month, year);

    return 0;
}