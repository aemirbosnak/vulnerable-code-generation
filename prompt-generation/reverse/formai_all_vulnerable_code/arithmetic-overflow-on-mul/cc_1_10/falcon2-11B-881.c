//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: realistic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_DATE_LENGTH 30
#define MAX_MONTH_LENGTH 3
#define MAX_DAY_LENGTH 2

typedef struct {
    int year;
    int month;
    int day;
} Date;

void parseDate(const char *date, Date *d) {
    int i = 0;
    int day = 1;
    int month = 1;
    int year = 1970;

    while (date[i]!= '\0' && isspace(date[i])) {
        i++;
    }

    while (date[i]!= '\0' &&!isspace(date[i])) {
        if (isdigit(date[i])) {
            d->year = d->year * 10 + (date[i] - '0');
            i++;
        } else if (date[i] == '/') {
            i++;
            if (isdigit(date[i])) {
                d->month = d->month * 10 + (date[i] - '0');
                i++;
            } else if (date[i] == '-') {
                i++;
                if (isdigit(date[i])) {
                    d->day = d->day * 10 + (date[i] - '0');
                    i++;
                } else {
                    break;
                }
            } else {
                break;
            }
        } else {
            break;
        }
    }

    if (i < MAX_DATE_LENGTH) {
        printf("Invalid date format\n");
        return;
    }
}

int main() {
    char date[MAX_DATE_LENGTH];

    printf("Enter a date in natural language format: ");
    fgets(date, sizeof(date), stdin);

    Date d;
    parseDate(date, &d);

    printf("Machine-readable date format: %02d/%02d/%04d\n", d.month, d.day, d.year);

    return 0;
}