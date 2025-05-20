//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DaysOfMonth
{
    int month;
    int year;
    int daysofmonth;
};

static struct DaysOfMonth daysinmonth[] = {
    {1, 1900, 31}, {2, 1900, 28}, {3, 1900, 31}, {4, 1900, 30}, {5, 1900, 31}, {6, 1900, 30},
    {7, 1900, 31}, {8, 1900, 31}, {9, 1900, 30}, {10, 1900, 31}, {11, 1900, 30}, {12, 1900, 31},
    {1, 1901, 31}, {2, 1901, 28}, {3, 1901, 31}, {4, 1901, 30}, {5, 1901, 31}, {6, 1901, 30},
    {7, 1901, 31}, {8, 1901, 31}, {9, 1901, 30}, {10, 1901, 31}, {11, 1901, 30}, {12, 1901, 31},
    {1, 1902, 31}, {2, 1902, 28}, {3, 1902, 31}, {4, 1902, 30}, {5, 1902, 31}, {6, 1902, 30},
    {7, 1902, 31}, {8, 1902, 31}, {9, 1902, 30}, {10, 1902, 31}, {11, 1902, 30}, {12, 1902, 31},
    {1, 1903, 31}, {2, 1903, 28}, {3, 1903, 31}, {4, 1903, 30}, {5, 1903, 31}, {6, 1903, 30},
    {7, 1903, 31}, {8, 1903, 31}, {9, 1903, 30}, {10, 1903, 31}, {11, 1903, 30}, {12, 1903, 31},
    {1, 1904, 31}, {2, 1904, 29}, {3, 1904, 31}, {4, 1904, 30}, {5, 1904, 31}, {6, 1904, 30},
    {7, 1904, 31}, {8, 1904, 31}, {9, 1904, 30}, {10, 1904, 31}, {11, 1904, 30}, {12, 1904, 31}
};

int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}

int days_in_month(int month, int year) {
    if (month == 2 && is_leap_year(year)) return 29;
    for (int i = 0; i < 48; i++) {
        if (month == daysinmonth[i].month && year == daysinmonth[i].year) {
            return daysinmonth[i].daysofmonth;
        }
    }
    return 0;
}

int julian_date(int day, int month, int year) {
    int jd = day;
    for (int i = 1; i < month; i++) {
        jd += days_in_month(i, year);
    }
    return jd;
}

void date_diff(int month1, int day1, int year1, int month2, int day2, int year2) {
    int jd1 = julian_date(day1, month1, year1);
    int jd2 = julian_date(day2, month2, year2);
    int diff = jd2 - jd1;
    printf("The number of days between %d/%d/%d and %d/%d/%d is %d.\n", month1, day1, year1, month2, day2, year2, diff);
}

void date_converter(int month, int day, int year, int days_added) {
    day += days_added;
    while (day > days_in_month(month, year)) {
        day -= days_in_month(month, year);
        month++;
        if (month > 12) {
            year++;
            month = 1;
        }
    }
    printf("The new date is: %d/%d/%d\n", month, day, year);
}

int main() {
    int choice = 0;
    while (choice != 3) {
        printf("Welcome to the date converter!\n");
        printf("1. Calculate difference between two dates\n");
        printf("2. Add days to a date\n");
        printf("3. Quit\n");
        printf("Please make a selection: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int month1, day1, year1, month2, day2, year2;
            printf("Please enter the first date (mm/dd/yyyy): ");
            scanf("%d/%d/%d", &month1, &day1, &year1);
            printf("Please enter the second date (mm/dd/yyyy): ");
            scanf("%d/%d/%d", &month2, &day2, &year2);
            date_diff(month1, day1, year1, month2, day2, year2);
        } else if (choice == 2) {
            int month, day, year, days_added;
            printf("Please enter the date (mm/dd/yyyy): ");
            scanf("%d/%d/%d", &month, &day, &year);
            printf("Please enter the number of days to add: ");
            scanf("%d", &days_added);
            date_converter(month, day, year, days_added);
        } else if (choice == 3) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid selection. Please try again.\n");
        }
    }
    return 0;
}