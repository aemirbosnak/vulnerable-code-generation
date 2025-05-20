//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

struct date {
    int day;
    int month;
    int year;
};

void get_date(struct date *date) {
    char input[100];
    printf("Enter the date in the format DD/MM/YYYY: ");
    scanf("%s", input);
    if (sscanf(input, "%d/%d/%d", &date->day, &date->month, &date->year)!= 3) {
        printf("Invalid date format. Please enter the date in the format DD/MM/YYYY.\n");
        exit(1);
    }
}

void convert_date(struct date *date, char *output) {
    char month_name[20];
    switch (date->month) {
        case 1:
            strcpy(month_name, "January");
            break;
        case 2:
            strcpy(month_name, "February");
            break;
        case 3:
            strcpy(month_name, "March");
            break;
        case 4:
            strcpy(month_name, "April");
            break;
        case 5:
            strcpy(month_name, "May");
            break;
        case 6:
            strcpy(month_name, "June");
            break;
        case 7:
            strcpy(month_name, "July");
            break;
        case 8:
            strcpy(month_name, "August");
            break;
        case 9:
            strcpy(month_name, "September");
            break;
        case 10:
            strcpy(month_name, "October");
            break;
        case 11:
            strcpy(month_name, "November");
            break;
        case 12:
            strcpy(month_name, "December");
            break;
    }
    sprintf(output, "Today is %s %d, %d.", month_name, date->day, date->year);
}

int main() {
    struct date date;
    char output[100];
    get_date(&date);
    convert_date(&date, output);
    printf("%s\n", output);
    return 0;
}