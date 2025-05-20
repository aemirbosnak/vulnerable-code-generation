//FormAI DATASET v1.0 Category: Date and time ; Style: expert-level
#include <stdio.h>
#include <time.h>

int main()
{
    // declaring variables and structs
    time_t t = time(NULL);
    struct tm *tm_ptr = localtime(&t);
    char *day;
    char *month;
    int year, hour, minute, second;

    // assigning values to the variables
    year = tm_ptr->tm_year + 1900;
    hour = tm_ptr->tm_hour;
    minute = tm_ptr->tm_min;
    second = tm_ptr->tm_sec;

    // using switch statements to get day and month in string format
    switch (tm_ptr->tm_wday)
    {
        case 0:
            day = "Sunday";
            break;
        case 1:
            day = "Monday";
            break;
        case 2:
            day = "Tuesday";
            break;
        case 3:
            day = "Wednesday";
            break;
        case 4:
            day = "Thursday";
            break;
        case 5:
            day = "Friday";
            break;
        case 6:
            day = "Saturday";
            break;
    }

    switch (tm_ptr->tm_mon)
    {
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

    // printing the formatted date and time
    printf("Today is %s, %s %d, %d\n", day, month, tm_ptr->tm_mday, year);
    printf("The time is %02d:%02d:%02d\n", hour, minute, second);

    return 0;
}