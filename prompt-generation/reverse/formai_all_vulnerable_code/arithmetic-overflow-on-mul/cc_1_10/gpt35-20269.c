//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: synchronous
#include <stdio.h>
#include <string.h>

// Function to check if the year is a leap year
int isLeapYear(int year) {
    if(year % 400 == 0)
        return 1;
    if(year % 100 == 0)
        return 0;
    if(year % 4 == 0)
        return 1;
    return 0;
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    if(month == 2) {
        if(isLeapYear(year))
            return 29;
        else
            return 28;
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else
        return 31;
}

// Function to convert a date to Julian Day Number
int dateToJDN(int day, int month, int year) {
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    int JDN = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    return JDN;
}

// Function to convert Julian Day Number to a date
void JDNToDate(int JDN, int* day, int* month, int* year) {
    int a = JDN + 32044;
    int b = (4 * a + 3) / 146097;
    int c = a - (b * 146097) / 4;
    int d = (4 * c + 3) / 1461;
    int e = c - (1461 * d) / 4;
    int m = (5 * e + 2) / 153;
    *day = e - (153 * m + 2) / 5 + 1;
    *month = m + 3 - 12 * (m / 10);
    *year = b * 100 + d - 4800 + m / 10;
}

// Function to add days to a date
void addDays(int* day, int* month, int* year, int daysToAdd) {
    while(daysToAdd > 0) {
        int daysInMonth = getDaysInMonth(*month, *year);
        if(daysToAdd > daysInMonth - *day + 1) {
            daysToAdd -= daysInMonth - *day + 1;
            *day = 1;
            *month += 1;
            if(*month > 12) {
                *month = 1;
                *year += 1;
            }
        }
        else {
            *day += daysToAdd;
            break;
        }
    }
}

// Function to subtract days from a date
void subtractDays(int* day, int* month, int* year, int daysToSubtract) {
    while(daysToSubtract > 0) {
        if(daysToSubtract >= *day) {
            daysToSubtract -= *day;
            *month -= 1;
            if(*month < 1) {
                *month = 12;
                *year -= 1;
            }
            *day = getDaysInMonth(*month, *year);
        }
        else {
            *day -= daysToSubtract;
            break;
        }
    }
}

int main() {
    int day, month, year, daysToAdd, daysToSubtract;
    char input[100];

    printf("Welcome to the Natural Language Date Converter\n");
    printf("Enter a date (DD-MM-YYYY): ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d-%d-%d", &day, &month, &year);

    printf("\nYou entered: %02d-%02d-%04d\n", day, month, year);

    printf("\nWhat would you like to do? (+/- days)\n");
    fgets(input, sizeof(input), stdin);

    if(input[0] == '+') {
        sscanf(input+1, "%d", &daysToAdd);
        printf("\nAdding %d days...\n", daysToAdd);
        addDays(&day, &month, &year, daysToAdd);
    }
    else if(input[0] == '-') {
        sscanf(input+1, "%d", &daysToSubtract);
        printf("\nSubtracting %d days...\n", daysToSubtract);
        subtractDays(&day, &month, &year, daysToSubtract);
    }

    printf("\nThe new date is: %02d-%02d-%04d\n", day, month, year);

    int JDN = dateToJDN(day, month, year);
    printf("\nThe Julian Day Number is: %d\n", JDN);

    JDNToDate(JDN+1, &day, &month, &year);
    printf("\nThe next day is: %02d-%02d-%04d\n", day, month, year);

    JDNToDate(JDN-1, &day, &month, &year);
    printf("\nThe previous day is: %02d-%02d-%04d\n", day, month, year);

    return 0;
}