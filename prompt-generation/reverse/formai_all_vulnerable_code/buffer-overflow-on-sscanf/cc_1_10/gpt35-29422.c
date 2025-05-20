//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: inquisitive
#include<stdio.h>
#include<string.h>
#define MAX_LINE_LEN 80

int convert_date(char date[MAX_LINE_LEN]);
void print_month(int month);

int main()
{
    char date[MAX_LINE_LEN];
    printf("Enter a date in natural language (e.g. December 1st, 2022): \n");
    fgets(date, MAX_LINE_LEN, stdin);
    int converted_date = convert_date(date);
    printf("Your input date in numerical format is: %d\n", converted_date);
    return 0;
}

int convert_date(char date[MAX_LINE_LEN])
{
    int year, month, day;
    char month_str[MAX_LINE_LEN];
    sscanf(date, "%s %d, %d", month_str, &day, &year);
    if (strcmp(month_str, "January") == 0) {
        month = 1;
    } else if (strcmp(month_str, "February") == 0) {
        month = 2;
    } else if (strcmp(month_str, "March") == 0) {
        month = 3;
    } else if (strcmp(month_str, "April") == 0) {
        month = 4;
    } else if (strcmp(month_str, "May") == 0) {
        month = 5;
    } else if (strcmp(month_str, "June") == 0) {
        month = 6;
    } else if (strcmp(month_str, "July") == 0) {
        month = 7;
    } else if (strcmp(month_str, "August") == 0) {
        month = 8;
    } else if (strcmp(month_str, "September") == 0) {
        month = 9;
    } else if (strcmp(month_str, "October") == 0) {
        month = 10;
    } else if (strcmp(month_str, "November") == 0) {
        month = 11;
    } else if (strcmp(month_str, "December") == 0) {
        month = 12;
    } else {
        printf("Invalid month input.\n");
        exit(1);
    }
    return year * 10000 + month * 100 + day;
}

void print_month(int month)
{
    if (month == 1) {
        printf("January");
    } else if (month == 2) {
        printf("February");
    } else if (month == 3) {
        printf("March");
    } else if (month == 4) {
        printf("April");
    } else if (month == 5) {
        printf("May");
    } else if (month == 6) {
        printf("June");
    } else if (month == 7) {
        printf("July");
    } else if (month == 8) {
        printf("August");
    } else if (month == 9) {
        printf("September");
    } else if (month == 10) {
        printf("October");
    } else if (month == 11) {
        printf("November");
    } else {
        printf("December");
    }
}