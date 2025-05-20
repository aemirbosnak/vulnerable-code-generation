//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12

// Function to check if a string is numeric
int isNumeric(char* str) { 
    int i = 0; 
    while (str[i] != '\0') { 
        if (str[i] < 48 || str[i] > 57) return 0; 
        i++; 
    } 
    return 1; 
}

// Function to convert month name to number
int monthToNum(char* month) {
    if (strcmp(month, "january") == 0 || strcmp(month, "jan") == 0) return JAN;
    if (strcmp(month, "february") == 0 || strcmp(month, "feb") == 0) return FEB;
    if (strcmp(month, "march") == 0 || strcmp(month, "mar") == 0) return MAR;
    if (strcmp(month, "april") == 0 || strcmp(month, "apr") == 0) return APR;
    if (strcmp(month, "may") == 0) return MAY;
    if (strcmp(month, "june") == 0 || strcmp(month, "jun") == 0) return JUN;
    if (strcmp(month, "july") == 0 || strcmp(month, "jul") == 0) return JUL;
    if (strcmp(month, "august") == 0 || strcmp(month, "aug") == 0) return AUG;
    if (strcmp(month, "september") == 0 || strcmp(month, "sep") == 0) return SEP;
    if (strcmp(month, "october") == 0 || strcmp(month, "oct") == 0) return OCT;
    if (strcmp(month, "november") == 0 || strcmp(month, "nov") == 0) return NOV;
    if (strcmp(month, "december") == 0 || strcmp(month, "dec") == 0) return DEC;
    return 0;
}

// Main function that converts natural language date to numeric date
int main(int argc, char* argv[]) {
    char date[30];
    char* day, *month, *year;
    int dayNum, monthNum, yearNum;

    // If no argument is given, print error message
    if (argc <= 1) {
        printf("Error: Missing argument!\n");
        exit(0);
    }

    // Get the date argument and split it into day, month and year
    strcpy(date, argv[1]);
    day = strtok(date, " ");
    month = strtok(NULL, " ");
    year = strtok(NULL, " ");

    // If any of the day, month or year is missing, print error message
    if (day == NULL || month == NULL || year == NULL) {
        printf("Error: Invalid date format!\n");
        exit(0);
    }

    // Convert day and year to numeric values
    if (!isNumeric(day) || !isNumeric(year)) {
        printf("Error: Invalid day or year value!\n");
        exit(0);
    }
    dayNum = atoi(day);
    yearNum = atoi(year);

    // Convert month to numeric value
    monthNum = monthToNum(month);
    if (monthNum == 0) {
        printf("Error: Invalid month name!\n");
        exit(0);
    }

    // Print the numeric date
    printf("%d-%02d-%02d\n", yearNum, monthNum, dayNum);
    return 0;
}