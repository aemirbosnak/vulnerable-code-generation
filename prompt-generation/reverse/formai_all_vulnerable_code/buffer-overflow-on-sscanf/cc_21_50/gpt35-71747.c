//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: energetic
#include <stdio.h>
#include <string.h>

int main()
{
    char date[15], output[30];
    int day, month, year;
    
    printf("Enter Date in Natural Language (E.g. December 25th, 2022): ");
    fgets(date, sizeof(date), stdin);
    
    // Extracting day, month and year from the user input
    sscanf(date, "%d %s %d", &month, output, &year);
    day = atoi(output);
    
    // Checking for the month and corresponding number of days
    if(strcmp("January", output) == 0) 
        month = 1;
    else if(strcmp("February", output) == 0) 
        month = 2;
    else if(strcmp("March", output) == 0) 
        month = 3;
    else if(strcmp("April", output) == 0) 
        month = 4;
    else if(strcmp("May", output) == 0) 
        month = 5;
    else if(strcmp("June", output) == 0) 
        month = 6;
    else if(strcmp("July", output) == 0) 
        month = 7;
    else if(strcmp("August", output) == 0) 
        month = 8;
    else if(strcmp("September", output) == 0) 
        month = 9;
    else if(strcmp("October", output) == 0) 
        month = 10;
    else if(strcmp("November", output) == 0) 
        month = 11;
    else if(strcmp("December", output) == 0) 
        month = 12;
    
    // Checking if the year entered is leap year or not
    int leap = 0;
    if(year % 400 == 0)
        leap = 1;
    else if(year % 100 == 0)
        leap = 0;
    else if(year % 4 == 0) 
        leap = 1;
    
    // Checking for the number of days in the month
    int days_in_month;
    if(month == 2)
    {
        if(leap == 1)
            days_in_month = 29;
        else
            days_in_month = 28;
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        days_in_month = 30;
    }
    else
    {
        days_in_month = 31;
    }
    
    // Validating the day entered
    if(day<1 || day>days_in_month)
    {
        printf("Invalid Day\n");
        return 0;
    }
    
    // Printing the output in the desired format
    printf("The Date in Numerical Format is: %02d/%02d/%d\n", month, day, year);
    
    return 0;
}