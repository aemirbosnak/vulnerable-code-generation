//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* month_name(int month){
    static char *month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return month_names[month];
}

int is_leap_year(int year){
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

int get_days_in_month(int month, int year){
    if (month == 2 && is_leap_year(year)) {
        return 29;
    } else if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

struct tm* convert_date(int day, int month, int year){
    struct tm *date = malloc(sizeof(struct tm));
    date->tm_year = year - 1900;
    date->tm_mon = month - 1;
    date->tm_mday = day;
    return date;
}

char* convert_to_string(struct tm* date){
    static char buffer[80];
    strftime(buffer, 80, "%A, %B %d, %Y", date);
    return buffer;
}

int main(){
    int day, month, year;
    printf("Enter a date in the format of DD/MM/YYYY: ");
    scanf("%d/%d/%d", &day, &month, &year);
    struct tm* date = convert_date(day, month, year);
    char* formatted_date = convert_to_string(date);
    printf("The date is: %s\n", formatted_date);
    free(date);
    return 0;
}