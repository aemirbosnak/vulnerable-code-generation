//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

void parseDate(const char *dateStr, Date *date) {
    sscanf(dateStr, "%d-%d-%d", &date->day, &date->month, &date->year);
}

void convertDate(Date from, Date to, char *dateStr) {
    int diffYear = to.year - from.year;
    int diffMonth = to.month - from.month;
    int diffDay = to.day - from.day;

    if (diffYear >= 0) {
        strftime(dateStr, sizeof(dateStr), "%d-%d-%d", gmtime(&from.year));
    } else if (diffYear == -1) {
        if (diffMonth >= 0) {
            strftime(dateStr, sizeof(dateStr), "%d-%d", localtime(&to.year + 1));
        } else if (diffMonth == -1) {
            strftime(dateStr, sizeof(dateStr), "%d", localtime(&to.year + 1));
        }
    } else if (diffYear == -2) {
        if (diffMonth >= 0) {
            strftime(dateStr, sizeof(dateStr), "%d-%d", localtime(&to.year - 1));
        } else if (diffMonth == -1) {
            strftime(dateStr, sizeof(dateStr), "%d", localtime(&to.year - 1));
        }
    } else {
        printf("Invalid date difference\n");
        return;
    }

    strftime(dateStr, sizeof(dateStr), " %d", localtime(&to.day));
}

int main() {
    Date from;
    Date to;
    char fromStr[100], toStr[100];

    printf("Enter a C Natural Language Date in format YYYY-MM-DD:\n");
    scanf("%s", fromStr);

    parseDate(fromStr, &from);

    printf("Enter a C Natural Language Date in format YYYY-MM-DD:\n");
    scanf("%s", toStr);

    parseDate(toStr, &to);

    convertDate(from, to, toStr);

    printf("Converted date: %s\n", toStr);

    return 0;
}