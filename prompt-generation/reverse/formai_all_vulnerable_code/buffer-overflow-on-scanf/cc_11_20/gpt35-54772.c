//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JANUARY 1
#define FEBRUARY 2
#define MARCH 3
#define APRIL 4
#define MAY 5
#define JUNE 6
#define JULY 7
#define AUGUST 8
#define SEPTEMBER 9
#define OCTOBER 10
#define NOVEMBER 11
#define DECEMBER 12

char* ConvertDate(char* date);

int main()
{
    char date[20];

    printf("Please enter a date (dd-mm-yyyy): ");
    scanf("%s", date);

    char* convertedDate = ConvertDate(date);

    printf("The converted date is: %s", convertedDate);

    free(convertedDate);

    return 0;
}

char* ConvertDate(char* date)
{
    char* newDate = (char*)malloc(20 * sizeof(char));

    char day[3];
    char month[3];
    char year[5];

    int i, j = 0;

    for(i = 0; i < 2; i++)
    {
        day[i] = date[i];
    }

    day[i] = '\0';

    i++;

    for(; i < 5; i++)
    {
        month[j] = date[i];
        j++;
    }

    month[j] = '\0';

    j = 0;

    for(i = 6; i < 10; i++)
    {
        year[j] = date[i];
        j++;
    }

    year[j] = '\0';

    int d = atoi(day);
    int m = atoi(month);
    int y = atoi(year);

    if(m < JANUARY || m > DECEMBER)
    {
        printf("Invalid date.\n");
        exit(0);
    }

    int daysInMonth;

    switch(m)
    {
        case JANUARY:
        case MARCH:
        case MAY:
        case JULY:
        case AUGUST:
        case OCTOBER:
        case DECEMBER:
            daysInMonth = 31;
            break;
        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
            daysInMonth = 30;
            break;
        case FEBRUARY:
            if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
            {
                daysInMonth = 29;
            }
            else
            {
                daysInMonth = 28;
            }
            break;
    }

    if(d < 1 || d > daysInMonth)
    {
        printf("Invalid date.\n");
        exit(0);
    }

    char monthName[10];

    switch(m)
    {
        case JANUARY:
            strcpy(monthName, "January");
            break;
        case FEBRUARY:
            strcpy(monthName, "February");
            break;
        case MARCH:
            strcpy(monthName, "March");
            break;
        case APRIL:
            strcpy(monthName, "April");
            break;
        case MAY:
            strcpy(monthName, "May");
            break;
        case JUNE:
            strcpy(monthName, "June");
            break;
        case JULY:
            strcpy(monthName, "July");
            break;
        case AUGUST:
            strcpy(monthName, "August");
            break;
        case SEPTEMBER:
            strcpy(monthName, "September");
            break;
        case OCTOBER:
            strcpy(monthName, "October");
            break;
        case NOVEMBER:
            strcpy(monthName, "November");
            break;
        case DECEMBER:
            strcpy(monthName, "December");
            break;
    }

    sprintf(newDate, "%s %d, %d", monthName, d, y);

    return newDate;
}