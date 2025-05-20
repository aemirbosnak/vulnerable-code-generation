//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check leap year
bool isLeap(int year)
{
    if (year % 4 != 0)
        return false;
    else if (year % 100 != 0)
        return true;
    else if (year % 400 != 0)
        return false;
    else
        return true;
}

// Function to convert month number to month name
char* monthName(int month)
{
    switch(month)
    {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "Invalid month";
    }
}

// Function to convert natural language date to C date
void convertDate(char* date)
{
    int day, month, year;
    char monthName[10];
    sscanf(date, "%d %s %d", &day, monthName, &year);

    // Convert month name to month number
    if(strcmp(monthName, "January")==0)
        month = 1;
    else if(strcmp(monthName, "February")==0)
        month = 2;
    else if(strcmp(monthName, "March")==0)
        month = 3;
    else if(strcmp(monthName, "April")==0)
        month = 4;
    else if(strcmp(monthName, "May")==0)
        month = 5;
    else if(strcmp(monthName, "June")==0)
        month = 6;
    else if(strcmp(monthName, "July")==0)
        month = 7;
    else if(strcmp(monthName, "August")==0)
        month = 8;
    else if(strcmp(monthName, "September")==0)
        month = 9;
    else if(strcmp(monthName, "October")==0)
        month = 10;
    else if(strcmp(monthName, "November")==0)
        month = 11;
    else if(strcmp(monthName, "December")==0)
        month = 12;
    else
    {
        printf("Invalid month name");
        return;
    }

    // Check if day is valid
    if(day<1 || day>31)
    {
        printf("Invalid day");
        return;
    }

    // Check if month is valid
    if(month<1 || month>12)
    {
        printf("Invalid month");
        return;
    }

    // Check if year is valid
    if(year<0)
    {
        printf("Invalid year");
        return;
    }

    // Check if day is valid for the given month
    if((month==4 || month==6 || month==9 || month==11) && day>30)
    {
        printf("Invalid day for given month");
        return;
    }
    else if(month==2)
    {
        if(isLeap(year) && day>29)
        {
            printf("Invalid day for given month");
            return;
        }
        else if(!isLeap(year) && day>28)
        {
            printf("Invalid day for given month");
            return;
        }
    }

    // Print C date
    printf("%02d-%02d-%d", day, month, year);
}

int main()
{
    char date[20];
    printf("Enter natural language date (Ex: 1 January 2022): ");
    fgets(date, sizeof(date), stdin);
    convertDate(date);

    return 0;
}