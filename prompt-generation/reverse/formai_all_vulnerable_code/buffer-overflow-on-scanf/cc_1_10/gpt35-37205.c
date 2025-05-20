//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert month from string to integer
int convert_month(char *month){
    int num_month;
    // Compare the given month string with all the month names
    if(strcmp(month,"January")==0){
        num_month=1;
    }
    else if(strcmp(month,"February")==0){
        num_month=2;
    }
    else if(strcmp(month,"March")==0){
        num_month=3;
    }
    else if(strcmp(month,"April")==0){
        num_month=4;
    }
    else if(strcmp(month,"May")==0){
        num_month=5;
    }
    else if(strcmp(month,"June")==0){
        num_month=6;
    }
    else if(strcmp(month,"July")==0){
        num_month=7;
    }
    else if(strcmp(month,"August")==0){
        num_month=8;
    }
    else if(strcmp(month,"September")==0){
        num_month=9;
    }
    else if(strcmp(month,"October")==0){
        num_month=10;
    }
    else if(strcmp(month,"November")==0){
        num_month=11;
    }
    else if(strcmp(month,"December")==0){
        num_month=12;
    }
    else{
        printf("Invalid month entered!\n");
        exit(1);        // Exit the program if invalid month entered
    }
    return num_month;
}

// Function to convert year from string to integer
int convert_year(char *year){
    int num_year=atoi(year);    // Convert year string into integer
    return num_year;
}

// Function to convert date from string to integer
int convert_date(char *date){
    int num_date=atoi(date);    // Convert date string into integer
    return num_date;
}

int main()
{
    // Declare variables to store date in string format
    char date_str[20], month_str[20], year_str[20];
    printf("Enter the date in natural language format (ex. 4th July, 1776): ");
    scanf("%s %s %s", date_str, month_str, year_str);    // Accept input from user

    // Convert month and year from string to integer format
    int month_int=convert_month(month_str);
    int year_int=convert_year(year_str);

    // Extract only the date from string and convert to integer
    char date_only[5];
    strncpy(date_only, date_str, 2);
    int date_int=convert_date(date_only);

    // Print the date in numerical format
    printf("\nThe date in numerical format is: %02d/%02d/%d\n", month_int, date_int, year_int);

    return 0;
}