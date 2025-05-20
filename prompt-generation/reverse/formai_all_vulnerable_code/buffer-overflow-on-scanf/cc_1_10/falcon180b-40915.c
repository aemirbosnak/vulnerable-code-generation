//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LENGTH 100
#define DAY_NAMES_LENGTH 7
#define MONTH_NAMES_LENGTH 12

struct date {
    int day;
    int month;
    int year;
};

char* day_names[DAY_NAMES_LENGTH] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
char* month_names[MONTH_NAMES_LENGTH] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void print_date(struct date* date) {
    printf("%s, %d %s %d\n", day_names[date->day], date->day, month_names[date->month], date->year);
}

void parse_date(char* input, struct date* date) {
    char* token;
    int i;

    token = strtok(input, ", ");
    date->day = atoi(token);

    token = strtok(NULL, ", ");
    for (i = 0; i < MONTH_NAMES_LENGTH; i++) {
        if (strcmp(token, month_names[i]) == 0) {
            date->month = i + 1;
            break;
        }
    }

    token = strtok(NULL, ", ");
    date->year = atoi(token);
}

int main() {
    char input[MAX_DATE_LENGTH];
    struct date date;

    printf("Enter a date in the format 'Day, Month Year': ");
    scanf("%s", input);

    parse_date(input, &date);
    print_date(&date);

    return 0;
}