//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert month name to number
int convert_month_to_number(char *month) {
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int i=0; i<12; i++) {
        if (strcmp(month, months[i]) == 0) {
            return i+1;
        }
    }
    return -1;
}

// Function to convert date to Julian day
int convert_date_to_julian(int day, int month, int year) {
    int a, b, jd;
    if (month < 3) {
        month += 12;
        year--;
    }
    a = year / 100;
    b = 2 - a + a / 4;
    jd = (int)(365.25 * (year + 4716)) + (int)(30.6001 * (month + 1)) + day + b - 1524;
    return jd;
}

// Function to convert Julian day to date
void convert_julian_to_date(int jd) {
    int a, b, c, d, e, month, day, year;
    if (jd > 2299160) {
        a = jd + 32044;
        b = (int)((4 * a + 3) / 146097);
        c = a - (int)((b * 146097) / 4);
    }
    else {
        b = 0;
        c = jd + 32082;
    }
    d = (int)((4 * c + 3) / 1461);
    e = c - (int)((1461 * d) / 4);
    month = (int)((5 * e + 2) / 153);
    day = e - (int)((153 * month + 2) / 5) + 1;
    year = (b * 100) + d - 4800 + (int)(month / 10);
    month = (month % 12) + 1;
    printf("%02d-%02d-%04d", day, month, year);
}

int main() {
    char input[30];
    printf("Enter date in natural language format (Example: 21st of June 2022): ");
    fgets(input, 30, stdin);

    // Parse input string to get day, month and year
    int day, month, year;
    char suffix[3], month_name[10];
    sscanf(input, "%d%s of %s %d", &day, suffix, month_name, &year);

    // Remove suffix from day
    day = atoi(strtok(suffix, "stndrdth"));

    // Convert month name to number
    month = convert_month_to_number(month_name);

    // Convert date to Julian day
    int jd = convert_date_to_julian(day, month, year);

    // Convert Julian day to date
    convert_julian_to_date(jd);

    return 0;
}