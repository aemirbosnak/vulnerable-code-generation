//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>

// Global variables
char months[13][10] = {"", "January", "February", "March", "April", "May", "June", "July",
                        "August", "September", "October", "November", "December"};
int daysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Function to check if a year is a leap year
int checkLeapYear(int year) {
    if (year % 400 == 0) {
        return 1;
    } 
    if (year % 100 == 0) {
        return 0;
    }
    if (year % 4 == 0) {
        return 1;
    }
    return 0;
}

// Function to convert a given date to the number of days since 01-01-0001
long int convertToDays(int day, int month, int year) {
    long int days = 0;
    int i;

    for (i = 1; i < year; i++) {
        days += checkLeapYear(i) ? 366 : 365;
    }

    for (i = 1; i < month; i++) {
        days += daysOfMonth[i];
    }

    if (month > 2 && checkLeapYear(year)) {
        days++;
    }

    days += day;

    return days;
}

// Function to convert a given number of days since 01-01-0001 to a date
void convertToDate(long int days, int *day, int *month, int *year) {
    int i;
    long int daysLeft = days;

    for (i = 1; i < 4000 && daysLeft > 0; i++) {
        int daysInYear = checkLeapYear(i) ? 366 : 365;

        if (daysLeft >= daysInYear) {
            daysLeft -= daysInYear;
        } else {
            break;
        }
    }

    *year = i - 1;

    for (i = 1; i <= 12 && daysLeft > 0; i++) {
        int daysInMonth = daysOfMonth[i];

        if (i == 2 && checkLeapYear(*year)) {
            daysInMonth++;
        }

        if (daysLeft >= daysInMonth) {
            daysLeft -= daysInMonth;
        } else {
            break;
        }
    }

    *month = i - 1;
    *day = daysLeft + 1;
}

// Main function
int main() {
    int day, month, year, choice, flag = 0;
    long int days;
    
    printf("*** Welcome to Natural Language Date Converter ***\n\n");

    while (1) {
        printf("Choose an option: \n1. Convert date to number of days since 01-01-0001\n2. Convert number of days since 01-01-0001 to date\n3. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("\nEnter a date (DD MM YYYY format): ");
                scanf("%d %d %d", &day, &month, &year);

                if (day < 1 || month < 1 || month > 12 || year < 1) {
                    printf("\nInvalid date! Please try again.\n");
                } else {
                    days = convertToDays(day, month, year);
                    printf("\nNumber of days since 01-01-0001: %ld\n", days);
                }
                break;

            case 2:
                printf("\nEnter the number of days since 01-01-0001: ");
                scanf("%ld", &days);

                if (days < 1) {
                    printf("\nInvalid number of days! Please try again.\n");
                } else {
                    convertToDate(days, &day, &month, &year);
                    printf("\nDate: %02d %s %04d\n", day, months[month], year);
                }
                break;

            case 3:
                flag = 1;
                break;

            default: 
                printf("\nInvalid choice! Please choose again.\n");
        }

        if (flag) {
            break;
        }
    }
    printf("\nThanks for using Natural Language Date Converter!\n");

    return 0;
}