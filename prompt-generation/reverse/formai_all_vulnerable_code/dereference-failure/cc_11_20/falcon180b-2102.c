//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t now;
    struct tm *t;
    char *date;
    char *month;
    char *year;

    // Get the current time
    time(&now);

    // Convert the time to a struct tm
    t = localtime(&now);

    // Get the day of the week
    switch (t->tm_wday) {
        case 0:
            month = "Sunday";
            break;
        case 1:
            month = "Monday";
            break;
        case 2:
            month = "Tuesday";
            break;
        case 3:
            month = "Wednesday";
            break;
        case 4:
            month = "Thursday";
            break;
        case 5:
            month = "Friday";
            break;
        case 6:
            month = "Saturday";
            break;
    }

    // Get the month
    switch (t->tm_mon) {
        case 0:
            month = "January";
            break;
        case 1:
            month = "February";
            break;
        case 2:
            month = "March";
            break;
        case 3:
            month = "April";
            break;
        case 4:
            month = "May";
            break;
        case 5:
            month = "June";
            break;
        case 6:
            month = "July";
            break;
        case 7:
            month = "August";
            break;
        case 8:
            month = "September";
            break;
        case 9:
            month = "October";
            break;
        case 10:
            month = "November";
            break;
        case 11:
            month = "December";
            break;
    }

    // Get the year
    year = asctime(t);

    // Get the date
    date = asctime(t);

    // Print the day of the week, month, day and year
    printf("Today is %s, %s %d, %s.\n", month, date, t->tm_mday, year);

    return 0;
}