//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: irregular
#include<stdio.h>
#include<string.h>

// function to calculate number of days in a month
int daysInMonth(int month, int year){

    int numDays;

    switch (month){
        case 1:
            numDays = 31;
            break;
        case 2:
            if(((year%100 == 0) && (year%400 == 0)) || ((year%100 != 0) && (year%4 == 0))){
                numDays = 29;
            }
            else{
                numDays = 28;
            }
            break;
        case 3:
            numDays = 31;
            break;
        case 4:
            numDays = 30;
            break;
        case 5:
            numDays = 31;
            break;
        case 6:
            numDays = 30;
            break;
        case 7:
            numDays = 31;
            break;
        case 8:
            numDays = 31;\
            break;
        case 9:
            numDays = 30;
            break;
        case 10:
            numDays = 31;
            break;
        case 11:
            numDays = 30;
            break;
        case 12:
            numDays = 31;
            break;
        default:
            printf("Invalid month input!\n");
            numDays = -1;
            break;
    }
    return numDays;
}

int main(){

    char inputDate[12];
    int month, day, year, daysInYear, daysInInputYear, dayCount;

    printf("Please enter date in format mm-dd-yyyy: ");
    fgets(inputDate, 12, stdin);
    inputDate[strcspn(inputDate, "\n")] = '\0'; // removing trailing newline character

    sscanf(inputDate, "%d-%d-%d", &month, &day, &year);

    // validating input
    if((month < 1) || (month > 12)){
        printf("Invalid month!\n");
        return 1;
    }
    if((day < 1) || (day > daysInMonth(month, year))){
        printf("Invalid day!\n");
        return 1;
    }
    if(year < 1){
        printf("Invalid year!\n");
        return 1;
    }

    // calculating number of days
    daysInYear = 365;
    daysInInputYear = daysInMonth(month, year) - day + 1;
    dayCount = daysInInputYear;
    month++;

    while(month <= 12){
        dayCount += daysInMonth(month, year);
        month++;
    }

    year++;
    while(year != 2022){
        if(year%4 == 0){
            daysInYear = 366;
        }
        else{
            daysInYear = 365;
        }
        dayCount += daysInYear;
        year++;
    }

    printf("The date %s is the %dth day of the year %d.\n", inputDate, dayCount, 2021);

    return 0;
}