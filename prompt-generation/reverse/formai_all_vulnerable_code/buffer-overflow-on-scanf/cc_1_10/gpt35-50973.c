//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Function to check if the given year is a leap year or not
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}

// Function to convert the given date to the Julian Days number
int toJulianDays(int day, int month, int year) {
    // array to store the number of days in each month
    const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // add up days for current month
    int julianDays = day;

    // add up days for previous months
    for (int i = 1; i < month; i++)
        julianDays += daysInMonth[i];

    // check if the current year is a leap year and it's after February
    if (isLeapYear(year) && month > 2)
        julianDays++;

    // add up days for previous years
    int yearToDays = 0;
    for (int i = 1; i < year; i++) {
        if (isLeapYear(i))
            yearToDays += 366;
        else
            yearToDays += 365;
    }
    julianDays += yearToDays;

    return julianDays;
}

// Function to convert the Julian Days number to the Gregorian Date
void toGregorianDate(int julianDays, int *day, int *month, int *year) {
    // number of days in each month, considering leap year
    const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // subtract days for all previous years
    int remainingDays = julianDays;
    int currentYear = 1;
    while (remainingDays > 0) {
        int daysInYear;
        if (isLeapYear(currentYear))
            daysInYear = 366;
        else
            daysInYear = 365;

        if (remainingDays >= daysInYear) {
            remainingDays -= daysInYear;
            currentYear++;
        }
        else {
            break;
        }
    }

    // subtract days for all previous months
    int currentMonth = 1;
    while (remainingDays > 0) {
        int daysInCurrentMonth = daysInMonth[currentMonth];

        // consider February of the current year for leap year
        if (currentMonth == 2 && isLeapYear(currentYear))
            daysInCurrentMonth++;

        if (remainingDays >= daysInCurrentMonth) {
            remainingDays -= daysInCurrentMonth;
            currentMonth++;
        }
        else {
            break;
        }
    }

    // assign values to output variables
    *day = remainingDays;
    *month = currentMonth;
    *year = currentYear;
}

int main() {
    int choice;
    while (1) {
        // print menu
        printf("\nPlease choose an option:\n");
        printf("1. Convert Gregorian date to Julian Days Number\n");
        printf("2. Convert Julian Days Number to Gregorian date\n");
        printf("3. Exit\n");

        // read user input
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // convert Gregorian date to Julian Days Number
        {
            // read input
            int day, month, year;
            printf("Enter Gregorian Date (dd-mm-yyyy): ");
            scanf("%d-%d-%d", &day, &month, &year);

            // convert and print output
            printf("Julian Days Number: %d\n", toJulianDays(day, month, year));

            break;
        }
        case 2: // convert Julian Days Number to Gregorian date
        {
            // read input
            int julianDays;
            printf("Enter Julian Days Number: ");
            scanf("%d", &julianDays);

            // convert and print output
            int day, month, year;
            toGregorianDate(julianDays, &day, &month, &year);
            printf("Gregorian Date: %02d-%02d-%04d\n", day, month, year);

            break;
        }
        case 3: // exit program
            printf("Thank you for using Date Converter. Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}