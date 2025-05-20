//Code Llama-13B DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 100

int main() {
    char input[MAX_BUFFER_SIZE];
    char output[MAX_BUFFER_SIZE];
    char day_name[10];
    char month_name[10];
    int day;
    int month;
    int year;

    printf("Enter a date in the format 'dd/mm/yyyy': ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    sscanf(input, "%d/%d/%d", &day, &month, &year);

    switch (month) {
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
        default:
            strcpy(month_name, "Invalid month");
            break;
    }

    switch (day) {
        case 1:
            strcpy(day_name, "Sunday");
            break;
        case 2:
            strcpy(day_name, "Monday");
            break;
        case 3:
            strcpy(day_name, "Tuesday");
            break;
        case 4:
            strcpy(day_name, "Wednesday");
            break;
        case 5:
            strcpy(day_name, "Thursday");
            break;
        case 6:
            strcpy(day_name, "Friday");
            break;
        case 7:
            strcpy(day_name, "Saturday");
            break;
        default:
            strcpy(day_name, "Invalid day");
            break;
    }

    sprintf(output, "%s %d, %d", day_name, day, year);

    printf("%s\n", output);

    return 0;
}