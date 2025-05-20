//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
    int day;
    int month;
    int year;
} Date;

void get_date_from_user(Date* date) {
    char input[MAX_LEN];
    int day, month, year;
    int is_valid = 0;

    printf("Fair noble youth, pray tell me this:\n");
    printf("What month, what day, what year, I pray,\n");
    printf("That I may witness thy sweet love's birth?\n");

    fgets(input, MAX_LEN, stdin);
    sscanf(input, "%d/%d/%d", &month, &day, &year);

    if (month < 1 || month > 12 || day < 1 || day > 31) {
        printf("I'm sorry, that's an invalid date.\n");
        exit(1);
    }

    date->day = day;
    date->month = month;
    date->year = year;
    is_valid = 1;
}

void print_date(Date date) {
    char month_names[13][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December", "Invalid"};

    printf("Ah, fair maiden, thy date of birth:\n");
    printf("'Tis %s %d, %d, I do beseech.\n", month_names[date.month], date.day, date.year);
}

int main() {
    Date date;

    get_date_from_user(&date);
    print_date(date);

    return 0;
}