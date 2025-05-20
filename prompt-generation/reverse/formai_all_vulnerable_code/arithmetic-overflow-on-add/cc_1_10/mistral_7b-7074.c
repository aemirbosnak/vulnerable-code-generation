//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: surrealist
// Unravel the cosmic fabric of time itself
// With this mystical date converter, sorcerer of the bit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>

// Galactic clocks ticking in harmony
typedef struct {
    int day;
    int month;
    int year;
} StellarDate;

// Celestial orbital dance of numbers
StellarDate parseDate(char* dateString) {
    StellarDate result;
    int position = 0;

    while (position < 10 && isdigit(dateString[position])) {
        result.day *= 10;
        result.day += dateString[position] - '0';
        position++;
    }

    if (dateString[position++] != '/') {
        // Galactic anomaly: wrong date format
        exit(EXIT_FAILURE);
    }

    result.month = 0;

    while (position < 7 && isdigit(dateString[position])) {
        result.month *= 10;
        result.month += dateString[position] - '0';
        position++;

        if (dateString[position] == '/') {
            position++;
            break;
        }
    }

    if (dateString[position++] != '/') {
        // Cosmic paradox: missing separator
        exit(EXIT_FAILURE);
    }

    while (position < strlen(dateString) && isdigit(dateString[position])) {
        result.year *= 10;
        result.year += dateString[position] - '0';
        position++;
    }

    return result;
}

// Interstellar leap year calculation
int isLeapYear(int year) {
    if (year % 4 != 0) {
        return 0;
    }

    if (year % 100 == 0) {
        if (year % 400 == 0) {
            return 1;
        }
        return 0;
    }

    return 1;
}

// Quantum leap: seconds from StellarDate to UNIX time
time_t dateToSeconds(StellarDate date) {
    int daysInMonth[] = {31, isLeapYear(date.year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDays = 0;

    for (int i = 0; i < date.month - 1; i++) {
        totalDays += daysInMonth[i];
    }

    totalDays += date.day;

    time_t result = totalDays * 24 * 60 * 60;
    struct tm* timeInfo = localtime(&result);

    result = mktime(timeInfo);

    return result;
}

// Main function: enter the date and witness the cosmic dance of numbers
int main() {
    char dateString[20];
    StellarDate userDate;
    time_t dateEpoch;

    printf("Enter the date in dd/mm/yyyy format: ");
    scanf("%s", dateString);

    userDate = parseDate(dateString);

    dateEpoch = dateToSeconds(userDate);

    printf("The number of seconds elapsed since 29-February-1960 is: %ld\n", dateEpoch);

    return EXIT_SUCCESS;
}