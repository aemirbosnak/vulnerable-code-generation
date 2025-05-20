//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if given year is a leap year
int isLeapYear(int year) 
{ 
    if (year % 400 == 0) 
        return 1; 
   
    if (year % 100 == 0) 
        return 0; 
   
    if (year % 4 == 0) 
        return 1; 
   
    return 0; 
} 

// Function to convert date from natural language to numeric format
void convertDate(char *date) 
{ 
    int day, month, year;
    char monthStr[10], temp[10];
    sscanf(date, "%d %s %d", &day, monthStr, &year);
    
    // Convert month string to lowercase
    int i;
    for (i = 0; monthStr[i]; i++) 
        temp[i] = tolower(monthStr[i]);
    temp[i] = '\0';
    
    // Check for month in natural language and set month variable accordingly
    if (strcmp(temp, "january") == 0 || strcmp(temp, "jan") == 0) 
        month = 1;
    else if (strcmp(temp, "february") == 0 || strcmp(temp, "feb") == 0)
        month = 2;
    else if (strcmp(temp, "march") == 0 || strcmp(temp, "mar") == 0)
        month = 3;
    else if (strcmp(temp, "april") == 0 || strcmp(temp, "apr") == 0)
        month = 4;
    else if (strcmp(temp, "may") == 0)
        month = 5;
    else if (strcmp(temp, "june") == 0 || strcmp(temp, "jun") == 0)
        month = 6;
    else if (strcmp(temp, "july") == 0 || strcmp(temp, "jul") == 0)
        month = 7;
    else if (strcmp(temp, "august") == 0 || strcmp(temp, "aug") == 0)
        month = 8;
    else if (strcmp(temp, "september") == 0 || strcmp(temp, "sep") == 0)
        month = 9;
    else if (strcmp(temp, "october") == 0 || strcmp(temp, "oct") == 0)
        month = 10;
    else if (strcmp(temp, "november") == 0 || strcmp(temp, "nov") == 0)
        month = 11;
    else if (strcmp(temp, "december") == 0 || strcmp(temp, "dec") == 0)
        month = 12;
    else {
        printf("Invalid input\n");
        return;
    }
    
    // Check if given day is valid for given month
    if (day < 1 || day > 31) {
        printf("Invalid day\n");
        return;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        printf("Invalid day for given month\n");
        return;
    }
    else if (month == 2 && isLeapYear(year) && day > 29) {
        printf("Invalid day for given month\n");
        return;
    }
    else if (month == 2 && !isLeapYear(year) && day > 28) {
        printf("Invalid day for given month\n");
        return;
    }
    
    // Print the date in numeric format
    printf("%02d/%02d/%d\n", day, month, year); 
}

// Main function
int main() 
{
    char date[20];
    printf("Enter date in natural language (e.g. 5th August 2021): ");
    fgets(date, 20, stdin);
    convertDate(date); 
    return 0; 
}