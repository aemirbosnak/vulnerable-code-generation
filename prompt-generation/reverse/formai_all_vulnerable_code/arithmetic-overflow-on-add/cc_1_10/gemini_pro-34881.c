//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DAYS_IN_YEAR 365
#define DAYS_IN_MONTH 30
#define MONTHS_IN_YEAR 12

// Structure to store a date
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Function to convert a string to a date
Date stringToDate(char *string) {
    Date date;
    sscanf(string, "%d/%d/%d", &date.day, &date.month, &date.year);
    return date;
}

// Function to convert a date to a string
char *dateToString(Date date) {
    char *string = malloc(11);
    sprintf(string, "%02d/%02d/%04d", date.day, date.month, date.year);
    return string;
}

// Function to add a number of days to a date
Date addDaysToDate(Date date, int days) {
    date.day += days;
    while (date.day > DAYS_IN_MONTH) {
        date.day -= DAYS_IN_MONTH;
        date.month++;
    }
    while (date.month > MONTHS_IN_YEAR) {
        date.month -= MONTHS_IN_YEAR;
        date.year++;
    }
    return date;
}

// Function to subtract a number of days from a date
Date subtractDaysFromDate(Date date, int days) {
    date.day -= days;
    while (date.day < 1) {
        date.month--;
        date.day += DAYS_IN_MONTH;
    }
    while (date.month < 1) {
        date.year--;
        date.month += MONTHS_IN_YEAR;
    }
    return date;
}

// Function to print a date in a romantic style
void printDateRomantically(Date date) {
    char *string = dateToString(date);
    printf("On %s, amidst the moon's gentle glow,\n", string);
    printf("Our hearts intertwined, a love so pure, like fresh-fallen snow.\n");
    free(string);
}

int main() {
    // Get the current date
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    Date currentDate = {tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900};

    // Print the current date in a romantic style
    printDateRomantically(currentDate);

    // Add 100 days to the current date
    Date futureDate = addDaysToDate(currentDate, 100);

    // Print the future date in a romantic style
    printDateRomantically(futureDate);

    return 0;
}