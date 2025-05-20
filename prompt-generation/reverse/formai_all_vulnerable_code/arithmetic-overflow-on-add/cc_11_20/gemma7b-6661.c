//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    int year = tm->tm_year + 1900;
    int month = tm->tm_mon + 1;
    int day = tm->tm_mday;

    char *month_name = "Jan";
    switch (month)
    {
        case 1:
            month_name = "Jan";
            break;
        case 2:
            month_name = "Feb";
            break;
        case 3:
            month_name = "Mar";
            break;
        case 4:
            month_name = "Apr";
            break;
        case 5:
            month_name = "May";
            break;
        case 6:
            month_name = "Jun";
            break;
        case 7:
            month_name = "Jul";
            break;
        case 8:
            month_name = "Aug";
            break;
        case 9:
            month_name = "Sep";
            break;
        case 10:
            month_name = "Oct";
            break;
        case 11:
            month_name = "Nov";
            break;
        case 12:
            month_name = "Dec";
            break;
    }

    printf("The current date is: %d %s %d, %d", day, month_name, year);
    printf("\n");
    printf("May the clock strike twelve...");
    printf("\n");

    return 0;
}