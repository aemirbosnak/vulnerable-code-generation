//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function to convert a given date string to a struct tm object
struct tm* string_to_tm(char* date_str) {
    struct tm tm = {0};
    int day, month, year, hour, minute, second;
    char* token;

    // Parse day
    token = strtok(date_str, " ");
    if (token == NULL) {
        return NULL;
    }
    day = atoi(token);

    // Parse month
    token = strtok(NULL, " ");
    if (token == NULL) {
        return NULL;
    }
    month = atoi(token);

    // Parse year
    token = strtok(NULL, " ");
    if (token == NULL) {
        return NULL;
    }
    year = atoi(token);

    // Parse time
    token = strtok(NULL, " ");
    if (token == NULL) {
        return NULL;
    }
    hour = atoi(token);

    token = strtok(NULL, ":");
    if (token == NULL) {
        return NULL;
    }
    minute = atoi(token);

    token = strtok(NULL, ":");
    if (token == NULL) {
        return NULL;
    }
    second = atoi(token);

    // Set tm struct
    tm.tm_sec = second;
    tm.tm_min = minute;
    tm.tm_hour = hour;
    tm.tm_mday = day;
    tm.tm_mon = month - 1;
    tm.tm_year = year - 1900;
    tm.tm_isdst = -1;

    return &tm;
}

// Function to convert a struct tm object to a natural language date string
char* tm_to_string(struct tm* tm) {
    char* date_str = malloc(100);
    strftime(date_str, 100, "%A, %B %d, %Y %I:%M %p", tm);
    return date_str;
}

int main() {
    char input[100];
    struct tm* tm;
    char* output;

    // Prompt user for input
    printf("Enter a date in the format 'Day Month Year Hour:Minute:Second' (e.g. 'Monday July 4 2022 10:30:00'):\n");
    scanf("%s", input);

    // Convert input to struct tm
    tm = string_to_tm(input);
    if (tm == NULL) {
        printf("Invalid date.\n");
        return 1;
    }

    // Convert struct tm to natural language string
    output = tm_to_string(tm);

    // Print result
    printf("The date is %s.\n", output);
    free(output);

    return 0;
}