//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert month from string to integer
int convertMonth(char* month) {
    if(strcmp(month, "January") == 0) {
        return 1;
    } else if(strcmp(month, "February") == 0) {
        return 2;
    } else if(strcmp(month, "March") == 0) {
        return 3;
    } else if(strcmp(month, "April") == 0) {
        return 4;
    } else if(strcmp(month, "May") == 0) {
        return 5;
    } else if(strcmp(month, "June") == 0) {
        return 6;
    } else if(strcmp(month, "July") == 0) {
        return 7;
    } else if(strcmp(month, "August") == 0) {
        return 8;
    } else if(strcmp(month, "September") == 0) {
        return 9;
    } else if(strcmp(month, "October") == 0) {
        return 10;
    } else if(strcmp(month, "November") == 0) {
        return 11;
    } else if(strcmp(month, "December") == 0) {
        return 12;
    } else {
        return -1;
    }
}

int main() {
    char input[50], *month;
    int day, year, monthInt;

    printf("Welcome to the Natural Language Date Converter.\n");
    printf("Please enter the date in the following format: [Month] [day], [year]\n");
    scanf("%[^\n]", input); // read the whole line as input

    // separate the month, day, and year from the input string
    month = strtok(input, " ");
    scanf("%d,", &day);
    scanf("%d", &year);

    // convert month from string to integer
    monthInt = convertMonth(month);

    // handle errors
    if(monthInt == -1 || day < 1 || day > 31 || year < 0) {
        printf("Error: Invalid input.\n");
        return 0;
    }

    // print the output
    printf("%d/%d/%d\n", monthInt, day, year);

    return 0;
}