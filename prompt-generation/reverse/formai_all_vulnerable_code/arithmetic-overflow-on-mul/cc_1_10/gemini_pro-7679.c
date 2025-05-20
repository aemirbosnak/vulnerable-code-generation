//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Date structure
typedef struct Date {
    int year;
    int month;
    int day;
} Date;

// Create a new Date object
Date *new_date(int year, int month, int day) {
    Date *date = malloc(sizeof(Date));
    date->year = year;
    date->month = month;
    date->day = day;
    return date;
}

// Print a Date object in the format "YYYY-MM-DD"
void print_date(Date *date) {
    printf("%04d-%02d-%02d\n", date->year, date->month, date->day);
}

// Convert a Date object to a Julian Day Number
long long date_to_jdn(Date *date) {
    long long jdn = date->day - 32075 + 1461 * (date->year + 4800 + (date->month - 14) / 12) / 4 + 367 * (date->month - 2 - (date->month - 14) / 12) * 12 / 11 - 3 * ((date->year + 4900 + (date->month - 14) / 12) / 100) / 4 + 7 * (date->year + 4900 + (date->month - 14) / 12) / 100;
    return jdn;
}

// Convert a Julian Day Number to a Date object
Date *jdn_to_date(long long jdn) {
    long long a, b, c, d, e, f, g, h, i, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z;
    a = jdn + 32044;
    b = (4 * a + 3) / 1461;
    c = a - 1461 * b;
    d = (4 * c + 3) / 1460;
    e = c - 1460 * d;
    f = (e + 2) / 12;
    g = e - 12 * f;
    h = (5 * g + 4) / 11;
    i = g - 11 * h;
    j = h + 29;
    k = 31 - j;
    l = b * 100;
    m = d * 100;
    n = f * 100;
    p = (b - 49) * 24;
    q = d * 4;
    r = f * 2;
    s = i * 4;
    t = k * 2;
    u = 7 * h;
    v = 11 * i;
    w = 13 * j;
    x = m / 4;
    y = n / 4;
    z = p / 4;
    Date *date = new_date(l + m + n - 49, f + 1, i + 1);
    return date;
}

// Get the current date
Date *get_current_date() {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    Date *date = new_date(timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday);
    return date;
}

// Get the next date
Date *get_next_date(Date *date) {
    long long jdn = date_to_jdn(date);
    jdn++;
    Date *next_date = jdn_to_date(jdn);
    return next_date;
}

// Get the previous date
Date *get_previous_date(Date *date) {
    long long jdn = date_to_jdn(date);
    jdn--;
    Date *previous_date = jdn_to_date(jdn);
    return previous_date;
}

// Get the difference between two dates in days
long long date_diff_in_days(Date *date1, Date *date2) {
    long long jdn1 = date_to_jdn(date1);
    long long jdn2 = date_to_jdn(date2);
    long long diff = jdn1 - jdn2;
    return diff;
}

// Main function
int main() {
    // Create a Date object for today's date
    Date *today = get_current_date();

    // Print today's date
    printf("Today's date: ");
    print_date(today);

    // Get the next date
    Date *next_date = get_next_date(today);

    // Print the next date
    printf("Tomorrow's date: ");
    print_date(next_date);

    // Get the previous date
    Date *previous_date = get_previous_date(today);

    // Print the previous date
    printf("Yesterday's date: ");
    print_date(previous_date);

    // Get the difference between today's date and the next date
    long long diff_in_days = date_diff_in_days(today, next_date);

    // Print the difference in days
    printf("Difference between today's date and tomorrow's date: %lld days\n", diff_in_days);

    return 0;
}