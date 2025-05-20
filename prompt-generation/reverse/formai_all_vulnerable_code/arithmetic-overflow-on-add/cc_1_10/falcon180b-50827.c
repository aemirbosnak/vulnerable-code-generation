//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

#define MAX_LENGTH 100

typedef struct {
    const char *month[12];
    const char *day[7];
    const char *weekday[7];
} Language;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [date] [output_language]\n", argv[0]);
        return 1;
    }

    char input_date[MAX_LENGTH];
    strcpy(input_date, argv[1]);

    char output_language[MAX_LENGTH];
    strcpy(output_language, argv[2]);

    struct tm date;
    strptime(input_date, "%Y-%m-%d", &date);

    Language language = {
       .month = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"},
       .day = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"},
       .weekday = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}
    };

    setlocale(LC_ALL, output_language);

    printf("Today's date is ");
    if (date.tm_mday == 1) {
        printf("%d ", date.tm_mon + 1);
        printf("%s, ", language.month[date.tm_mon]);
    } else {
        printf("%d ", date.tm_mday);
        if (date.tm_mday == 21) {
            printf("%s ", language.day[date.tm_wday]);
        }
    }

    printf("%s, %d\n", language.month[date.tm_mon], date.tm_year + 1900);

    return 0;
}