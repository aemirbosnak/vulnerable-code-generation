//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: mathematical
#include <stdio.h>
#include <time.h>

typedef enum {
    GREGORIAN,
    JULIAN
} Calendar;

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    Calendar calendar;
} Date;

// Gregorian calendar: 1582-12-05 was followed by 1582-12-20
// Julian calendar: 4713 BC-03-01 was followed by 4713 BC-03-14
const Date gregorian_transition_date = {1582, 12, 5, 0, 0, 0, GREGORIAN};
const Date julian_transition_date = {4713, 3, 1, 0, 0, 0, JULIAN};

// Days per month in the Gregorian calendar
const int gregorian_days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Days per month in the Julian calendar
const int julian_days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Is the given year a leap year?
int is_leap_year(int year, Calendar calendar) {
    if (calendar == GREGORIAN) {
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    } else if (calendar == JULIAN) {
        return (year % 4 == 0);
    } else {
        return 0;
    }
}

// Get the number of days in the given month
int days_in_month(int year, int month, Calendar calendar) {
    if (calendar == GREGORIAN) {
        return gregorian_days_per_month[month - 1];
    } else if (calendar == JULIAN) {
        return julian_days_per_month[month - 1];
    } else {
        return 0;
    }
}

// Convert a Date to a Julian Day Number
double date_to_jdn(Date date) {
    double jdn = 0;
    if (date.calendar == GREGORIAN) {
        jdn = (1461 * (date.year + 4800 + (date.month - 14) / 12)) / 4 +
              (367 * (date.month - 2 - 12 * ((date.month - 14) / 12))) / 12 -
              (3 * ((date.year + 4900 + (date.month - 14) / 12) / 100)) / 4 +
              date.day - 32075;
    } else if (date.calendar == JULIAN) {
        jdn = (1461 * (date.year + 4800 + (date.month - 14) / 12)) / 4 +
              (367 * (date.month - 2 - 12 * ((date.month - 14) / 12))) / 12 -
              (3 * ((date.year + 4900 + (date.month - 14) / 12) / 100)) / 4 +
              date.day - 32083;
    }
    return jdn;
}

// Convert a Julian Day Number to a Date
Date jdn_to_date(double jdn) {
    Date date;
    if (jdn >= 2299161) {
        date.calendar = GREGORIAN;
    } else {
        date.calendar = JULIAN;
    }
    int a = jdn + 32044;
    int b = (4 * a + 3) / 1461;
    int c = a - (1461 * b) / 4;
    int d = (4 * c + 3) / 1460;
    date.year = b * 100 + d - 4800;
    date.month = (5 * c + 2) / 153;
    date.day = c - (153 * date.month + 2) / 5 + 1;
    return date;
}

// Add a number of days to a Date
Date add_days(Date date, int days) {
    double jdn = date_to_jdn(date);
    jdn += days;
    return jdn_to_date(jdn);
}

// Subtract a number of days from a Date
Date subtract_days(Date date, int days) {
    return add_days(date, -days);
}

// Compare two Dates
int compare_dates(Date date1, Date date2) {
    double jdn1 = date_to_jdn(date1);
    double jdn2 = date_to_jdn(date2);
    if (jdn1 < jdn2) {
        return -1;
    } else if (jdn1 > jdn2) {
        return 1;
    } else {
        return 0;
    }
}

// Print a Date
void print_date(Date date) {
    printf("%04d-%02d-%02d %02d:%02d:%02d %s\n", date.year, date.month, date.day, date.hour, date.minute, date.second,
           date.calendar == GREGORIAN ? "Gregorian" : "Julian");
}

int main() {
    // Create a Date object
    Date date = {2023, 2, 28, 12, 34, 56, GREGORIAN};

    // Print the Date
    print_date(date);

    // Add 100 days to the Date
    date = add_days(date, 100);

    // Print the Date again
    print_date(date);

    // Subtract 50 days from the Date
    date = subtract_days(date, 50);

    // Print the Date again
    print_date(date);

    // Compare the Date to another Date
    Date date2 = {2023, 3, 1, 0, 0, 0, GREGORIAN};
    int comparison = compare_dates(date, date2);
    if (comparison == -1) {
        printf("Date1 is before Date2.\n");
    } else if (comparison == 0) {
        printf("Date1 is the same as Date2.\n");
    } else {
        printf("Date1 is after Date2.\n");
    }

    return 0;
}