//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_DATE_LENGTH 20
#define MONTH_NAMES_LENGTH 12
#define WEEK_DAY_NAMES_LENGTH 7

char *month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
char *week_day_names[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void set_locale() {
    setlocale(LC_ALL, "");
}

int is_valid_date(int day, int month, int year) {
    if (month < 1 || month > 12) {
        return 0;
    }

    switch (month) {
        case 2:
            if (day > 29 &&!(year % 4 == 0 && (year % 100!= 0 || year % 400 == 0))) {
                return 0;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day > 30) {
                return 0;
            }
            break;
        default:
            if (day > 31) {
                return 0;
            }
            break;
    }

    return 1;
}

void convert_date_to_words(int day, int month, int year, char *date_string) {
    set_locale();

    strftime(date_string, MAX_DATE_LENGTH, "%A, %B %d, %Y", localtime(&year));
}

int main() {
    int day, month, year;

    printf("Enter the day (1-31): ");
    scanf("%d", &day);

    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    printf("Enter the year (YYYY): ");
    scanf("%d", &year);

    if (is_valid_date(day, month, year)) {
        char date_string[MAX_DATE_LENGTH];
        convert_date_to_words(day, month, year, date_string);
        printf("The date is: %s\n", date_string);
    } else {
        printf("Invalid date.\n");
    }

    return 0;
}