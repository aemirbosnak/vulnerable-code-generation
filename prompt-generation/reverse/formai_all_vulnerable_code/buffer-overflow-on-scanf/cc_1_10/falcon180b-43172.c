//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

struct tm date; // holds the date

void set_date(int year, int month, int day) {
    date.tm_year = year - 1900; // adjust for 1900 offset
    date.tm_mon = month - 1; // adjust for 0 offset
    date.tm_mday = day;
}

void print_date(char* format) {
    char buffer[MAX_LEN];
    strftime(buffer, MAX_LEN, format, &date);
    printf("%s\n", buffer);
}

int main() {
    int year, month, day;
    char input_date[MAX_LEN];

    printf("Enter a date in the format YYYY-MM-DD: ");
    scanf("%s", input_date);

    // parse input date
    sscanf(input_date, "%d-%d-%d", &year, &month, &day);

    // print original date
    print_date("%Y-%m-%d");

    // convert date to natural language format
    char* month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char* day_names[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    printf("On a %s, in the fair city of Verona,\n", day_names[date.tm_wday]);
    printf("Two households, both alike in dignity,\n");
    printf("In fair %s, where we lay our scene,\n", month_names[date.tm_mon]);
    printf("From ancient grudge break to new mutiny,\n");
    printf("Where civil blood makes civil hands unclean.\n\n");

    // print date as Romeo and Juliet would say it
    printf("It is the %d day of %s,\n", day + 1, month_names[date.tm_mon]);
    printf("In the year of our Lord %d,\n", year + 1900);

    return 0;
}