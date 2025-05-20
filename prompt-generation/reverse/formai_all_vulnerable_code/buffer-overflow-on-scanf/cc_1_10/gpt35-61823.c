//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct date // define structure for date
{
    int d, m, y; // day, month, year
};

int leap(int y) // function to check whether a year is leap year or not
{
    return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0); // return 1 if leap year, 0 otherwise
}

int daysInMonth(int m, int y) // function to return number of days in a month
{
    switch (m)
    {
        case 2:
            if (leap(y)) return 29; // February has 29 days in leap year
            return 28; // February has 28 days in non-leap year
        case 4:
        case 6:
        case 9:
        case 11:
            return 30; // April, June, September, November have 30 days
        default:
            return 31; // All other months have 31 days
    }
}

int daysBetween(struct date d1, struct date d2) // function to calculate number of days between two dates
{
    int nDays = 0, i; // variable to store number of days and loop index
    for (i = d1.y; i < d2.y; i++) // loop through years
        nDays += (leap(i) ? 366 : 365); // add number of days in year
    for (i = 1; i < d1.m; i++) // loop through months of start year
        nDays -= daysInMonth(i, d1.y); // subtract number of days in month
    nDays -= d1.d - 1; // subtract number of days from start day to end of start month
    for (i = 1; i < d2.m; i++) // loop through months of end year
        nDays += daysInMonth(i, d2.y); // add number of days in month
    nDays += d2.d - 1; // add number of days from start of end month to end day
    return nDays; // return total number of days
}

int main()
{
    struct date d1, d2; // define variables for two dates
    printf("Enter first date: "); // prompt user to enter first date
    scanf("%d/%d/%d", &d1.d, &d1.m, &d1.y); // read first date from user
    printf("Enter second date: "); // prompt user to enter second date
    scanf("%d/%d/%d", &d2.d, &d2.m, &d2.y); // read second date from user
    printf("Number of days between %d/%d/%d and %d/%d/%d is %d\n", d1.d, d1.m, d1.y, d2.d, d2.m, d2.y, daysBetween(d1, d2)); // print number of days between two dates
    return 0; // exit program
}