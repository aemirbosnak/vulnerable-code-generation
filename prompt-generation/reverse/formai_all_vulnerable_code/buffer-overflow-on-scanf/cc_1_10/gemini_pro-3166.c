//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is empty
int is_empty(char *str) {
    return (str == NULL || strlen(str) == 0);
}

// Function to check if a string is a valid date
int is_valid_date(char *str) {
    int len = strlen(str);
    if (len != 10) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    int day = atoi(str);
    int month = atoi(str + 2);
    int year = atoi(str + 4);
    if (day < 1 || day > 31) {
        return 0;
    }
    if (month < 1 || month > 12) {
        return 0;
    }
    if (year < 1000) {
        return 0;
    }
    return 1;
}

// Function to convert a string date to a Julian Day Number
int to_julian_day(char *str) {
    int y, m, d;
    sscanf(str, "%4d%2d%2d", &y, &m, &d);
    int jdn = d - 32075 + 1461 * (y + 4800 + (m - 14) / 12) / 4 + 367 * (m - 2 - (m - 14) / 12 * 12) / 12 - 3 * ((y + 4900 + (m - 14) / 12) / 100) / 4;
    return jdn;
}

// Function to convert a Julian Day Number to a string date
char *from_julian_day(int jdn) {
    int y, m, d;
    jdn += 32075;
    y = (4 * jdn - 1) / 1461;
    jdn = 4 * jdn - 1 - 1461 * y;
    d = jdn / 367;
    jdn = jdn - 367 * d + 365 - d / 4;
    m = jdn / 30;
    jdn = jdn - 30 * m + 30 - m / 12;
    char *str = malloc(11);
    sprintf(str, "%04d%02d%02d", y, m, jdn);
    return str;
}

// Main function
int main() {
    // Get the input string
    char str[11];
    printf("Enter a date (YYYYMMDD): ");
    scanf("%s", str);

    // Check if the string is empty
    if (is_empty(str)) {
        printf("Invalid date: The string is empty.\n");
        return 1;
    }

    // Check if the string is a valid date
    if (!is_valid_date(str)) {
        printf("Invalid date: The string is not a valid date.\n");
        return 1;
    }

    // Convert the string date to a Julian Day Number
    int jdn = to_julian_day(str);

    // Convert the Julian Day Number to a string date
    char *new_str = from_julian_day(jdn);

    // Print the converted string date
    printf("The converted date is: %s\n", new_str);

    // Free the allocated memory
    free(new_str);

    return 0;
}