//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int parseDate(char *dateString) {
    char month[3], day[3], year[9];
    int days;

    strncpy(month, dateString, 3);
    strncpy(day, &dateString[4], 2);
    strncpy(year, &dateString[7], 9);

    month[2] = '\0';
    day[2] = '\0';
    year[8] = '\0';

    if (isdigit(month[0])) {
        days = 0;
    } else {
        days = 31;
    }

    if (isdigit(day[0])) {
        days += (atoi(day) - 1);
    } else {
        days += (isdigit(month[0])? (atoi(month) - 1) : 0);
    }

    if (isdigit(year[0])) {
        days += 365 * (atoi(year) - 2000);
    } else {
        days += 366 * (atoi(year) - 2000);
    }

    return days;
}

int main() {
    char dateString[30];
    int daysElapsed;

    printf("Enter a date in natural language format: ");
    fgets(dateString, sizeof(dateString), stdin);
    dateString[strcspn(dateString, "\n")] = '\0'; // remove newline character

    daysElapsed = parseDate(dateString);
    printf("The number of days elapsed since January 1, 2000 is: %d\n", daysElapsed);

    return 0;
}