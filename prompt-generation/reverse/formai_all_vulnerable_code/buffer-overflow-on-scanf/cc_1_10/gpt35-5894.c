//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: real-life
#include <stdio.h>
#include <string.h>

// function to convert month abbreviation to month number
int monthConverter(char month[4]){
    if(strcmp(month, "Jan") == 0){
        return 1;
    }
    else if(strcmp(month, "Feb") == 0){
        return 2;
    }
    else if(strcmp(month, "Mar") == 0){
        return 3;
    }
    else if(strcmp(month, "Apr") == 0){
        return 4;
    }
    else if(strcmp(month, "May") == 0){
        return 5;
    }
    else if(strcmp(month, "Jun") == 0){
        return 6;
    }
    else if(strcmp(month, "Jul") == 0){
        return 7;
    }
    else if(strcmp(month, "Aug") == 0){
        return 8;
    }
    else if(strcmp(month, "Sep") == 0){
        return 9;
    }
    else if(strcmp(month, "Oct") == 0){
        return 10;
    }
    else if(strcmp(month, "Nov") == 0){
        return 11;
    }
    else if(strcmp(month, "Dec") == 0){
        return 12;
    }
    else{
        printf("Invalid month abbreviation\n");
        return -1;
    }
}

// function to convert date into number of days
int convertToDays(int day, int month, int year){
    int daysInMonth;
    int daysInYear = 0;
    int i;

    // finding number of days in the month
    if(month == 2){
        if(year % 4 == 0){
            daysInMonth = 29;
        }
        else{
            daysInMonth = 28;
        }
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11){
        daysInMonth = 30;
    }
    else{
        daysInMonth = 31;
    }

    // finding number of days in the year
    for(i = 1; i < month; i++){
        if(i == 2){
            if(year % 4 == 0){
                daysInYear += 29;
            }
            else{
                daysInYear += 28;
            }
        }
        else if(i == 4 || i == 6 || i == 9 || i == 11){
            daysInYear += 30;
        }
        else{
            daysInYear += 31;
        }
    }

    // adding number of days in the month and the day inputted
    daysInYear += day;

    return daysInYear;
}

int main(){

    char input[20];
    char month[4];
    int day, year, m, n;

    printf("Enter date in the format 'dd mmm yyyy':\n");
    scanf("%d %s %d", &day, month, &year);

    // converting month abbreviation to month number
    n = monthConverter(month);

    // converting date into number of days
    m = convertToDays(day, n, year);

    printf("The date inputted is day number %d in the year %d\n", m, year);

    return 0;
}