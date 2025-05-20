//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_INPUT_LEN 25

void validateDate(int day, int month, int year) {
    if (isValidMonth(month) && isValidDay(day, month, year)) {
        printf("Valid Date: %d-%d-%d\n", day, month, year);
    } else {
        printf("Invalid Date: %d-%d-%d\n", day, month, year);
    }
}

int isValidMonth(int month) {
    return (month >= 1 && month <= 12);
}

int isValidDay(int day, int month, int year) {
    int totalDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isValidLeapYear(year))
        totalDays[2] = 29;
    return (day > 0 && day <= totalDays[month]);
}

int isValidLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int main() {
    char str[MAX_INPUT_LEN];
    int day, month, year;
    sscanf(gets(str), "%d-%d-%d%*c", &day, &month, &year);

    if (strlen(str) == MAX_INPUT_LEN) {
        printf("Input too long, try 'dd-mm-yyyy' or 'dd.mm.yyyy' format\n");
        return 1;
    }

    if (str[0] == '.')
        sscanf(str, "%d.%d.%d%*c", &day, &month, &year);

    validateDate(day, month, year);

    struct tm timeStruct = {0};
    timeStruct.tm_year = year - 1900;
    timeStruct.tm_mon = month - 1;
    timeStruct.tm_mday = day;
    time_t unixTimestamp = mktime(&timeStruct);

    printf("Unix Timestamp for the given date is: %ld\n", (long int)unixTimestamp);

    return 0;
}