//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* get_month_string(int month){
    char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[month-1];
}

bool is_leap_year(int year){
    if(year % 400 == 0)
        return true;
    else if(year % 100 == 0)
        return false;
    else if(year % 4 == 0)
        return true;
    else
        return false;
}

int get_days_in_month(int month, int year){
    int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (is_leap_year(year) && month == 2)
        return 29;
    return days_in_month[month-1];
}

bool valid_date(int day, int month, int year) {
    if (year < 0 || month < 1 || month > 12)
        return false;
    int days_in_month = get_days_in_month(month, year);
    if (!(day > 0 && day <= days_in_month))
        return false;
    return true;
}

void convert_date(char* date){
    int day, month, year;
    sscanf(date,"%d/%d/%d", &day, &month, &year);
    if (!valid_date(day, month, year)) {
        printf("Invalid Date!\n");
        return;
    }
    char* month_string = get_month_string(month);
    printf("%s %d, %d\n", month_string, day, year);
}

int main(){
    char date1[] = "5/25/2021";
    char date2[] = "02/29/2020";
    char date3[] = "13/13/2022";
    char date4[] = "0/0/0";
    printf("Converted Date: ");
    convert_date(date1);
    printf("Converted Date: ");
    convert_date(date2);
    printf("Converted Date: ");
    convert_date(date3);
    printf("Converted Date: ");
    convert_date(date4);
    return 0;
}