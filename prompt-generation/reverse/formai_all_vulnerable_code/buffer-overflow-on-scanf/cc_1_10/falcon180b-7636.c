//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_LENGTH 100

struct date {
    int month;
    int day;
    int year;
};

struct date parse_date(char* input) {
    struct date date = {0};
    char* token;
    int count = 0;

    token = strtok(input, " ");
    while (token!= NULL && count < MAX_LENGTH) {
        if (count == 0) {
            date.month = atoi(token);
        } else if (count == 1) {
            date.day = atoi(token);
        } else if (count == 2) {
            date.year = atoi(token);
            break;
        }
        count++;
        token = strtok(NULL, " ");
    }

    if (count!= 3) {
        printf("Invalid date format\n");
        exit(1);
    }

    return date;
}

char* format_date(struct date date) {
    char* output;
    char* month_str;
    char* day_str;
    char* year_str;

    month_str = (date.month < 10)? "0" : "";
    day_str = (date.day < 10)? "0" : "";
    year_str = (date.year < 1000)? "" : (date.year < 10000)? "0" : "";

    output = malloc(strlen(date.month) + strlen(day_str) + strlen(year_str) + 3);
    sprintf(output, "%s%s%s", month_str, day_str, year_str);

    return output;
}

int main() {
    char input[MAX_LENGTH];
    struct date date;
    char* output;

    printf("Enter a date in the format MM DD YYYY: ");
    scanf("%s", input);

    date = parse_date(input);
    output = format_date(date);

    printf("Formatted date: %s\n", output);

    free(output);
    return 0;
}