//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DATE_LENGTH 30

enum {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER,
};

const char* month_names[] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December",
};

const char* day_names[] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
};

const char* date_format = "%A, %B %d, %Y";

char* convert_date(time_t timestamp) {
    struct tm* tm = localtime(&timestamp);
    char date_buffer[MAX_DATE_LENGTH];
    strftime(date_buffer, MAX_DATE_LENGTH, date_format, tm);
    char* date_string = strdup(date_buffer);
    return date_string;
}

int main() {
    time_t timestamp;
    char* date_string;

    printf("Enter a timestamp in seconds since January 1, 1970: ");
    scanf("%ld", &timestamp);

    date_string = convert_date(timestamp);
    printf("The date is: %s\n", date_string);

    free(date_string);
    return 0;
}