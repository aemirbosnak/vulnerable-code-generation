//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: scientific
#include<stdio.h>
#include<string.h>

//Function to remove spaces from a given string
void removeSpaces(char *str) 
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
           str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
}

//Function to get the month number from the month name
int getMonthNumber(char *month){
    if(strcmp(month, "January") == 0){
        return 1;
    }
    if(strcmp(month, "February") == 0){
        return 2;
    }
    if(strcmp(month, "March") == 0){
        return 3;
    }
    if(strcmp(month, "April") == 0){
        return 4;
    }
    if(strcmp(month, "May") == 0){
        return 5;
    }
    if(strcmp(month, "June") == 0){
        return 6;
    }
    if(strcmp(month, "July") == 0){
        return 7;
    }
    if(strcmp(month, "August") == 0){
        return 8;
    }
    if(strcmp(month, "September") == 0){
        return 9;
    }
    if(strcmp(month, "October") == 0){
        return 10;
    }
    if(strcmp(month, "November") == 0){
        return 11;
    }
    if(strcmp(month, "December") == 0){
        return 12;
    }
}

//Main function
int main(){
    //Take user input
    char date[50];
    printf("Enter date in natural language (e.g. 15th June, 2021): ");
    fgets(date, 50, stdin);
    removeSpaces(date);

    //Extract day, month and year from input
    char day[3], month[10], year[5];
    sscanf(date, "%2s%10s%4s", day, month, year);
    
    //Convert month name to month number
    int monthNumber = getMonthNumber(month);

    //Print output
    printf("Date in numerical format: %s-%02d-%s", year, monthNumber, day);
    return 0;
}