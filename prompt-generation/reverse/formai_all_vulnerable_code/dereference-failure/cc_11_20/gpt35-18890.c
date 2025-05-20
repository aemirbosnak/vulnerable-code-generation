//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // Create an array to store the month names
    char *months[12] = {"January", "February", "March",
                        "April", "May", "June",
                        "July", "August", "September",
                        "October", "November", "December"};

    // Create an array to store the number of days in each month
    int daysInMonth[12] = {31, 28, 31,
                           30, 31, 30,
                           31, 31, 30,
                           31, 30, 31};

    // Ask the user for input
    printf("Please enter a date in the format mm/dd/yyyy: ");
    char *inputDate;
    scanf("%ms", &inputDate);

    // Split the input into month, day, and year
    char *monthStr = strtok(inputDate, "/");
    char *dayStr = strtok(NULL, "/");
    char *yearStr = strtok(NULL, "/");

    // Convert the month, day, and year strings to integers
    int month = atoi(monthStr);
    int day = atoi(dayStr);
    int year = atoi(yearStr);

    // Check for a valid date
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > daysInMonth[month-1]){
        printf("Invalid date.\n");
        return 1;
    }

    // Calculate the number of days in the current year
    int numDays = 0;
    for (int i=0; i<month-1; i++){
        numDays += daysInMonth[i];
    }
    numDays += day;

    // Check for a leap year and adjust the number of days if necessary
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        if (month > 2){
            numDays++;
        }
    }

    // Print the output
    printf("The date %s is day %d of the year %d.\n", inputDate, numDays, year);
    printf("It is %s %d, %d.\n", months[month-1], day, year);

    return 0;
}