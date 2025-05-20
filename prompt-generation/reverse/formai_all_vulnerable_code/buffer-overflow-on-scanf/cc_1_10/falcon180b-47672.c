//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int day;
    int month;
    int year;
} Date;

void parseDate(char *dateString, Date *date);
int isLeapYear(int year);
char *getMonthName(int month);
char *getDayName(int day);

int main() {
    char input[100];
    Date date;

    printf("Enter a date in the format 'dd/mm/yyyy': ");
    scanf("%s", input);

    parseDate(input, &date);

    printf("Today is %s, %d %s, %d\n", getDayName(date.day), date.day, getMonthName(date.month), date.month);

    return 0;
}

void parseDate(char *dateString, Date *date) {
    int i, j, k;
    char *token;

    token = strtok(dateString, "/");
    i = atoi(token);

    token = strtok(NULL, "/");
    j = atoi(token);

    token = strtok(NULL, "/");
    k = atoi(token);

    date->day = i;
    date->month = j;
    date->year = k;
}

int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100!= 0) || year % 400 == 0);
}

char *getMonthName(int month) {
    static char *monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    if (month >= 1 && month <= 12) {
        return monthNames[month - 1];
    } else {
        return "Invalid month";
    }
}

char *getDayName(int day) {
    static char *dayNames[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    if (day >= 1 && day <= 7) {
        return dayNames[day - 1];
    } else {
        return "Invalid day";
    }
}