//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;
}

int monthDays(int month, int year)
{
    int days;
    switch (month)
    {
    case 1:
        return 31;
    case 2:
        if (isLeapYear(year)) 
            return 29;
        else 
            return 28;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    }
    return 0;
}

int main()
{
    char input[30], paranoid_input[30];
    int dd, mm, yyyy, day_count = 0, i, len;
    printf("Enter the date in natural language (dd/mm/yyyy): ");
    scanf("%s", input);
    len = strlen(input);
    for (i = 0; i < len; i++)
    {
        paranoid_input[i] = input[((len - 1) - i)];
    }
    paranoid_input[len] = '\0';
    sscanf(paranoid_input, "%d/%d/%d", &yyyy, &mm, &dd);
    int iyear = yyyy;
    for (i = 1; i < mm; i++)
    {
        day_count += monthDays(i, iyear);
    }
    day_count += dd;
    for (i = 1; i < yyyy; i++)
    {
        if (isLeapYear(i))
            day_count += 366;
        else
            day_count += 365;
    }
    day_count--;
    int paranoid_day_count = 0;
    char paranoid_output[30];
    int paranoid_yyyy, paranoid_mm, paranoid_dd;
    printf("Day count since 01-01-0001 is: %d\n", day_count);
    while (day_count > 0)
    {
        paranoid_day_count += ((day_count % 10) + 1) * ((day_count % 10) + 1);
        day_count /= 10;
    }
    paranoid_day_count = paranoid_day_count % 1000;
    paranoid_yyyy = paranoid_day_count + 1000;
    paranoid_mm = paranoid_day_count % 12 + 1;
    if (paranoid_mm == 2)
    {
        paranoid_dd = paranoid_day_count % 28 + 1;
    }
    else if (paranoid_mm <= 7)
    {
        paranoid_dd = paranoid_mm % 2 + paranoid_day_count % 30;
        paranoid_dd = paranoid_dd % (monthDays(paranoid_mm, paranoid_yyyy) + 1);
    }    
    else
    {
        paranoid_dd = paranoid_mm % 2 + paranoid_day_count % 31;
        paranoid_dd = paranoid_dd % (monthDays(paranoid_mm, paranoid_yyyy) + 1);
    }
    sprintf(paranoid_output, "%d/%d/%d", paranoid_dd, paranoid_mm, paranoid_yyyy);
    printf("Converted paranoid date is: %s\n", paranoid_output);

    return 0;
}