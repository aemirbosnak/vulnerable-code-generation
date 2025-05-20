//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
    char date[15];
    int day, month, year, leapYear = 0;

    printf("My love, please enter a date in natural language format (e.g. January 1st, 2022): ");
    fgets(date, sizeof(date), stdin);
    
    // Remove comma and convert month to lowercase
    int len = strlen(date);
    date[len-2] = '\0';
    date[0] = tolower(date[0]);
    for(int i=1; i<len-3; i++) {
        if(date[i] == ' ') {
            date[i+1] = tolower(date[i+1]);
        }
    }

    // Convert month to number
    if(strcmp(date, "january") == 0) {
        month = 1;
    } else if(strcmp(date, "february") == 0) {
        month = 2;
    } else if(strcmp(date, "march") == 0) {
        month = 3;
    } else if(strcmp(date, "april") == 0) {
        month = 4;
    } else if(strcmp(date, "may") == 0) {
        month = 5;
    } else if(strcmp(date, "june") == 0) {
        month = 6;
    } else if(strcmp(date, "july") == 0) {
        month = 7;
    } else if(strcmp(date, "august") == 0) {
        month = 8;
    } else if(strcmp(date, "september") == 0) {
        month = 9;
    } else if(strcmp(date, "october") == 0) {
        month = 10;
    } else if(strcmp(date, "november") == 0) {
        month = 11;
    } else if(strcmp(date, "december") == 0) {
        month = 12;
    } else {
        printf("My love, I'm sorry but that's not a valid date. Please try again.\n");
        return 0;
    }

    printf("My love, what year is it? ");
    scanf("%d", &year);

    // Check if it's a leap year
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        leapYear = 1;
    }
   
    printf("My love, what day is it? ");
    scanf("%d", &day);
    
    // Check if day is valid
    if(day < 1 || day > 31) {
        printf("My love, I'm sorry but that's not a valid day. Please try again.\n");
        return 0;
    }
    
    // Check if day is valid for the month
    if(month == 2) {
        if(leapYear == 1) {
            if(day > 29) {
                printf("My love, I'm sorry but February only has 29 days this year. Please try again.\n");
                return 0;
            }
        } else {
            if(day > 28) {
                printf("My love, I'm sorry but February only has 28 days this year. Please try again.\n");
                return 0;
            }
        }
    } else if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        printf("My love, I'm sorry but that month only has 30 days. Please try again.\n");
        return 0;
    }
    
    printf("My love, the date you entered is: %d/%d/%d\n", month, day, year);
    
    return 0;
}