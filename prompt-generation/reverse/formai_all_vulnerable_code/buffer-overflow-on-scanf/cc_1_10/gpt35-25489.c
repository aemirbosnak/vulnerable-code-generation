//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

//Function to check if year is leap year or not
int isLeapYear(int year){
    if((year%4==0 && year%100!=0) || year%400==0){
        return 1;
    }
    return 0;
}

//Function to get the total number of days till that month using an array
int daysInMonth(int month, int year){
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(month==2 && isLeapYear(year)){
        return 29;
    }
    return days[month-1];
}

//Function to convert date into number of days from year 1 AD
int daysFromYear1AD(int day, int month, int year){
    int days=0,i;
    for(i=1;i<year;i++){
        days+=isLeapYear(i) ? 366 : 365;
    }
    for(i=1;i<month;i++){
        days+=daysInMonth(i,year);
    }
    days+=day;
    return days;
}

//Function to convert number of days into date
void getDayMonthYearFromDays(int *day, int *month, int *year, int days){
    int i;
    for(i=1;;i++){
        int daysInCurrentYear=isLeapYear(i) ? 366 : 365;
        if(days<=daysInCurrentYear){
            *year=i;
            break;
        }
        days-=daysInCurrentYear;
    }
    for(i=1;;i++){
        int daysInCurrentMonth=daysInMonth(i,*year);
        if(days<=daysInCurrentMonth){
            *month=i;
            break;
        }
        days-=daysInCurrentMonth;
    }
    *day=days;
}

int main(){
    int day,month,year;
    printf("Enter date in the format of dd-mm-yyyy: ");
    scanf("%d-%d-%d",&day,&month,&year);
    int totalDays=daysFromYear1AD(day,month,year);
    printf("Total number of days from year 1 AD: %d\n",totalDays);
    getDayMonthYearFromDays(&day,&month,&year,totalDays);
    printf("Date in the format of dd-mm-yyyy: %d-%d-%d\n",day,month,year);
    return 0;
}