//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: scalable
#include<stdio.h>
#include<string.h>

//function to calculate leap year
int isLeap(int year){
    if((year%400==0)||(year%4==0)&& (year%100!=0)){
        return 1; //leap year
    }
    else {
        return 0; //not a leap year
    }
}

//function to find days in a month
int daysInMonth(int month, int year){
    int days;
    switch(month){
        case 1: //January
        case 3: //March
        case 5: //May
        case 7: //July
        case 8: //August
        case 10: //October
        case 12: //December
            days = 31;
            break;
        case 4: //April
        case 6: //June
        case 9: //September
        case 11: //November
            days = 30;
            break;
        case 2: //February
            if(isLeap(year)==1){
                days = 29;
            }
            else{
                days = 28;
            }
            break;
    }
    return days;
}

int main(){
    int day, month, year, totalDays; //input variables
    int i;
    char monthName[12][10]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    //prompt user to enter the date and year
    printf("Enter date in format dd mm yyyy: \n");
    scanf("%d%d%d", &day, &month, &year);

    //calculate total number of days
    totalDays = 0;
    for(i=1; i<year; i++){
        if(isLeap(i)==1){
            totalDays += 366;
        }
        else{
            totalDays += 365;
        }
    }

    //calculate days for the current year
    for(i=1; i<month; i++){
        totalDays += daysInMonth(i, year);
    }
    totalDays += day;

    //print the output
    printf("The date is %s %d, %d. It is the %dth day of the year.", monthName[month-1], day, year, totalDays);

    return 0;
}