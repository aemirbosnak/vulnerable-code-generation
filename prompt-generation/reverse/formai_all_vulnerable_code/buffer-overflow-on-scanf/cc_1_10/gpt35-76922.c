//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Alan Touring
#include <stdio.h>
#include <stdbool.h>

bool isLeapYear(int year){
    if(year % 400 == 0){
        return true;
    } else if(year % 100 == 0){
        return false;
    } else if(year % 4 == 0){
        return true;
    } else {
        return false;
    }
}

int getDaysInMonth(int month, int year){
    if(month == 2){
        if(isLeapYear(year)){
            return 29;
        } else {
            return 28;
        }
    } else if(month == 4 || month == 6 || month == 9 || month == 11){
        return 30;
    } else {
        return 31;
    }
}

void convertDate(int day, int month, int year){
    int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; // storing daysInMonth in index position array
    
    if(isLeapYear(year)){
        daysInMonth[2] = 29;
    }

    int days = day - 1;

    for(int i=1; i<month; i++){
        days += daysInMonth[i];
    }

    for(int i=1; i<=12; i++){
        if(days<=daysInMonth[i]){
            printf("The converted date is: %d/%d/%d\n",days,i,year);
            break;
        } else{
            days -= daysInMonth[i];
        }
    }
}

int main(){
    int day, month, year;
    printf("Enter the day in numerical format (DD): ");
    scanf("%d", &day);

    printf("Enter the month in numerical format (MM): ");
    scanf("%d", &month);

    printf("Enter the year in numerical format (YYYY): ");
    scanf("%d", &year);

    convertDate(day, month, year);

    return 0;
}