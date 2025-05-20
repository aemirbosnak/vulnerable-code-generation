//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef enum {
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
} Month;

void convert_date_to_string(Date date, char* string) {
    switch(date.month) {
        case JANUARY:
            strcpy(string, "January");
            break;
        case FEBRUARY:
            strcpy(string, "February");
            break;
        case MARCH:
            strcpy(string, "March");
            break;
        case APRIL:
            strcpy(string, "April");
            break;
        case MAY:
            strcpy(string, "May");
            break;
        case JUNE:
            strcpy(string, "June");
            break;
        case JULY:
            strcpy(string, "July");
            break;
        case AUGUST:
            strcpy(string, "August");
            break;
        case SEPTEMBER:
            strcpy(string, "September");
            break;
        case OCTOBER:
            strcpy(string, "October");
            break;
        case NOVEMBER:
            strcpy(string, "November");
            break;
        case DECEMBER:
            strcpy(string, "December");
            break;
    }
    sprintf(string + strlen(string), " %d, %d", date.day, date.year);
}

int main() {
    Date date;
    char input_date[MAX_STRING_LENGTH];
    char output_date[MAX_STRING_LENGTH];

    printf("Enter a date in the format of 'MM/DD/YYYY': ");
    scanf("%s", input_date);

    date.day = atoi(input_date + 8);
    date.month = atoi(input_date + 5) - 1;
    date.year = atoi(input_date + 2) + 2000;

    convert_date_to_string(date, output_date);

    printf("The date '%s' is '%s'.\n", input_date, output_date);

    return 0;
}