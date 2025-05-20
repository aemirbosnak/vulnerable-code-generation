//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: dynamic
#include <stdio.h>
#include <string.h>

struct date {
    int day;
    int month;
    int year;
};

char *months[] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"
};

int daysInMonth(int month, int year) {
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return 29; // leap year
    }
    return days[month - 1];
}

int isValidDate(struct date d) {
    if(d.month < 1 || d.month > 12)
        return 0; // invalid month
    if(d.day < 1 || d.day > daysInMonth(d.month, d.year))
        return 0; // invalid day
    return 1; // valid date
}

int daysInYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 366 : 365;
}

int daysBetween(struct date d1, struct date d2) {
    int days = 0;
    if(d1.year == d2.year) { // same year
        if(d1.month == d2.month) { // same month
            days = d2.day - d1.day;
        } else { // different month
            for(int i = d1.month; i < d2.month; i++) {
                days += daysInMonth(i, d1.year);
            }
            days -= d1.day;
            days += d2.day;
        }
    } else { // different years
        days = daysInYear(d1.year) - d1.day; // days left in d1's year
        for(int i = d1.month + 1; i <= 12; i++) {
            days += daysInMonth(i, d1.year);
        }
        for(int i = d1.year + 1; i < d2.year; i++) {
            days += daysInYear(i);
        }
        for(int i = 1; i < d2.month; i++) {
            days += daysInMonth(i, d2.year);
        }
        days += d2.day; // days elapsed in d2's year
    }
    return days;
}

void convert(char *input) {
    char *token = strtok(input, " ");
    int i = 0;
    int dateCount = 0;
    struct date dates[2];
    while(token != NULL && dateCount < 2) {
        if(sscanf(token, "%d-%d-%d", &dates[dateCount].year, &dates[dateCount].month, &dates[dateCount].day) == 3) {
            dateCount++;
        }
        token = strtok(NULL, " ");
    }
    if(dateCount == 2) { // two valid dates
        if(isValidDate(dates[0]) && isValidDate(dates[1])) {
            int days = daysBetween(dates[0], dates[1]);
            printf("%d days between %s %d, %d and %s %d, %d\n", 
                days, months[dates[0].month - 1], dates[0].day, dates[0].year, 
                months[dates[1].month - 1], dates[1].day, dates[1].year);
        } else {
            printf("Invalid date(s).\n");
        }
    } else {
        printf("Two dates separated by a space required.\n");
    }
}

int main() {
    char input[100];
    printf("Enter two dates (yyyy-mm-dd yyyy-mm-dd): ");
    fgets(input, 100, stdin);
    convert(input);
    return 0;
}