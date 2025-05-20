//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

//helper function to find leap year
int isLeapYear(int year){
    if((year%4==0 && year%100!=0) || year%400==0){
        return 1;
    }
    return 0;
}

//helper function to convert month number to string
char* monthToString(int month){
    switch(month){
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
    }
}

//main function to convert date
void convertDate(){
    int day, month, year, daysInMonth;
    printf("Enter date in C natural language (e.g. March 14, 2022): ");
    scanf("%s %d, %d", monthToString(&month), &day, &year);
    daysInMonth = 31;
    //check for months with less than or more than 31 days
    if(month == 2){
        daysInMonth = 28 + isLeapYear(year);
    }else if(month == 4 || month == 6 || month == 9 || month == 11){
        daysInMonth = 30;
    }
    //check for invalid dates
    if(day > daysInMonth || day < 1){
        printf("Invalid date entered.");
        return;
    }
    //output formatted date
    printf("%s %d, %d\n", monthToString(month), day, year);
}

//test main function
int main(){
    convertDate();
    return 0;
}