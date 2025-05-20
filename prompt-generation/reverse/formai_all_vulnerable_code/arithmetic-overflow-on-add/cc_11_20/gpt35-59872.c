//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include <stdio.h>
#include <ctype.h>

int daysInMonth(int month, int year){
    int days;
    if (month == 2){
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
            days = 29;
        }else{
            days = 28;
        }
    }else if (month == 4 || month == 6 || month == 9 || month == 11){
        days = 30;
    }else{
        days = 31;
    }
    return days;
}

int main(){
    char inputDate[15];
    printf("Please enter a date in natural language (e.g. \"January 1, 2022\"): ");
    fgets(inputDate, 15, stdin);

    // Extracting values from input
    int year, month, day;
    char monthStr[10];
    sscanf(inputDate, "%s %d, %d", monthStr, &day, &year);

    // Converting month string to number
    for (int i = 0; monthStr[i]; i++){
        monthStr[i] = tolower(monthStr[i]);
    }
    if (strcmp(monthStr, "january") == 0){
        month = 1;
    }else if (strcmp(monthStr, "february") == 0){
        month = 2;
    }else if (strcmp(monthStr, "march") == 0){
        month = 3;
    }else if (strcmp(monthStr, "april") == 0){
        month = 4;
    }else if (strcmp(monthStr, "may") == 0){
        month = 5;
    }else if (strcmp(monthStr, "june") == 0){
        month = 6;
    }else if (strcmp(monthStr, "july") == 0){
        month = 7;
    }else if (strcmp(monthStr, "august") == 0){
        month = 8;
    }else if (strcmp(monthStr, "september") == 0){
        month = 9;
    }else if (strcmp(monthStr, "october") == 0){
        month = 10;
    }else if (strcmp(monthStr, "november") == 0){
        month = 11;
    }else if (strcmp(monthStr, "december") == 0){
        month = 12;
    }else{
        printf("Invalid date format. Please enter a date in natural language (e.g. \"January 1, 2022\"): ");
        fgets(inputDate, 15, stdin);
    }

    // Calculating number of days
    int days = day;
    for (int i = 1; i < month; i++){
        days += daysInMonth(i, year);
    }
    printf("The date in number of days since January 1, %d is: %d\n", year, days);

    return 0;
}