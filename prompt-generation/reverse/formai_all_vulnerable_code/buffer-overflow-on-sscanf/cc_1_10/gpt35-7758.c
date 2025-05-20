//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dayOfYear(char* date);
void convertToNatural(char* date, char* naturalDate);

int main(){
    // Sample input date in yyyy-mm-dd format
    char date[] = "2022-07-15";
    char naturalDate[100];

    printf("Date in yyyy-mm-dd format: %s\n", date);

    int doy = dayOfYear(date);
    convertToNatural(date, naturalDate);

    printf("Day of year: %d\n", doy);
    printf("Natural language date: %s\n", naturalDate);

    return 0;
}

// Function to calculate the day of year
int dayOfYear(char* date){
    int year, month, day;
    sscanf(date, "%d-%d-%d", &year, &month, &day);

    // Number of days in each month
    int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    // Adjust for leap year
    if((year%4==0 && year%100!=0) || year%400==0){
        daysInMonth[2] = 29;
    }

    int doy = 0;

    for(int i=1;i<month;i++){
        doy += daysInMonth[i];
    }

    doy += day;

    return doy;
}

// Function to convert date format to natural language
void convertToNatural(char* date, char* naturalDate){
    char year[5];
    char month[3];
    char day[3];

    // Separate year, month and day
    strncpy(year, date, 4);
    strncpy(month, date+5, 2);
    strncpy(day, date+8, 2);

    // Null terminate the char arrays
    year[4] = '\0';
    month[2] = '\0';
    day[2] = '\0';

    int m = atoi(month);

    // List of months in natural language
    char months[13][20] = {"", "January", "February", "March", 
                        "April", "May", "June", "July", 
                        "August", "September", "October", 
                        "November", "December"};

    sprintf(naturalDate, "%s %d, %s", months[m], atoi(day), year);
}