//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: scalable
#include <stdio.h>

// Function to check if the given year is a leap year or not
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return 1;
            else
                return 0;
        } else
            return 1;
    } else
        return 0;
}

// Function to convert given date (dd-mm-yyyy) to Julian Day Number
int dateToJDN(int day, int month, int year) {
    int a, b, c, d, JDN;

    if (month < 3) {
        year--;
        month += 12;
    }
    a = year / 100;
    b = a / 4;
    c = 2 - a + b;
    d = (int) (365.25 * (year + 4716));
    d += (int) (30.6001 * (month + 1));
    d += day + c - 1524;
    JDN = d;

    return JDN;
}

// Function to convert a given Julian Day Number to Gregorian date (dd-mm-yyyy)
void jdnToDate(int JDN, int *day, int *month, int *year) {
    int a, b, c, d, e, m;

    if (JDN >= 1721426) {
        a = (int) (((float) JDN - 1867216.25) / 36524.25);
        a = JDN + 1 + a - (a / 4);
    } else {
        a = JDN;
    }

    b = a + 1524;
    c = (int) (((float) b - 122.1) / 365.25);
    d = (int) (365.25 * c);
    e = (int) ((float) (b - d) / 30.6001);

    // Month calculation
    if (e < 14) {
        *month = e - 1;
    } else {
        *month = e - 13;
    }

    // Year calculation
    if (*month > 2) {
        *year = c - 4716;
    } else {
        *year = c - 4715;
    }

    // Day calculation
    *day = b - d - (int) (30.6001 * e);

    // For leap years, if day of the month is after February then we add one extra day
    if (*month > 2 && isLeapYear(*year)) {
        (*day)++;
    }
}

int main() {
    int input_day, input_month, input_year, output_day, output_month, output_year, jdn_input, jdn_output;

    printf("Enter input date (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &input_day, &input_month, &input_year);

    // Convert input date to Julian Day Number
    jdn_input = dateToJDN(input_day, input_month, input_year);

    printf("Enter output date (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &output_day, &output_month, &output_year);

    // Convert output date to Julian Day Number
    jdn_output = dateToJDN(output_day, output_month, output_year);

    // Calculate the number of days between input and output dates
    int no_of_days = jdn_output - jdn_input;

    // Convert the number of days to years, months, and remaining days
    int years = no_of_days / 365;
    int remaining_days = no_of_days % 365;
    int months = remaining_days / 30;
    int days = remaining_days % 30;

    // Convert the input date to output date format
    jdnToDate(jdn_output, &output_day, &output_month, &output_year);

    printf("\n%d year(s), %d month(s) and %d day(s) between %d-%d-%d and %d-%d-%d.\n", years, months, days, input_day, input_month, input_year, output_day, output_month, output_year);

    return 0;
}