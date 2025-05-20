//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

#define MAX_LENGTH 100

int is_valid_date(char* date_str, int* day, int* month, int* year);
char* get_month_name(int month);

int main() {
    char input_date[MAX_LENGTH];
    int day, month, year;

    printf("Enter a date in the format of DD/MM/YYYY: ");
    scanf("%s", input_date);

    if(is_valid_date(input_date, &day, &month, &year)) {
        printf("The date %s is valid and corresponds to %s %d, %d.\n", input_date, get_month_name(month), day, year);
    } else {
        printf("Invalid date.\n");
    }

    return 0;
}

int is_valid_date(char* date_str, int* day, int* month, int* year) {
    int len = strlen(date_str);
    if(len!= 10) {
        return 0;
    }

    char delimiter = date_str[2];
    if(delimiter!= '/') {
        return 0;
    }

    int day_val = atoi(date_str);
    if(day_val < 1 || day_val > 31) {
        return 0;
    }

    *day = day_val;

    int month_val = atoi(date_str + 3);
    if(month_val < 1 || month_val > 12) {
        return 0;
    }

    *month = month_val;

    int year_val = atoi(date_str + 6);
    if(year_val < 1000 || year_val > 9999) {
        return 0;
    }

    *year = year_val;

    return 1;
}

char* get_month_name(int month) {
    switch(month) {
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