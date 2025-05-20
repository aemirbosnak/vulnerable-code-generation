//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STRING_LENGTH 1000
#define MONTH_NAMES_LENGTH 12
#define WEEK_DAY_NAMES_LENGTH 7

typedef struct {
    char* name;
    int length;
} NameLength;

NameLength monthNames[MONTH_NAMES_LENGTH] = {{"January"}, 7};
NameLength weekDayNames[WEEK_DAY_NAMES_LENGTH] = {{"Sunday"}, 7};

int main() {
    char input[MAX_STRING_LENGTH];
    time_t now = time(0);
    struct tm* timeInfo = localtime(&now);

    printf("Enter a date (YYYY-MM-DD): ");
    scanf("%s", input);

    int year, month, day;
    sscanf(input, "%d-%d-%d", &year, &month, &day);

    if (month < 1 || month > 12) {
        printf("Invalid month.\n");
        return 1;
    }

    if (day < 1 || day > 31) {
        printf("Invalid day.\n");
        return 1;
    }

    if (month == 2) {
        if (day > 29) {
            printf("Invalid day for February.\n");
            return 1;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            printf("Invalid day.\n");
            return 1;
        }
    }

    printf("Today is %s, %d %s %d.\n", weekDayNames[timeInfo->tm_wday].name, day, monthNames[month - 1].name, year);

    return 0;
}