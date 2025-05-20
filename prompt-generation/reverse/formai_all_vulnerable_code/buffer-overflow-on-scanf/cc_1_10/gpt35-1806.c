//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold date information
typedef struct {
    int day;
    int month;
    int year;
} date;

// Function to convert a string date to a date structure
date strToDate(char* strDate) {
    date newDate;
    char* token;
    char* delim = "/";

    // Get the day
    token = strtok(strDate, delim);
    newDate.day = atoi(token);

    // Get the month
    token = strtok(NULL, delim);
    newDate.month = atoi(token);

    // Get the year
    token = strtok(NULL, delim);
    newDate.year = atoi(token);

    return newDate;
}

// Function to convert a date structure to a string date
char* dateToStr(date givenDate) {
    char* strDate = malloc(sizeof(char) * 11);

    // Format the date string
    sprintf(strDate, "%02d/%02d/%04d", givenDate.day, givenDate.month, givenDate.year);

    return strDate;
}

// Function to convert a date from the Gregorian calendar to the Julian calendar
date gregorianToJulian(date givenDate) {
    date newDate;

    // Calculate the Julian day
    int A = (14 - givenDate.month) / 12;
    int Y = givenDate.year + 4800 - A;
    int M = givenDate.month + 12 * A - 3;
    int JD = givenDate.day + (153 * M + 2) / 5 + 365 * Y + Y / 4 - Y / 100 + Y / 400 - 32045;

    // Split the Julian day into a Julian date
    int L = JD + 68569;
    int N = 4 * L / 146097;
    L = L - (146097 * N + 3) / 4;
    int I = 4000 * (L + 1) / 1461001;
    L = L - 1461 * I / 4 + 31;
    int J = 80 * L / 2447;
    int D = L - 2447 * J / 80;
    L = J / 11;
    int M2 = J + 2 - 12 * L;
    int Y2 = 100 * (N - 49) + I + L;

    // Assign the new date values
    newDate.day = D;
    newDate.month = M2;
    newDate.year = Y2;

    return newDate;
}

// Function to convert a date from the Julian calendar to the Gregorian calendar
date julianToGregorian(date givenDate) {
    date newDate;

    // Calculate the Julian day
    int JDN = 1721425 + givenDate.day + 367 * givenDate.year
        - (int) (0.75 * (givenDate.year + (int) ((givenDate.month + 9) / 12)));
    int p = JDN - 1721425;
    int y = (int) ((p - 0.25) / 365.25);
    int j = p - (int) (365.25 * y);
    int g = (int) (30.6001 * 14);
    int m = (int) (((j + 14 - g) / 30.6001));
    int d = j - (int) (30.6001 * m) + (p - (int) (p / 1461)*1461) / 365;
    int i;

    // Assign the new date values
    newDate.day = d;
    newDate.month = m - 1;
    newDate.year = y + (int) ((m - 1) / 12);

    return newDate;
}

int main() {
    date inputDate;
    date convertedDate;
    char inputStr[11];

    // Prompt the user for a date in the format "dd/mm/yyyy"
    printf("Enter the date you want to convert:\n");
    scanf("%s", inputStr);

    // Convert the input string to a date structure
    inputDate = strToDate(inputStr);

    // Determine the calendar type of the input date
    if (inputDate.year < 1582) {
        // Julian calendar
        convertedDate = julianToGregorian(inputDate);
        printf("The Gregorian calendar date is: %s\n", dateToStr(convertedDate));
    } else {
        // Gregorian calendar
        convertedDate = gregorianToJulian(inputDate);
        printf("The Julian calendar date is: %s\n", dateToStr(convertedDate));
    }

    return 0;
}