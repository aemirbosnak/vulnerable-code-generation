//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to check leap year
int isLeap(int year){
    if(year%4 == 0){
        if(year%100 == 0){
            if(year%400 == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}

//Function to convert month name to month number
int monthConvert(char* month){
    if(strcmp(month, "January") == 0){
        return 1;
    }
    else if(strcmp(month, "February") == 0){
        return 2;
    }
    else if(strcmp(month, "March") == 0){
        return 3;
    }
    else if(strcmp(month, "April") == 0){
        return 4;
    }
    else if(strcmp(month, "May") == 0){
        return 5;
    }
    else if(strcmp(month, "June") == 0){
        return 6;
    }
    else if(strcmp(month, "July") == 0){
        return 7;
    }
    else if(strcmp(month, "August") == 0){
        return 8;
    }
    else if(strcmp(month, "September") == 0){
        return 9;
    }
    else if(strcmp(month, "October") == 0){
        return 10;
    }
    else if(strcmp(month, "November") == 0){
        return 11;
    }
    else if(strcmp(month, "December") == 0){
        return 12;
    }
}

//Function to calculate number of days in a given month
int daysInMonth(int month, int year){
    if(month == 2){
        if(isLeap(year)){
            return 29;
        }
        else{
            return 28;
        }
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11){
        return 30;
    }
    else{
        return 31;
    }
}

//Main function
int main(){
    char input[100];
    char day[3], month[10], year[5];
    int int_day, int_month, int_year, days_in_month, total_days, i;

    //Take user input
    printf("Enter date in natural language format (E.g. Fifteenth January Two thousand twenty): ");
    fgets(input, 100, stdin);

    //Tokenize the input string
    char *token = strtok(input, " ");
    i=0;
    while(token != NULL){
        if(i == 0){
            //Convert first token (day) to integer
            strncpy(day, token, 2);
            int_day = atoi(day);
        }
        else if(i == 1){
            //Convert second token (month) to integer
            strcpy(month, token);
            int_month = monthConvert(month);
        }
        else if(i == 2){
            //Convert third token (year) to integer
            strncpy(year, token, 4);
            int_year = atoi(year);
        }
        i++;
        token = strtok(NULL, " ");
    }

    //Calculate number of days in given month
    days_in_month = daysInMonth(int_month, int_year);

    //Calculate total number of days
    total_days = int_day;
    for(i=1; i<int_month; i++){
        total_days += daysInMonth(i, int_year);
    }

    //Output result
    printf("\nDate in numerical format (DD/MM/YYYY): %d/%d/%d\n", int_day, int_month, int_year);
    printf("Total days in %s %d: %d\n", month, int_year, days_in_month);
    printf("Total days passed in %d: %d\n", int_year, total_days);

    return 0;
}