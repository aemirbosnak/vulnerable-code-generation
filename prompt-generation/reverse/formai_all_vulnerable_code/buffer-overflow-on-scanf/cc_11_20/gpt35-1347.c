//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getMonthDays(int y, int m);

int main()
{
    char dateStr[11];
    int d, m, y, days, i;
    printf("Enter date in natural language format (DD MMM YYYY): ");
    scanf("%s", dateStr);
    char *months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    char *abbrMonths[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    char *tokens[4];
    char *token = strtok(dateStr, " ");
    i = 0;
    while (token != NULL)
    {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    d = atoi(tokens[0]);
    char *mStr = tokens[1];
    y = atoi(tokens[2]);
    for (i = 0; i < 12; i++)
    {
        if (strcmp(mStr, months[i]) == 0 || strcmp(mStr, abbrMonths[i]) == 0)
        {
            m = i + 1;
            break;
        }
    }
    if (i == 12)
    {
        printf("Invalid month.\n");
        return 0;
    }
    days = d;
    for (i = 1; i < m; i++)
    {
        days += getMonthDays(y, i);
    }
    printf("The date %s is equivalent to day %d of year %d.\n", dateStr, days, y);
    return 0;
}

int getMonthDays(int y, int m)
{
    int days;
    switch (m)
    {
    case 1:
        days = 31;
        break;
    case 2:
        if (y % 4 == 0)
        {
            if (y % 100 == 0)
            {
                if (y % 400 == 0)
                {
                    days = 29;
                }
                else
                {
                    days = 28;
                }
            }
            else
            {
                days = 29;
            }
        }
        else
        {
            days = 28;
        }
        break;
    case 3:
        days = 31;
        break;
    case 4:
        days = 30;
        break;
    case 5:
        days = 31;
        break;
    case 6:
        days = 30;
        break;
    case 7:
        days = 31;
        break;
    case 8:
        days = 31;
        break;
    case 9:
        days = 30;
        break;
    case 10:
        days = 31;
        break;
    case 11:
        days = 30;
        break;
    case 12:
        days = 31;
        break;
    }
    return days;
}