//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_YEAR 9999
#define MAX_MONTH 12

// Function to check if a string is a valid date
int is_valid_date(char* date) {
    char* token = strtok(date, " ");
    if(token == NULL) {
        return 0;
    }
    int year = atoi(token);
    token = strtok(NULL, " ");
    if(token == NULL) {
        return 0;
    }
    int month = atoi(token);
    if(month < 1 || month > MAX_MONTH) {
        return 0;
    }
    token = strtok(NULL, " ");
    if(token == NULL) {
        return 0;
    }
    int day = atoi(token);
    if(day < 1 || day > 31) {
        return 0;
    }
    return 1;
}

// Function to convert a date string to a struct tm
struct tm* string_to_tm(char* date) {
    struct tm tm = {0};
    char* token = strtok(date, " ");
    tm.tm_year = atoi(token) - 1900;
    token = strtok(NULL, " ");
    tm.tm_mon = atoi(token) - 1;
    token = strtok(NULL, " ");
    tm.tm_mday = atoi(token);
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    tm.tm_isdst = -1;
    return &tm;
}

// Function to convert a struct tm to a string
char* tm_to_string(struct tm* tm) {
    static char buffer[100];
    strftime(buffer, 100, "%d %B %Y", tm);
    return buffer;
}

int main() {
    char input[100];
    printf("Enter a date (dd mmm yyyy): ");
    scanf("%s", input);

    struct tm* tm = string_to_tm(input);
    if(tm == NULL) {
        printf("Invalid date.\n");
        return 1;
    }

    char* output = tm_to_string(tm);
    printf("The date is %s.\n", output);

    return 0;
}