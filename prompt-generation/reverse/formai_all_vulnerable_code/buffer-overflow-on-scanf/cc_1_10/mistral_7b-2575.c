//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

const char* MONTHS[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

int isLeapYear(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int daysInMonth(int year, int month) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }

    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[month - 1];
}

void parseDate(const char* dateStr, Date* date) {
    char monthStr[10];
    int index = sscanf(dateStr, "%d-%[^/]-%d", &date->year, monthStr, &date->day);

    if (index != 2) {
        printf("Invalid date format: %s\n", dateStr);
        exit(1);
    }

    for (int i = 0; i < 12; i++) {
        if (strcmp(MONTHS[i], monthStr) == 0) {
            date->month = i + 1;
            break;
        }
    }
}

void printDate(const Date* date) {
    printf("%d %s %d\n", date->year, MONTHS[date->month - 1], date->day);
}

int main() {
    char input[100];
    Date date;

    printf("Enter a date in the format YYYY-MM-DD: ");
    scanf("%s", input);

    parseDate(input, &date);

    printf("Date converted: ");
    printDate(&date);

    time_t currentTime = time(NULL);
    struct tm* localTime = localtime(&currentTime);

    printf("Current date: %s %s %d\n", asctime(localTime));

    return 0;
}