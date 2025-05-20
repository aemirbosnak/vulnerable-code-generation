//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100

enum {
    DAY_SUNDAY,
    DAY_MONDAY,
    DAY_TUESDAY,
    DAY_WEDNESDAY,
    DAY_THURSDAY,
    DAY_FRIDAY,
    DAY_SATURDAY
};

struct tm get_current_time() {
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);
    return *timeinfo;
}

char* get_day_name(int day) {
    switch (day) {
        case DAY_SUNDAY:
            return "Sunday";
        case DAY_MONDAY:
            return "Monday";
        case DAY_TUESDAY:
            return "Tuesday";
        case DAY_WEDNESDAY:
            return "Wednesday";
        case DAY_THURSDAY:
            return "Thursday";
        case DAY_FRIDAY:
            return "Friday";
        case DAY_SATURDAY:
            return "Saturday";
        default:
            return "Invalid day";
    }
}

char* get_month_name(int month) {
    switch (month) {
        case 0:
            return "January";
        case 1:
            return "February";
        case 2:
            return "March";
        case 3:
            return "April";
        case 4:
            return "May";
        case 5:
            return "June";
        case 6:
            return "July";
        case 7:
            return "August";
        case 8:
            return "September";
        case 9:
            return "October";
        case 10:
            return "November";
        case 11:
            return "December";
        default:
            return "Invalid month";
    }
}

char* get_date_string(struct tm date) {
    char buffer[MAX_LENGTH];
    strftime(buffer, MAX_LENGTH, "%A, %B %d, %Y", &date);
    return strdup(buffer);
}

int main() {
    struct tm current_time = get_current_time();
    char* current_date_string = get_date_string(current_time);

    printf("Today is %s\n", current_date_string);

    return 0;
}