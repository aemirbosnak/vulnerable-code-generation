//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100

struct date {
    int day;
    int month;
    int year;
};

void parse_date(const char* input_date, struct date* date) {
    char* token = strtok(input_date, " ");
    if (token == NULL) {
        printf("Invalid date format\n");
        exit(1);
    }

    date->day = atoi(token);

    token = strtok(NULL, " ");
    if (token == NULL) {
        printf("Invalid date format\n");
        exit(1);
    }

    date->month = atoi(token);

    token = strtok(NULL, " ");
    if (token == NULL) {
        printf("Invalid date format\n");
        exit(1);
    }

    date->year = atoi(token);
}

void convert_date_to_words(struct date date, char* output_date) {
    char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    sprintf(output_date, "%d %s %d", date.day, months[date.month - 1], date.year);
}

int main() {
    char input_date[MAX_STRING_LENGTH];
    printf("Enter a date in the format DD/MM/YYYY: ");
    fgets(input_date, MAX_STRING_LENGTH, stdin);

    struct date date;
    parse_date(input_date, &date);

    char output_date[MAX_STRING_LENGTH];
    convert_date_to_words(date, output_date);

    printf("The date %s is %s\n", input_date, output_date);

    return 0;
}