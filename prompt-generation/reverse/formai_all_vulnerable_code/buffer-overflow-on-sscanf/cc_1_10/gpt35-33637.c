//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: cheerful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void convert_date(char date[]);

int main() {
    char date[11];
    printf("Welcome to the Cheerful Date Converter!\n");
    printf("Please enter a date in the format 'MM/DD/YYYY': ");
    fgets(date, 11, stdin);
    convert_date(date);
    return 0;
}

void convert_date(char date[]) {
    int month, day, year;
    char month_name[12];
    sscanf(date, "%d/%d/%d", &month, &day, &year);
    switch(month) {
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
            printf("Invalid month!\n");
            exit(0);
    }
    printf("\nThanks for being so cheerful and entering: %s/%d/%d \n", month_name, day, year);
    printf("Here is your date in a completely different format:\n");
    printf("%s %d, %d\n", month_name, day, year);
    printf("Have a cheerful day!");
}