//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATE_LEN 20
#define MAX_MONTHS 12
#define MAX_DAYS_IN_MONTH 31

const char *MONTH_NAMES[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

const char *DAY_NAMES[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

struct Date {
    int day;
    int month;
    int year;
};

int is_valid_date(struct Date date) {
    if (date.year < 1 || date.year > 9999) {
        return 0;
    }
    if (date.month < 1 || date.month > 12) {
        return 0;
    }
    if (date.day < 1 || date.day > MAX_DAYS_IN_MONTH) {
        return 0;
    }
    return 1;
}

struct Date read_date(void) {
    struct Date date;
    char input[MAX_DATE_LEN];

    printf("Enter a date (dd/mm/yyyy): ");
    scanf("%s", input);

    char *ptr = input;
    date.day = atoi(ptr);
    while (*ptr++ != '/');
    date.month = atoi(ptr);
    while (*ptr++ != '/');
    date.year = atoi(ptr);

    return date;
}

void print_date(struct Date date) {
    printf("%02d/%02d/%04d\n", date.day, date.month, date.year);
}

int main(void) {
    struct Date date = read_date();

    if (!is_valid_date(date)) {
        printf("Invalid date!\n");
        return 1;
    }

    printf("The date you entered is: ");
    print_date(date);

    return 0;
}