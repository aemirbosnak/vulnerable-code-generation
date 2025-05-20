//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char date_str[20];
    printf("Enter a date in the format MM/DD/YY: ");
    scanf("%s", date_str);

    time_t t = mktime(NULL);
    struct tm *tm = localtime(&t);

    char month_name[30];
    switch (tm->tm_mon)
    {
        case 0:
            strcpy(month_name, "January");
            break;
        case 1:
            strcpy(month_name, "February");
            break;
        case 2:
            strcpy(month_name, "March");
            break;
        case 3:
            strcpy(month_name, "April");
            break;
        case 4:
            strcpy(month_name, "May");
            break;
        case 5:
            strcpy(month_name, "June");
            break;
        case 6:
            strcpy(month_name, "July");
            break;
        case 7:
            strcpy(month_name, "August");
            break;
        case 8:
            strcpy(month_name, "September");
            break;
        case 9:
            strcpy(month_name, "October");
            break;
        case 10:
            strcpy(month_name, "November");
            break;
        case 11:
            strcpy(month_name, "December");
            break;
    }

    char day_name[30];
    switch (tm->tm_wday)
    {
        case 0:
            strcpy(day_name, "Sunday");
            break;
        case 1:
            strcpy(day_name, "Monday");
            break;
        case 2:
            strcpy(day_name, "Tuesday");
            break;
        case 3:
            strcpy(day_name, "Wednesday");
            break;
        case 4:
            strcpy(day_name, "Thursday");
            break;
        case 5:
            strcpy(day_name, "Friday");
            break;
        case 6:
            strcpy(day_name, "Saturday");
            break;
    }

    printf("The date you entered is: %s, %s %s, %d", month_name, day_name, tm->tm_year, tm->tm_mday);

    return 0;
}