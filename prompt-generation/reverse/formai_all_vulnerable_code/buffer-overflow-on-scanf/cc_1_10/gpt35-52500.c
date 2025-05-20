//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: genious
//Genius-style C Natural Language Date Converter

#include <stdio.h>
#include <string.h>

//Function to get the month code
int getMonthCode(char month[]){
    if(strcmp(month, "January") == 0)
        return 6;
    else if(strcmp(month, "February") == 0)
        return 2;
    else if(strcmp(month, "March") == 0)
        return 2;
    else if(strcmp(month, "April") == 0)
        return 5;
    else if(strcmp(month, "May") == 0)
        return 0;
    else if(strcmp(month, "June") == 0)
        return 3;
    else if(strcmp(month, "July") == 0)
        return 5;
    else if(strcmp(month, "August") == 0)
        return 1;
    else if(strcmp(month, "September") == 0)
        return 4;
    else if(strcmp(month, "October") == 0)
        return 6;
    else if(strcmp(month, "November") == 0)
        return 2;
    else if(strcmp(month, "December") == 0)
        return 4;
    else
        return -1; //Invalid month input
}

//Function to check if it's a leap year
int isLeapYear(int year){
    if((year%4 == 0 && year%100 != 0) || year%400 == 0)
        return 1; //Leap year
    else
        return 0; //Not a leap year
}

//Function to get the century code
int getCenturyCode(int year){
    int century = year/100;
    if(century == 16)
        return 6;
    else if(century == 17)
        return 4;
    else if(century == 18)
        return 2;
    else if(century == 19)
        return 0;
    else if(century == 20)
        return 6;
    else if(century == 21)
        return 4;
    else
        return -1; //Invalid year input
}

//Function to convert date to day of the week
char* dateToDay(int day, char month[], int year){
    int monthCode = getMonthCode(month);
    int centuryCode = getCenturyCode(year);
    int yearCode = year % 100;

    if(monthCode == -1 || centuryCode == -1){
        return "Invalid input";
    }

    int leapYearCorrection = (isLeapYear(year) && (strcmp(month, "January") == 0 || strcmp(month, "February") == 0)) ? -1 : 0;
    int dayOfWeek = (day + monthCode + yearCode + (yearCode/4) + centuryCode + leapYearCorrection) % 7;

    switch(dayOfWeek){
        case 0:
            return "Saturday";
            break;
        case 1:
            return "Sunday";
            break;
        case 2:
            return "Monday";
            break;
        case 3:
            return "Tuesday";
            break;
        case 4:
            return "Wednesday";
            break;
        case 5:
            return "Thursday";
            break;
        case 6:
            return "Friday";
            break;
        default:
            return "Invalid input";
            break;
    }
}

int main(){
    int day, year;
    char month[10];

    printf("Enter date in natural language (E.g. 1st August 2021): ");
    scanf("%d %s %d", &day, month, &year);

    char* dayOfWeek = dateToDay(day, month, year);

    printf("The date %d %s %d was on a %s.\n", day, month, year, dayOfWeek);

    return 0;
}