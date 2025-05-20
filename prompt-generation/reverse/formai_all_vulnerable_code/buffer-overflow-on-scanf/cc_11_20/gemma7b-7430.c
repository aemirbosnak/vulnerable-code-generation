//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char date_string[100];
    printf("Enter a date in the format YYYY-MM-DD: ");
    scanf("%s", date_string);

    time_t timestamp = time(NULL);
    struct tm *tm_struct = localtime(&timestamp);

    int year, month, day;
    char month_name[30];

    year = atoi(date_string);
    month = atoi(date_string + 5);
    day = atoi(date_string + 8);

    switch (month)
    {
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

    printf("The date you entered is: %s, %d, %d, %d", month_name, year, day, tm_struct->tm_hour);

    return 0;
}