//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if given year is a leap year or not
int isLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;   
}

// Function to convert date from NLD to Gredian Calendar
void nldToGreg(int year, int month, int day) {
    int gyear = year + 543; // Convert NLD year to Gredian year
    int gmonth, gday;
    
    // Check for different months
    switch (month) {
        case 1:
            gmonth = 1;
            gday = day;
            break;
        case 2:
            gmonth = 1;
            gday = day + 31;
            break;
        case 3:
            gmonth = 2;
            if (isLeap(gyear)) {
                gday = day + 60;
            }
            else {
                gday = day + 59;
            }
            break;
        case 4:
            gmonth = 3;
            if (isLeap(gyear)) {
                gday = day + 91;
            }
            else {
                gday = day + 90;
            }
            break;
        case 5:
            gmonth = 4;
            if (isLeap(gyear)) {
                gday = day + 121;
            }
            else {
                gday = day + 120;
            }
            break;
        case 6:
            gmonth = 5;
            if (isLeap(gyear)) {
                gday = day + 152;
            }
            else {
                gday = day + 151;
            }
            break;
        case 7:
            gmonth = 6;
            if (isLeap(gyear)) {
                gday = day + 182;
            }
            else {
                gday = day + 181;
            }
            break;
        case 8:
            gmonth = 7;
            if (isLeap(gyear)) {
                gday = day + 213;
            }
            else {
                gday = day + 212;
            }
            break;
        case 9:
            gmonth = 8;
            if (isLeap(gyear)) {
                gday = day + 244;
            }
            else {
                gday = day + 243;
            }
            break;
        case 10:
            gmonth = 9;
            if (isLeap(gyear)) {
                gday = day + 274;
            }
            else {
                gday = day + 273;
            }
            break;
        case 11:
            gmonth = 10;
            if (isLeap(gyear)) {
                gday = day + 305;
            }
            else {
                gday = day + 304;
            }
            break;
        case 12:
            gmonth = 11;
            if (isLeap(gyear)) {
                gday = day + 335;
            }
            else {
                gday = day + 334;
            }
            break;
        default:
            printf("Invalid Month!");
            exit(0);
    }

    printf("The equivalent Gregorian date is %d-%02d-%02d", gyear, gmonth, gday);
}

int main() {
    printf("Welcome to the Natural Language Date (NLD) to Gregorian Calendar converter!\n");
    printf("Please enter the date in the format of yyyy-mm-dd: ");
    char nld[11];
    scanf("%s", nld);

    // Extract year, month and day from date string
    char yearStr[5], monthStr[3], dayStr[3];
    strncpy(yearStr, nld, 4);
    strncpy(monthStr, nld+5, 2);
    strncpy(dayStr, nld+8, 2);
    int year = atoi(yearStr);
    int month = atoi(monthStr);
    int day = atoi(dayStr);

    // Check if date is valid
    if (year < 1000 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31) {
        printf("Invalid date!");
        exit(0);
    }

    // Convert NLD to Gregorian
    nldToGreg(year, month, day);

    return 0;
}