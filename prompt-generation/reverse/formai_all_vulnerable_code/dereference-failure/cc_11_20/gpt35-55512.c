//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: genious
#include<stdio.h>
#include<string.h>

/*
    Author: Genius Bot
    Date: 13th August, 2021
    Description: A unique C Natural Language Date Converter program
*/

int main(){
    // Variables to store date components
    int day = 0;
    int month = 0;
    int year = 0;

    // User input for the date
    printf("Enter a date in natural language format (e.g. 13th August 2021): ");
    char date_input[50];
    fgets(date_input, 50, stdin);

    // Output formatting for the input
    printf("\n You entered %s", date_input);

    // Extracting day, month and year from input
    char *day_string = strtok(date_input, " ");
    day = atoi(day_string);

    char *month_string = strtok(NULL, " ");
    if(strcmp(month_string, "January") == 0){
        month = 1;
    } else if(strcmp(month_string, "February") == 0){
        month = 2;
    } else if(strcmp(month_string, "March") == 0){
        month = 3;
    } else if(strcmp(month_string, "April") == 0){
        month = 4;
    } else if(strcmp(month_string, "May") == 0){
        month = 5;
    } else if(strcmp(month_string, "June") == 0){
        month = 6;
    } else if(strcmp(month_string, "July") == 0){
        month = 7;
    } else if(strcmp(month_string, "August") == 0){
        month = 8;
    } else if(strcmp(month_string, "September") == 0){
        month = 9;
    } else if(strcmp(month_string, "October") == 0){
        month = 10;
    } else if(strcmp(month_string, "November") == 0){
        month = 11;
    } else if(strcmp(month_string, "December") == 0){
        month = 12;
    }

    char *year_string = strtok(NULL, " \n");
    year = atoi(year_string);

    // Output formatting for the extracted date
    printf("\n\n Extracted date: %d/%d/%d \n", month, day, year);

    // Output formatting for the final date
    printf("\n The date you entered in standard date format is: %d/%d/%d \n\n", day, month, year);

    return 0;
}