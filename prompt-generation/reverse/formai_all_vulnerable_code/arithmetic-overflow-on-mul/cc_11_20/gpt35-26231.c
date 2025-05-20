//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Alan Touring
#include <stdio.h>

// Function to return the number of days in a given month
int getDaysInMonth(int month, int year) {
    int days;

    switch(month) {
        // January
        case 1:
            days = 31;
            break;
        // February
        case 2:
            // Check for leap year
            if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                days = 29;
            else
                days = 28;
            break;
        // March
        case 3:
            days = 31;
            break;
        // April
        case 4:
            days = 30;
            break;
        // May
        case 5:
            days = 31;
            break;
        // June
        case 6:
            days = 30;
            break;
        // July
        case 7:
            days = 31;
            break;
        // August
        case 8:
            days = 31;
            break;
        // September
        case 9:
            days = 30;
            break;
        // October
        case 10:
            days = 31;
            break;
        // November
        case 11:
            days = 30;
            break;
        // December
        case 12:
            days = 31;
            break;
        // Invalid month
        default:
            days = -1;
            break;
    }

    return days;
}

// Function to convert a natural language date to a standard date format
void convertNaturalLanguageDate(char date[]) {
    char month[10];
    int day, year, i = 0, j = 0;

    // Loop through the date string to extract the month, day, and year
    while(date[i] != ' ') {
        month[j] = date[i];
        i++; j++;
    }
    month[j] = '\0';
    i++;
    j = 0;
    while(date[i] != ',') {
        day = day * 10 + (date[i] - '0');
        i++;
        j++;
    }
    i += 2;
    j = 0;
    while(date[i] != '\0') {
        year = year * 10 + (date[i] - '0');
        i++;
        j++;
    }

    // Convert the month string to a month integer
    int monthNum = 0;
    if(strcmp(month, "January") == 0)
        monthNum = 1;
    else if(strcmp(month, "February") == 0)
        monthNum = 2;
    else if(strcmp(month, "March") == 0)
        monthNum = 3;
    else if(strcmp(month, "April") == 0)
        monthNum = 4;
    else if(strcmp(month, "May") == 0)
        monthNum = 5;
    else if(strcmp(month, "June") == 0)
        monthNum = 6;
    else if(strcmp(month, "July") == 0)
        monthNum = 7;
    else if(strcmp(month, "August") == 0)
        monthNum = 8;
    else if(strcmp(month, "September") == 0)
        monthNum = 9;
    else if(strcmp(month, "October") == 0)
        monthNum = 10;
    else if(strcmp(month, "November") == 0)
        monthNum = 11;
    else if(strcmp(month, "December") == 0)
        monthNum = 12;

    // Check for invalid month
    if(monthNum == 0) {
        printf("Invalid month\n");
        return;
    }

    // Check for invalid day
    if(day > getDaysInMonth(monthNum, year) || day < 1) {
        printf("Invalid day\n");
        return;
    }

    // Output the converted date in standard format
    printf("%02d/%02d/%04d\n", monthNum, day, year);
}

// Main function
int main() {
    char date[20];

    // Get the natural language date from the user
    printf("Enter a natural language date (e.g. January 1, 2022): ");
    fgets(date, sizeof(date), stdin);

    // Convert the natural language date to a standard date format and output
    convertNaturalLanguageDate(date);

    return 0;
}