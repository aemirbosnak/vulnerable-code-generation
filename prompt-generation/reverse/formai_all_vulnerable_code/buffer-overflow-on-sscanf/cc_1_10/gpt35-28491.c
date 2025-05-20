//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: careful
#include <stdio.h>
#include <string.h>

// Function to check if a year is a leap year
int isLeapYear(int year){
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}

// Function to convert date from natural language to MM/DD/YYYY format
void convertDate(char* inputDate){
    char month[10], day[3], year[5];
    int monthNum, dayNum, yearNum;

    // Parse input date
    sscanf(inputDate, "%s %d, %d", month, &dayNum, &yearNum);

    // Get month number
    if(strcmp(month, "January") == 0){
        monthNum = 1;
    }else if(strcmp(month, "February") == 0){
        monthNum = 2;
    }else if(strcmp(month, "March") == 0){
        monthNum = 3;
    }else if(strcmp(month, "April") == 0){
        monthNum = 4;
    }else if(strcmp(month, "May") == 0){
        monthNum = 5;
    }else if(strcmp(month, "June") == 0){
        monthNum = 6;
    }else if(strcmp(month, "July") == 0){
        monthNum = 7;
    }else if(strcmp(month, "August") == 0){
        monthNum = 8;
    }else if(strcmp(month, "September") == 0){
        monthNum = 9;
    }else if(strcmp(month, "October") == 0){
        monthNum = 10;
    }else if(strcmp(month, "November") == 0){
        monthNum = 11;
    }else{
        monthNum = 12;
    }

    // Check if it's a leap year
    int isLeap = isLeapYear(yearNum);

    // Get number of days in month
    int daysInMonth;
    if(monthNum == 2){
        if(isLeap){
            daysInMonth = 29;
        }else{
            daysInMonth = 28;
        }
    }else if(monthNum == 4 || monthNum == 6 || monthNum == 9 || monthNum == 11){
        daysInMonth = 30;
    }else{
        daysInMonth = 31;
    }

    // Check if day number is valid
    if(dayNum < 1 || dayNum > daysInMonth){
        printf("Invalid day number in input date.\n");
        return;
    }

    // Format date string
    sprintf(day, "%02d", dayNum);
    sprintf(month, "%02d", monthNum);
    sprintf(year, "%04d", yearNum);

    char outputDate[11];
    sprintf(outputDate, "%s/%s/%s", month, day, year);

    // Print output date
    printf("%s", outputDate);
}

// Main function
int main(){
    char inputDate[20];
    printf("Enter a date in natural language (e.g. January 1, 2022): ");
    fgets(inputDate, 20, stdin);

    inputDate[strcspn(inputDate, "\n")] = 0; // Remove trailing newline

    convertDate(inputDate);

    return 0;
}