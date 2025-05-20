//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DAYS_PER_MONTH(year, month) (month == 2? (month == 2 && (year % 4 == 0 && year % 100!= 0 || year % 400 == 0))? 29 : 28 : (month - 1) % 7 == 0? 31 : 30)

typedef struct {
    int day;
    int month;
    int year;
} Date;

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100!= 0) || year % 400 == 0;
}

char* getMonthName(int month) {
    switch(month) {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "Invalid month";
    }
}

void printDate(Date date) {
    printf("%s %d, %d\n", getMonthName(date.month), date.day, date.year);
}

int main() {
    int day, month, year;
    char input[10];

    // Get input from user
    printf("Enter date in format DD/MM/YYYY: ");
    scanf("%s", input);

    // Parse input into day, month, and year
    day = atoi(strtok(input, "/"));
    month = atoi(strtok(NULL, "/"));
    year = atoi(strtok(NULL, "/"));

    // Check if input is valid
    if(day < 1 || day > DAYS_PER_MONTH(year, month)) {
        printf("Invalid date\n");
        return 1;
    }

    // Create Date struct
    Date date;
    date.day = day;
    date.month = month;
    date.year = year;

    // Print date in natural language format
    printDate(date);

    return 0;
}