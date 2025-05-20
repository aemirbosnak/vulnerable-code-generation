//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: mind-bending
#include<stdio.h>
#include<string.h>

// Function to check if the year is a leap year
int isLeapYear(int year){
    // If the year is evenly divisible by 4, it could be a leap year
    if(year % 4 == 0){
        // If the year is evenly divisible by 100, it MAY NOT be a leap year
        if(year % 100 == 0){
            // If the year is evenly divisible by 400, it is definitely a leap year
            if(year % 400 == 0){
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year){
    // If February, check if it is a leap year
    if(month == 2){
        if(isLeapYear(year)){
            return 29;
        }
        else{
            return 28;
        }
    }
    // If April, June, September or November, return 30
    else if(month == 4 || month == 6 || month == 9 || month == 11){
        return 30;
    }
    // All other months have 31 days
    else{
        return 31;
    }
}

int main(){
    // Get the date from the user
    printf("Please enter a date in the format dd/mm/yyyy: ");
    char date[11];
    fgets(date, 11, stdin);

    // Parse the day, month and year from the input string
    int day, month, year;
    sscanf(date, "%d/%d/%d", &day, &month, &year);

    // Check that the input is valid i.e. the month and day are within range
    if(month < 1 || month > 12){
        printf("Invalid input: month must be between 1 and 12.\n");
        return 1;
    }
    if(day < 1 || day > getDaysInMonth(month, year)){
        printf("Invalid input: day must be between 1 and %d.\n", getDaysInMonth(month, year));
        return 1;
    }

    // Calculate the number of days from the beginning of the year
    int numDays = 0;
    for(int i = 1; i < month; i++){
        numDays += getDaysInMonth(i, year);
    }
    numDays += day;

    // Print out the result
    printf("The date %s is day %d of the year %d.\n", date, numDays, year);

    return 0;
}