//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert month string to number */
int monthToNumber(char *month){
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for(int i=0; i<12; i++){
        if(strcmp(month, months[i]) == 0){
            return i+1;
        }
    }
    return -1;
}

/* Function to convert date string to number */
int dateToNumber(char *date){
    int number = 0;
    for(int i=0; i<strlen(date); i++){
        if(date[i] >= '0' && date[i] <= '9'){
            number = number * 10 + (date[i] - '0');
        }
    }
    return number;
}

/* Main function */
int main(){
    char date[20], month[10], year[5];
    int day, monthNum, yearNum;
    
    /* Get input from user */
    printf("Enter a date (dd mmm yyyy format): ");
    scanf("%s %s %s", date, month, year);
    
    /* Convert month string to number */
    monthNum = monthToNumber(month);
    if(monthNum == -1){
        printf("Invalid month\n");
        exit(0);
    }
    
    /* Convert date string to number */
    day = dateToNumber(date);
    
    /* Convert year string to number */
    yearNum = atoi(year);
    
    /* Check for leap year */
    int isLeap = 0;
    if (yearNum % 4 == 0) {
        if (yearNum % 100 == 0) {
            if (yearNum % 400 == 0)
                isLeap = 1;
            else
                isLeap = 0;
        }
        else
            isLeap = 1;
    }
    else
        isLeap = 0;
    
    /* Calculate number of days */
    int daysInMonth[] = {31, (isLeap ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDays = 0;
    for(int i=0; i<monthNum-1; i++){
        totalDays += daysInMonth[i];
    }
    totalDays += day;
    
    /* Print output */
    printf("The date %s %s %s is day number %d of the year %s\n", date, month, year, totalDays, year);
    
    return 0;
}