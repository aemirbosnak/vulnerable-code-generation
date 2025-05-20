//FormAI DATASET v1.0 Category: Date and time ; Style: happy
#include <stdio.h>
#include <time.h>

int main()
{
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    int hour = timeinfo->tm_hour;
    int minute = timeinfo->tm_min;
    int second = timeinfo->tm_sec;

    printf("Hello there! It's currently %02d:%02d:%02d on ", hour, minute, second);

    switch(timeinfo->tm_wday) {
        case 0:
            printf("Sunday");
            break;
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
    }

    printf(", ");

    switch(timeinfo->tm_mon) {
        case 0:
            printf("January");
            break;
        case 1:
            printf("February");
            break;
        case 2:
            printf("March");
            break;
        case 3:
            printf("April");
            break;
        case 4:
            printf("May");
            break;
        case 5:
            printf("June");
            break;
        case 6:
            printf("July");
            break;
        case 7:
            printf("August");
            break;
        case 8:
            printf("September");
            break;
        case 9:
            printf("October");
            break;
        case 10:
            printf("November");
            break;
        case 11:
            printf("December");
            break;
    }

    printf(" %02d, %d.\n", timeinfo->tm_mday, timeinfo->tm_year + 1900);

    printf("Isn't it a wonderful day?\n");

    return 0;
}