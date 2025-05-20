//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 20

struct date_t {
    int day;
    int month;
    int year;
};

struct date_t parse_date(char* input) {
    struct date_t date = {0};
    char* token = strtok(input, " ");
    while (token!= NULL) {
        if (strlen(token) > MAX_WORD_LENGTH) {
            printf("Error: Invalid date format\n");
            exit(1);
        }
        if (date.day == 0 && strlen(token) == 2) {
            date.day = atoi(token);
        } else if (date.month == 0 && strlen(token) == 3) {
            date.month = atoi(token);
        } else if (date.year == 0 && strlen(token) == 4) {
            date.year = atoi(token);
        }
        token = strtok(NULL, " ");
    }
    if (date.day == 0 || date.month == 0 || date.year == 0) {
        printf("Error: Invalid date format\n");
        exit(1);
    }
    return date;
}

void print_date(struct date_t date) {
    printf("Day: %d\n", date.day);
    printf("Month: %d\n", date.month);
    printf("Year: %d\n", date.year);
}

void main() {
    char input[100];
    printf("Enter a date in the format DD/MM/YYYY: ");
    scanf("%s", input);
    struct date_t date = parse_date(input);
    printf("You entered the date: ");
    print_date(date);
}