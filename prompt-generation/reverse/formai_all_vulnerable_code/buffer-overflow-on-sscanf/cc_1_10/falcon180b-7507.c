//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATE_LENGTH 100

struct date {
    int day;
    int month;
    int year;
};

char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int is_valid_date(const char *date_str) {
    struct date date;
    int day, month, year;
    char delimiter;
    if (sscanf(date_str, "%d%c%d%c%d", &day, &delimiter, &month, &delimiter, &year)!= 5) {
        return 0;
    }
    if (!isdigit(day) ||!isdigit(month) ||!isdigit(year)) {
        return 0;
    }
    if (month < 1 || month > 12) {
        return 0;
    }
    if (day < 1 || day > 31) {
        return 0;
    }
    if (year < 1000 || year > 9999) {
        return 0;
    }
    return 1;
}

char *convert_date(const char *date_str) {
    struct date date;
    if (!is_valid_date(date_str)) {
        return NULL;
    }
    date.day = atoi(date_str);
    date.month = atoi(date_str + 3);
    date.year = atoi(date_str + 6);
    return asctime(mktime(&date));
}

int main() {
    char input[MAX_DATE_LENGTH];
    printf("Enter a date (dd/mm/yyyy): ");
    fgets(input, MAX_DATE_LENGTH, stdin);
    char *result = convert_date(input);
    if (result!= NULL) {
        printf("Natural language date: %s\n", result);
    } else {
        printf("Invalid date format!\n");
    }
    return 0;
}