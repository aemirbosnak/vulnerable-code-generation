//Code Llama-13B DATASET v1.0 Category: Natural Language Date Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main(void) {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int length;

    printf("Enter a date in the format 'YYYY-MM-DD': ");
    fgets(input, MAX_LENGTH, stdin);
    length = strlen(input);
    input[length - 1] = '\0';

    if (length != 10) {
        printf("Invalid date format.\n");
        return 1;
    }

    char year[5];
    char month[3];
    char day[3];
    sscanf(input, "%4s-%2s-%2s", year, month, day);

    int year_int = atoi(year);
    int month_int = atoi(month);
    int day_int = atoi(day);

    if (month_int > 12 || month_int < 1) {
        printf("Invalid month value.\n");
        return 1;
    }

    if (day_int > 31 || day_int < 1) {
        printf("Invalid day value.\n");
        return 1;
    }

    char *month_name = NULL;
    switch (month_int) {
        case 1:
            month_name = "January";
            break;
        case 2:
            month_name = "February";
            break;
        case 3:
            month_name = "March";
            break;
        case 4:
            month_name = "April";
            break;
        case 5:
            month_name = "May";
            break;
        case 6:
            month_name = "June";
            break;
        case 7:
            month_name = "July";
            break;
        case 8:
            month_name = "August";
            break;
        case 9:
            month_name = "September";
            break;
        case 10:
            month_name = "October";
            break;
        case 11:
            month_name = "November";
            break;
        case 12:
            month_name = "December";
            break;
        default:
            printf("Invalid month value.\n");
            return 1;
    }

    sprintf(output, "%s %d, %d", month_name, day_int, year_int);

    printf("The date in words is: %s\n", output);

    return 0;
}