//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: modular
#include <stdio.h>

// Function to check if a year is leap year
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

// Function to convert date to Julian Day
int toJulianDay(int day, int month, int year) {
    int a, b, c, d, e, JD;

    if (month < 3) {
        year--;
        month += 12;
    }

    a = year / 100;
    b = a / 4;
    c = 2 - a + b;
    d = 365.25 * (year + 4716);
    e = 30.6001 * (month + 1);

    JD = c + day + d + e - 1524.5;

    return JD;
}

// Function to convert Julian Day to date
void fromJulianDay(int JD, int *day, int *month, int *year) {
    int a, b, c, d, e, z, alpha;

    alpha = (int) ((JD - 1867216.25) / 36524.25);
    a = JD + 1 + alpha - alpha / 4;
    b = a + 1524;
    c = (int) ((b - 122.1) / 365.25);
    d = (int) (365.25 * c);
    e = (int) ((b - d) / 30.6001);

    *day = b - d - (int) (30.6001 * e);
    *month = e - 1 - 12 * (e / 14);
    *year = c - 4715 - ((7 + *month) / 10);

}

int main() {
    int day, month, year, JD;
    char format;

    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &day, &month, &year);

    printf("Enter the format (J)ulian or (G)regorian: ");
    scanf(" %c", &format);

    if (format == 'G') {
        JD = toJulianDay(day, month, year);
        printf("The Julian Day for %d/%d/%d is %d\n", day, month, year, JD);
    } else if (format == 'J') {
        fromJulianDay(JD, &day, &month, &year);
        printf("The Gregorian date for Julian Day %d is %d/%d/%d\n", JD, day, month, year);
        if (day == 29 && month == 2 && !isLeapYear(year)) {
            printf("%d is not a leap year, so February 29th does not exist.\n", year);
        }
    }

    return 0;
}