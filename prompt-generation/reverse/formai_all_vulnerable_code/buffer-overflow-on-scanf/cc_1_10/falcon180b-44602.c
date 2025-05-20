//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

void get_date(char* input, Date* date) {
    char* token = strtok(input, " ");
    int i = 0;
    while (token!= NULL) {
        if (i == 0) {
            date->day = atoi(token);
        } else if (i == 1) {
            date->month = atoi(token);
        } else if (i == 2) {
            date->year = atoi(token);
        }
        token = strtok(NULL, " ");
        i++;
    }
}

char* get_month_name(int month) {
    switch (month) {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "Invalid month";
    }
}

char* get_day_of_week(int day) {
    switch (day) {
        case 0:
            return "Sunday";
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        default:
            return "Invalid day";
    }
}

void print_date(Date* date) {
    printf("The date is %s, %d %s %d\n", get_month_name(date->month), date->day, get_day_of_week(date->day), date->year);
}

int main() {
    char input[100];
    Date date;
    printf("Enter a date in the format dd/mm/yyyy: ");
    scanf("%s", input);
    get_date(input, &date);
    print_date(&date);
    return 0;
}