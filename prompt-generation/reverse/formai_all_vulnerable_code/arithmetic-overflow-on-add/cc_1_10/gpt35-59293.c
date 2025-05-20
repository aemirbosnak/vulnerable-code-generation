//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int day;
    int month;
    int year;
} Date;

char* c_month_name(int month){
    switch (month){
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
    }
    return "";
}

void print_date(Date date){
    char* month_name = c_month_name(date.month);
    printf("%s %d, %d", month_name, date.day, date.year);
}

int is_leap_year(int year){
    if (year % 4 != 0) return 0;
    if (year % 100 != 0) return 1;
    if (year % 400 != 0) return 0;
    return 1;
}

int get_days_in_month(int month, int year){
    if (month == 2) return is_leap_year(year) ? 29 : 28;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    return 31;
}

int is_valid_date(Date date){
    if (date.month < 1 || date.month > 12) return 0;
    if (date.day < 1 || date.day > get_days_in_month(date.month, date.year)) return 0;
    return 1;
}

Date parse_date(char* date_str){
    Date date = {0, 0, 0};
    sscanf(date_str, "%2d-%2d-%4d", &date.month, &date.day, &date.year);
    return date;
}

void add_days(Date* date, int days){
    while (days > 0){
        int days_in_month = get_days_in_month(date->month, date->year);
        int days_to_add = days;
        if (date->day + days_to_add > days_in_month){
            days_to_add = days_in_month - date->day + 1;
            date->day = 1;
            if (date->month == 12){
                date->year++;
                date->month = 1;
            } else {
                date->month++;
            }
        } else {
            date->day += days_to_add;
        }
        days -= days_to_add;
    }
}

int main(){
    char date_str[20];
    int days_to_add;
    printf("Enter date in format mm-dd-yyyy: ");
    scanf("%s", date_str);
    Date date = parse_date(date_str);
    printf("Enter number of days to add: ");
    scanf("%d", &days_to_add);
    if (!is_valid_date(date)){
        printf("Invalid date!\n");
        exit(1);
    }
    add_days(&date, days_to_add);
    print_date(date);
    printf("\n");
    return 0;
}