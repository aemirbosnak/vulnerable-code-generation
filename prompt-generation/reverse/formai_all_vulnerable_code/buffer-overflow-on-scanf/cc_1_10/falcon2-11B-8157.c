//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct date {
    int year;
    int month;
    int day;
};

struct date next_day(struct date date) {
    struct date result = date;
    result.day++;
    if (result.day > 31) {
        result.month++;
        if (result.month > 12) {
            result.year++;
            result.month = 1;
        }
    }
    return result;
}

struct date next_week(struct date date) {
    struct date result = date;
    int days_to_next_week = 7 - date.day % 7;
    result.day += days_to_next_week;
    if (result.day > 31) {
        result.month++;
        if (result.month > 12) {
            result.year++;
            result.month = 1;
        }
    }
    return result;
}

struct date next_month(struct date date) {
    struct date result = date;
    result.day = 1;
    result.month++;
    if (result.month > 12) {
        result.year++;
        result.month = 1;
    }
    return result;
}

struct date next_year(struct date date) {
    struct date result = date;
    result.day = 1;
    result.month = 1;
    result.year++;
    return result;
}

int main() {
    struct date date;
    char input[50];

    printf("Enter a natural language date (e.g. \"next Friday\"): ");
    scanf("%s", input);

    sscanf(input, "%d-%d-%d", &date.year, &date.month, &date.day);

    if (strcmp(input, "next day") == 0) {
        date = next_day(date);
    } else if (strcmp(input, "next week") == 0) {
        date = next_week(date);
    } else if (strcmp(input, "next month") == 0) {
        date = next_month(date);
    } else if (strcmp(input, "next year") == 0) {
        date = next_year(date);
    } else {
        printf("Invalid input\n");
        return 1;
    }

    printf("Converted date: %d-%d-%d\n", date.year, date.month, date.day);
    return 0;
}