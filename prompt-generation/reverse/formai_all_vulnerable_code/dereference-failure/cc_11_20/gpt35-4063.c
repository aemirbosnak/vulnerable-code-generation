//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check whether a year is a leap year or not
int isLeapYear(int year){
    if(year%400 == 0)
        return 1;
    if(year%100 == 0)
        return 0;
    if(year%4 == 0)
        return 1;
    return 0;
}

// Function to convert date from natural language to numeric format
void convertDate(char* date){
    char month[10], day[3], year[5], suffix[3], comma[2] = ",";
    int monthNum = 0, dayNum = 0, yearNum = 0;
    
    // Extracting month, day, year and suffix from input string
    sscanf(date, "%s %s %s %s",month, day, year, suffix);
    
    // Removing comma from month if it's present
    if(strcmp(&month[strlen(month)-1], comma) == 0)
        month[strlen(month)-1] = '\0';
   
    // Converting month from string to number
    if(strcmp(month, "January") == 0)
        monthNum = 1;
    else if(strcmp(month, "February") == 0)
        monthNum = 2;
    else if(strcmp(month, "March") == 0)
        monthNum = 3;
    else if(strcmp(month, "April") == 0)
        monthNum = 4;
    else if(strcmp(month, "May") == 0)
        monthNum = 5;
    else if(strcmp(month, "June") == 0)
        monthNum = 6;
    else if(strcmp(month, "July") == 0)
        monthNum = 7;
    else if(strcmp(month, "August") == 0)
        monthNum = 8;
    else if(strcmp(month, "September") == 0)
        monthNum = 9;
    else if(strcmp(month, "October") == 0)
        monthNum = 10;
    else if(strcmp(month, "November") == 0)
        monthNum = 11;
    else if(strcmp(month, "December") == 0)
        monthNum = 12;
    
    // Converting day from string to number
    dayNum = atoi(day);
    
    // Converting year from string to number
    yearNum = atoi(year);
    
    // Checking suffix and converting year accordingly
    if(strcmp(suffix, "BC") == 0)
        yearNum = -yearNum;
    
    // Adding 2000 to year if year is of 2 digits
    if(yearNum >= 0 && yearNum < 100)
        yearNum += 2000;
    
    // Adjusting date for February and leap year
    if(monthNum == 2){
        if(dayNum > 28){
            if(isLeapYear(yearNum) && dayNum == 29)
                dayNum = 29;
            else
                dayNum = 28;
        }
    }
    // Adjusting date for April, June, September, November
    else if(monthNum == 4 || monthNum == 6 || monthNum == 9 || monthNum == 11){
        if(dayNum > 30)
            dayNum = 30;
    }
    
    // Checking invalid dates
    if(monthNum < 1 || monthNum > 12 || dayNum < 1 || dayNum > 31 || (monthNum == 2 && dayNum > 29) || ((monthNum == 4 || monthNum == 6 || monthNum == 9 || monthNum == 11) && dayNum > 30)){
        printf("Invalid date.\n");
        return;
    }
    
    // Printing date in numeric format
    printf("%02d/%02d/%04d\n", monthNum, dayNum, yearNum);
}

int main(){
    char date[20];
    printf("Enter date in natural language (Example: October 21, 2022 AD): ");
    fgets(date, 20, stdin);
    convertDate(date);
    return 0;
}