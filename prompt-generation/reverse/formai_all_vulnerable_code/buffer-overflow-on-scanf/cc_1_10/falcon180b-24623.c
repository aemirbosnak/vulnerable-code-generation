//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct tm getDate(char* strDate) {
    struct tm date = {0};
    char* pch = strtok(strDate, " ");
    if (pch == NULL) {
        return date;
    }
    strcpy(date.tm_mon, pch);
    pch = strtok(NULL, " ");
    if (pch == NULL) {
        return date;
    }
    strcpy(date.tm_mday, pch);
    pch = strtok(NULL, " ");
    if (pch == NULL) {
        return date;
    }
    strcpy(date.tm_year, pch);
    pch = strtok(NULL, " ");
    if (pch == NULL) {
        return date;
    }
    strcpy(date.tm_hour, pch);
    pch = strtok(NULL, " ");
    if (pch == NULL) {
        return date;
    }
    strcpy(date.tm_min, pch);
    pch = strtok(NULL, " ");
    if (pch == NULL) {
        return date;
    }
    strcpy(date.tm_sec, pch);
    date.tm_year -= 1900;
    date.tm_mon--;
    date.tm_mday--;
    date.tm_hour--;
    date.tm_min--;
    date.tm_sec--;
    return date;
}

char* getDayName(int day) {
    static char days[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days[day];
}

char* getMonthName(int month) {
    static char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[month];
}

int main() {
    char input[100];
    printf("Enter a date in the format 'dd/mm/yyyy hh:mm:ss': ");
    scanf("%s", input);
    struct tm date = getDate(input);
    if (date.tm_year < 1900 || date.tm_mon < 0 || date.tm_mday < 1 || date.tm_hour < 0 || date.tm_min < 0 || date.tm_sec < 0) {
        printf("Invalid date.\n");
        return 1;
    }
    char* dayName = getDayName(date.tm_wday);
    char* monthName = getMonthName(date.tm_mon + 1);
    printf("Today is %s, %d %s %d.\n", dayName, date.tm_mday, monthName, date.tm_year + 1900);
    return 0;
}