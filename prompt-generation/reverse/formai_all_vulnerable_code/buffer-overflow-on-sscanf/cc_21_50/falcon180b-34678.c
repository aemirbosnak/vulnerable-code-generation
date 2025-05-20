//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <date>\n", argv[0]);
        return 1;
    }
    Date date;
    if (sscanf(argv[1], "%d-%d-%d", &date.day, &date.month, &date.year) == 3) {
        if (date.day >= 1 && date.day <= 31 && date.month >= 1 && date.month <= 12 && date.year >= 1000 && date.year <= 9999) {
            char *month_name = "";
            if (date.month == 1) {
                month_name = "January";
            } else if (date.month == 2) {
                month_name = "February";
            } else if (date.month == 3) {
                month_name = "March";
            } else if (date.month == 4) {
                month_name = "April";
            } else if (date.month == 5) {
                month_name = "May";
            } else if (date.month == 6) {
                month_name = "June";
            } else if (date.month == 7) {
                month_name = "July";
            } else if (date.month == 8) {
                month_name = "August";
            } else if (date.month == 9) {
                month_name = "September";
            } else if (date.month == 10) {
                month_name = "October";
            } else if (date.month == 11) {
                month_name = "November";
            } else if (date.month == 12) {
                month_name = "December";
            }
            printf("The date is: %d %s %d\n", date.day, month_name, date.year);
        } else {
            fprintf(stderr, "Invalid date: %s\n", argv[1]);
        }
    } else {
        fprintf(stderr, "Invalid date: %s\n", argv[1]);
    }
    return 0;
}