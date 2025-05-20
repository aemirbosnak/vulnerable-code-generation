//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char response[500];
    printf("My dear friend, prithee mayhap give me the date thou wishest to convert? (e.g. 'July 21, 2021')\n");
    scanf("%[^\n]%*c", response);
    
    char *month = strtok(response, " ");
    char *day = strtok(NULL, ",");
    char *year = strtok(NULL, " ");
    
    int month_number;
    if (strcmp(month, "January") == 0) {
        month_number = 1;
    } else if (strcmp(month, "February") == 0) {
        month_number = 2;
    } else if (strcmp(month, "March") == 0) {
        month_number = 3;
    } else if (strcmp(month, "April") == 0) {
        month_number = 4;
    } else if (strcmp(month, "May") == 0) {
        month_number = 5;
    } else if (strcmp(month, "June") == 0) {
        month_number = 6;
    } else if (strcmp(month, "July") == 0) {
        month_number = 7;
    } else if (strcmp(month, "August") == 0) {
        month_number = 8;
    } else if (strcmp(month, "September") == 0) {
        month_number = 9;
    } else if (strcmp(month, "October") == 0) {
        month_number = 10;
    } else if (strcmp(month, "November") == 0) {
        month_number = 11;
    } else {
        month_number = 12;
    }
    
    printf("I prithee tell me, art thy date from the Gregorian or Julian calendar? (Enter 'G' or 'J')\n");
    char calendar_choice;
    scanf(" %c", &calendar_choice);
    int year_number = atoi(year);
    
    if (toupper(calendar_choice) == 'G') {
        int julian_day = 367 * year_number - (7 * (year_number + (month_number + 9) / 12)) / 4 + (275 * month_number) / 9 + atoi(day) + 1721013.5;
        printf("Verily, thy date in the Julian calendar is: %d", julian_day);
    } else {
        int gregorian_year = year_number;
        int gregorian_month = month_number;
        int gregorian_day = atoi(day);
        if (gregorian_month <= 2) {
            gregorian_year--;
            gregorian_month += 12;
        }
        int a = gregorian_year / 100;
        int b = a / 4;
        int c = 2 - a + b;
        int e = (int)(365.25 * (gregorian_year + 4716));
        int f = (int)(30.6001 * (gregorian_month + 1));
        int julian_day = c + gregorian_day + e + f - 1524.5;
        printf("Forsooth, thy date in the Gregorian calendar is: %d", julian_day);
    }
    
    return 0;
}