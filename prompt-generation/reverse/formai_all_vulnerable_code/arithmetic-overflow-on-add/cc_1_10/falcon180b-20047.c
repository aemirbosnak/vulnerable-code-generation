//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

#define MAX_MONTH_NAME_LENGTH 20
#define MAX_WEEKDAY_NAME_LENGTH 20

typedef struct {
    char* name;
    int length;
} Month;

typedef struct {
    char* name;
    int length;
} Weekday;

Month months[] = {
    { "January", 7 },
    { "February", 8 },
    { "March", 6 },
    { "April", 6 },
    { "May", 4 },
    { "June", 5 },
    { "July", 6 },
    { "August", 7 },
    { "September", 9 },
    { "October", 8 },
    { "November", 7 },
    { "December", 8 }
};

Weekday weekdays[] = {
    { "Sunday", 6 },
    { "Monday", 7 },
    { "Tuesday", 8 },
    { "Wednesday", 9 },
    { "Thursday", 8 },
    { "Friday", 6 },
    { "Saturday", 7 }
};

char* get_month_name(int month) {
    for (int i = 0; i < 12; i++) {
        if (months[i].length == month) {
            return months[i].name;
        }
    }
    return "Invalid month";
}

char* get_weekday_name(int weekday) {
    for (int i = 0; i < 7; i++) {
        if (weekdays[i].length == weekday) {
            return weekdays[i].name;
        }
    }
    return "Invalid weekday";
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    time_t now = time(NULL);
    struct tm* date = localtime(&now);

    printf("Today's date is %s, %s %d, %d\n", get_weekday_name(date->tm_wday), get_month_name(date->tm_mon), date->tm_mday, date->tm_year + 1900);

    return 0;
}