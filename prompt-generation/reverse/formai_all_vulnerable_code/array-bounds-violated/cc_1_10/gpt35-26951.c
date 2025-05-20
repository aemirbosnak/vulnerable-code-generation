//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert date from natural language to date format
char* naturalToDate(char* naturalDate) {
    char* date = (char*) malloc(sizeof(char) * 11);
    int day, month, year;

    // tokenize the natural date string
    char* token = strtok(naturalDate, " ");
    while(token != NULL) {
        if(strcmp(token, "January") == 0) {
            month = 1;
        } else if(strcmp(token, "February") == 0) {
            month = 2;
        } else if(strcmp(token, "March") == 0) {
            month = 3;
        } else if(strcmp(token, "April") == 0) {
            month = 4;
        } else if(strcmp(token, "May") == 0) {
            month = 5;
        } else if(strcmp(token, "June") == 0) {
            month = 6;
        } else if(strcmp(token, "July") == 0) {
            month = 7;
        } else if(strcmp(token, "August") == 0) {
            month = 8;
        } else if(strcmp(token, "September") == 0) {
            month = 9;
        } else if(strcmp(token, "October") == 0) {
            month = 10;
        } else if(strcmp(token, "November") == 0) {
            month = 11;
        } else if(strcmp(token, "December") == 0) {
            month = 12;
        } else if(isdigit(token[0])) {
            day = atoi(token);
        } else {
            year = atoi(token);
        }
        token = strtok(NULL, " ");
    }

    // construct the date string in dd/mm/yyyy format
    sprintf(date, "%02d/%02d/%04d", day, month, year);
    return date;
}

int main() {
    char naturalDate[100];
    printf("Enter a natural language date (e.g. \"June 1st, 2022\"): ");
    fgets(naturalDate, 100, stdin);

    // remove newline character from input
    if(naturalDate[strlen(naturalDate) - 1] == '\n') {
        naturalDate[strlen(naturalDate) - 1] = '\0';
    }

    // convert natural language date to date format
    char* date = naturalToDate(naturalDate);
    printf("Date in date format: %s\n", date);

    // free dynamically allocated memory
    free(date);
    return 0;
}