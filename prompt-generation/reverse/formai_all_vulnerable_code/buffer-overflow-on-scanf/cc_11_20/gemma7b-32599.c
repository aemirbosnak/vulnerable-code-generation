//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[20];
    printf("Enter the date in the format MM/DD/YYYY:");
    scanf("%s", input);

    int month, day, year;
    month = atoi(input);
    day = atoi(input + 3);
    year = atoi(input + 6);

    char *month_name;
    switch (month)
    {
        case 1:
            month_name = "January";
            break;
        case 2:
            month_name = "February";
            break;
        case 3:
            month_name = "March";
            break;
        case 4:
            month_name = "April";
            break;
        case 5:
            month_name = "May";
            break;
        case 6:
            month_name = "June";
            break;
        case 7:
            month_name = "July";
            break;
        case 8:
            month_name = "August";
            break;
        case 9:
            month_name = "September";
            break;
        case 10:
            month_name = "October";
            break;
        case 11:
            month_name = "November";
            break;
        case 12:
            month_name = "December";
            break;
        default:
            month_name = "Invalid Month";
    }

    printf("The date is: %s, %d, %d", month_name, day, year);

    return 0;
}