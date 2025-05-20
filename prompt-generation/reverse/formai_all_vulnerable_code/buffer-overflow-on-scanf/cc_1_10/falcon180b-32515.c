//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

// Function to convert a given date string to a struct tm
struct tm convertDateString(const char* dateStr) {
    struct tm date = {0};
    strptime(dateStr, "%d %B %Y", &date);
    return date;
}

// Function to convert a given time string to a time_t
time_t convertTimeString(const char* timeStr) {
    struct tm time = {0};
    strptime(timeStr, "%I:%M %p", &time);
    return mktime(&time);
}

// Function to convert a given date and time string to a time_t
time_t convertDateTimeString(const char* dateTimeStr) {
    struct tm dateTime = {0};
    strptime(dateTimeStr, "%d %B %Y %I:%M %p", &dateTime);
    return mktime(&dateTime);
}

// Function to convert a time_t to a human-readable date and time string
char* convertTimeToString(time_t time) {
    char* result = calloc(20, sizeof(char));
    strftime(result, 20, "%Y-%m-%d %H:%M:%S", localtime(&time));
    return result;
}

// Function to convert a time_t to a natural language date and time string
char* convertDateTimeToNaturalLanguage(time_t time) {
    char* result = calloc(30, sizeof(char));
    struct tm* dateTime = localtime(&time);
    strftime(result, 30, "%A, %d %B %Y %I:%M %p", dateTime);
    return result;
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    char input[100];

    while (1) {
        printf("Enter a date and time in the format DD/MM/YYYY HH:MM AM/PM or exit to quit: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        time_t time = convertDateTimeString(input);
        char* naturalLanguageDate = convertDateTimeToNaturalLanguage(time);
        printf("The natural language date and time is: %s\n", naturalLanguageDate);
    }

    return 0;
}