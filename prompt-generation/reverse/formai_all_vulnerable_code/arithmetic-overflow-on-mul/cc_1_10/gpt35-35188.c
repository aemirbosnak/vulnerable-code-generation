//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a Gregorian date to Julian Day Number
int gregorian_to_jdn(int year, int month, int day) {
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    return day + (153 * m + 2) / 5 + y * 365 + y / 4 - y / 100 + y / 400 - 32045;
}

// Function to convert Julian Day Number to a Gregorian date
void jdn_to_gregorian(int jdn, int *year, int *month, int *day) {
    int a = jdn + 32044;
    int b = (4 * a + 3) / 146097;
    int c = a - (b * 146097) / 4;
    int d = (4 * c + 3) / 1461;
    int e = c - (1461 * d) / 4;
    int m = (5 * e + 2) / 153;
    *day = e - (153 * m + 2) / 5 + 1;
    *month = m + 3 - 12 * (m / 10);
    *year = b * 100 + d - 4800 + (m / 10);
}

int main() {
    int year, month, day;
    char date[11];

    // Prompt user to enter a date in the format YYYY-MM-DD
    printf("Enter a date in the format YYYY-MM-DD: ");
    fgets(date, sizeof(date), stdin);

    // Extract the year, month, and day from the user input
    sscanf(date, "%d-%d-%d", &year, &month, &day);

    // Check if the date is valid
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
        printf("Invalid date.\n");
        return 1;
    }

    // Convert the Gregorian date to Julian Day Number
    int jdn = gregorian_to_jdn(year, month, day);
    printf("Julian Day Number: %d\n", jdn);

    // Convert the Julian Day Number back to a Gregorian date
    jdn_to_gregorian(jdn, &year, &month, &day);
    printf("Gregorian date: %04d-%02d-%02d\n", year, month, day);

    return 0;
}