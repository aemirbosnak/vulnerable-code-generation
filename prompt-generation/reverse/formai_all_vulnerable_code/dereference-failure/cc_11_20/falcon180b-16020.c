//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main() {
    char input[256];
    char *token;
    struct tm date;
    time_t timestamp;
    int day, month, year;
    int hour, minute, second;

    // Get input from user
    printf("Enter a date in the format 'Month Day, Year Hour:Minute:Second': ");
    fgets(input, sizeof(input), stdin);

    // Parse input string
    strtok(input, " ");
    strcpy(input, strtok(NULL, ","));
    strcpy(input, strtok(NULL, ","));
    strcpy(input, strtok(NULL, ","));
    strcpy(input, strtok(NULL, " "));

    // Convert input string to date and time
    if (sscanf(input, "%d:%d:%d", &hour, &minute, &second)!= 3) {
        fprintf(stderr, "Invalid time format\n");
        return 1;
    }
    if (sscanf(input, "%d/%d/%d", &month, &day, &year)!= 3) {
        fprintf(stderr, "Invalid date format\n");
        return 1;
    }

    // Validate date and time components
    if (month < 1 || month > 12) {
        fprintf(stderr, "Invalid month\n");
        return 1;
    }
    if (day < 1 || day > 31) {
        fprintf(stderr, "Invalid day\n");
        return 1;
    }
    if (hour < 0 || hour > 23) {
        fprintf(stderr, "Invalid hour\n");
        return 1;
    }
    if (minute < 0 || minute > 59) {
        fprintf(stderr, "Invalid minute\n");
        return 1;
    }
    if (second < 0 || second > 59) {
        fprintf(stderr, "Invalid second\n");
        return 1;
    }

    // Set date and time components
    date.tm_mon = month - 1;
    date.tm_mday = day;
    date.tm_year = year - 1900;
    date.tm_hour = hour;
    date.tm_min = minute;
    date.tm_sec = second;

    // Convert date and time to timestamp
    timestamp = mktime(&date);

    // Print result
    printf("Timestamp: %ld\n", timestamp);
    printf("Date and time: %s", ctime(&timestamp));

    return 0;
}