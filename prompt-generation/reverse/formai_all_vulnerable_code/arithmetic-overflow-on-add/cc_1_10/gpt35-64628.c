//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: distributed
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function to convert string to integer
int stringToInt(char* str) {
    int len = strlen(str);
    int num = 0;
    for (int i = 0; i < len; i++) {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

// Function to find the number of days in a month
int daysInMonth(int month, int year) {
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return 29;
        } else {
            return 28;
        }
    } else if (month <= 7 && month % 2 != 0 || month >= 8 && month % 2 == 0) {
        return 31;
    } else {
        return 30;
    }
}

// Function to calculate the day number
int calculateDayNumber(int day, int month, int year) {
    int dayNumber = 0;
    for (int i = 1; i < year; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            dayNumber += 366;
        } else {
            dayNumber += 365;
        }
    }
    for (int i = 1; i < month; i++) {
        dayNumber += daysInMonth(i, year);
    }
    dayNumber += day;
    return dayNumber;
}

// Function to convert Gregorian date to Julian date
int gregorianToJulian(int day, int month, int year) {
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    int jdn = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    return jdn;
}

// Function to convert Julian date to Gregorian date
void julianToGregorian(int jdn, int* day, int* month, int* year) {
    int j = 32044 + jdn;
    int g = j / 146097;
    int dg = j % 146097;
    int c = (dg / 36524 + 1) * 3 / 4;
    int dc = dg - c * 36524;
    int b = dc / 1461;
    int db = dc % 1461;
    int a = (db / 365 + 1) * 3 / 4;
    int da = db - a * 365;
    int y = g * 400 + c * 100 + b * 4 + a;
    int m = (da * 5 + 308) / 153 - 2;
    int d = da - (m + 4) * 153 / 5 + 122;
    *day = d;
    *month = m;
    *year = y - 4800 + (m + 2) / 12;
}

// Function to convert Julian date to Islamic date
void julianToIslamic(int jdn, int* day, int* month, int* year) {
    int jd = jdn - 1948440 + 10632;
    int year1 = (jd - 1) / 354;
    int jd1 = 29 * year1 + 235;
    int i = 1;
    while (jd >= jd1 + 354) {
        jd1 += 354;
        i++;
    }
    int month1 = (jd - jd1) / 29 + 1;
    int day1 = jd - jd1 - (month1 - 1) * 29;
    *day = day1;
    *month = month1;
    *year = year1 + i;
}

int main() {
    int day, month, year;
    char input[20], date[20], output[20];
    printf("Enter a date (dd/mm/yyyy): ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d/%d/%d", &day, &month, &year);
    int gregorianDate = gregorianToJulian(day, month, year);
    julianToIslamic(gregorianDate, &day, &month, &year);
    sprintf(date, "%02d/%02d/%04d", day, month, year);
    printf("Islamic Date: %s\n", date);
    printf("Would you like to convert this back to Gregorian? (y/n) ");
    fgets(output, sizeof(output), stdin);
    if (strcmp(output, "y\n") == 0) {
        julianToGregorian(gregorianDate, &day, &month, &year);
        sprintf(date, "%02d/%02d/%04d", day, month, year);
        printf("Gregorian Date: %s\n", date);
    }
    return 0;
}