//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to check if a string is a valid date format
int isDate(char* date) {
    int i = 0, j = 0;
    while (date[i]) {
        if (!isdigit(date[i])) {
            // Check for separator
            if (date[i]!= '-') {
                return 0;
            }
            i++;
            j++;
        }
        i++;
    }
    if (j!= 2) {
        return 0;
    }
    return 1;
}

// Function to convert a date string to a time_t value
time_t strToTime(char* date) {
    struct tm tm = {0};
    tm.tm_year = atoi(date) - 1900;
    tm.tm_mon = 0;
    tm.tm_mday = 1;
    return mktime(&tm);
}

// Function to convert a time_t value to a date string
char* timeToStr(time_t time, int format) {
    char* str = malloc(20 * sizeof(char));
    struct tm* tm = gmtime(&time);
    strftime(str, 20, (format == 1)? "%Y-%m-%d" : "%d-%m-%Y", tm);
    return str;
}

int main() {
    char date[20];
    char* input;
    int format = 0;

    // Get user input
    printf("Enter a date (YYYY-MM-DD or DD-MM-YYYY): ");
    scanf("%s", date);

    // Check if input is a valid date format
    if (!isDate(date)) {
        printf("Invalid date format.\n");
        return 1;
    }

    // Convert input to time_t value
    time_t t = strToTime(date);

    // Convert time_t value to output format
    char* output;
    if (format == 0) {
        output = timeToStr(t, 0);
    } else {
        output = timeToStr(t, 1);
    }

    // Print output
    printf("Output date: %s\n", output);

    return 0;
}