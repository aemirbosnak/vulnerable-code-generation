//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check if a given year is a leap year
int isLeap(int year){
    if((year%4 == 0 && year%100 != 0) || year%400 == 0){
        return 1; // true
    }
    else{
        return 0; // false
    }
}

// function to get the number of days in a given month
int daysInMonth(int month, int year){
    int days;
    switch(month){
        case 1:
            days = 31;
            break;
        case 2:
            if(isLeap(year)){
                days = 29;
            }
            else{
                days = 28;
            }
            break;
        case 3:
            days = 31;
            break;
        case 4:
            days = 30;
            break;
        case 5:
            days = 31;
            break;
        case 6:
            days = 30;
            break;
        case 7:
            days = 31;
            break;
        case 8:
            days = 31;
            break;
        case 9:
            days = 30;
            break;
        case 10:
            days = 31;
            break;
        case 11:
            days = 30;
            break;
        case 12:
            days = 31;
            break;
        default:
            days = -1;
            break;
    }
    return days;
}

// function to convert a date in natural language to a date in standard format
void naturalToStandard(char *natural, char *standard){
    char month[10];
    int day, year;
    sscanf(natural, "%s %d, %d", month, &day, &year);
    int monthNum;
    if(strcmp(month, "January") == 0){
        monthNum = 1;
    }
    else if(strcmp(month, "February") == 0){
        monthNum = 2;
    }
    else if(strcmp(month, "March") == 0){
        monthNum = 3;
    }
    else if(strcmp(month, "April") == 0){
        monthNum = 4;
    }
    else if(strcmp(month, "May") == 0){
        monthNum = 5;
    }
    else if(strcmp(month, "June") == 0){
        monthNum = 6;
    }
    else if(strcmp(month, "July") == 0){
        monthNum = 7;
    }
    else if(strcmp(month, "August") == 0){
        monthNum = 8;
    }
    else if(strcmp(month, "September") == 0){
        monthNum = 9;
    }
    else if(strcmp(month, "October") == 0){
        monthNum = 10;
    }
    else if(strcmp(month, "November") == 0){
        monthNum = 11;
    }
    else{
        monthNum = 12;
    }
    sprintf(standard, "%02d/%02d/%04d", monthNum, day, year);
}

// function to convert a date in standard format to natural language
void standardToNatural(char *standard, char *natural){
    int month, day, year;
    sscanf(standard, "%d/%d/%d", &month, &day, &year);
    char monthName[10];
    switch(month){
        case 1:
            sprintf(monthName, "January");
            break;
        case 2:
            sprintf(monthName, "February");
            break;
        case 3:
            sprintf(monthName, "March");
            break;
        case 4:
            sprintf(monthName, "April");
            break;
        case 5:
            sprintf(monthName, "May");
            break;
        case 6:
            sprintf(monthName, "June");
            break;
        case 7:
            sprintf(monthName, "July");
            break;
        case 8:
            sprintf(monthName, "August");
            break;
        case 9:
            sprintf(monthName, "September");
            break;
        case 10:
            sprintf(monthName, "October");
            break;
        case 11:
            sprintf(monthName, "November");
            break;
        case 12:
            sprintf(monthName, "December");
            break;
        default:
            sprintf(monthName, "unknown");
            break;
    }
    sprintf(natural, "%s %d, %d", monthName, day, year);
}

int main(){
    char naturalDate[20], standardDate[20];
    int option;
    printf("1. Convert natural language date to standard format\n");
    printf("2. Convert standard format date to natural language\n");
    printf("Enter option: ");
    scanf("%d", &option);
    if(option == 1){
        printf("Enter natural language date (e.g. January 1, 2000): ");
        scanf(" %[^\n]", naturalDate);
        naturalToStandard(naturalDate, standardDate);
        printf("Standard format date: %s\n", standardDate);
    }
    else if(option == 2){
        printf("Enter standard format date (e.g. 01/01/2000): ");
        scanf(" %[^\n]", standardDate);
        standardToNatural(standardDate, naturalDate);
        printf("Natural language date: %s\n", naturalDate);
    }
    else{
        printf("Invalid option selected\n");
    }
    return 0;
}