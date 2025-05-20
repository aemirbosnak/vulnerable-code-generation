//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function to convert natural language date to mm/dd/yyyy format */
char* convertDate(char* inputDate)
{
    char* month = malloc(3 * sizeof(char)); // allocate memory for month variable
    char* day = malloc(3 * sizeof(char));   // allocate memory for day variable
    char* year = malloc(5 * sizeof(char));  // allocate memory for year variable

    sscanf(inputDate, "%s %s %s", month, day, year); // scan the input date for month, day, and year

    /* convert month to numeric value */
    if (strcmp(month, "January") == 0) {
        strcpy(month, "01");
    }
    else if (strcmp(month, "February") == 0) {
        strcpy(month, "02");
    }
    else if (strcmp(month, "March") == 0) {
        strcpy(month, "03");
    }
    else if (strcmp(month, "April") == 0) {
        strcpy(month, "04");
    }
    else if (strcmp(month, "May") == 0) {
        strcpy(month, "05");
    }
    else if (strcmp(month, "June") == 0) {
        strcpy(month, "06");
    }
    else if (strcmp(month, "July") == 0) {
        strcpy(month, "07");
    }
    else if (strcmp(month, "August") == 0) {
        strcpy(month, "08");
    }
    else if (strcmp(month, "September") == 0) {
        strcpy(month, "09");
    }
    else if (strcmp(month, "October") == 0) {
        strcpy(month, "10");
    }
    else if (strcmp(month, "November") == 0) {
        strcpy(month, "11");
    }
    else if (strcmp(month, "December") == 0) {
        strcpy(month, "12");
    }
    else {
        printf("Invalid month. Please enter a valid month name.\n");
        exit(0);
    }

    /* remove any commas or dots from day */
    size_t len = strlen(day);
    if (day[len - 1] == ',' || day[len - 1] == '.') {
        day[len - 1] = '\0';
    }

    /* append leading zero to day if necessary */
    if (strlen(day) == 1) {
        memmove(day + 1, day, strlen(day) + 1);
        day[0] = '0';
    }

    /* append century to year if necessary */
    if (strlen(year) == 2) {
        if (atoi(year) < 50) {
            strcat(year, "20");
        }
        else {
            strcat(year, "19");
        }
    }

    /* concatenate the month, day, and year variables and return the result */
    char* result = malloc(11 * sizeof(char)); // allocate memory for result variable
    strcat(result, month);
    strcat(result, "/");
    strcat(result, day);
    strcat(result, "/");
    strcat(result, year);

    return result;
}

/* main function */
int main()
{
    char inputDate[30]; // declare variable to hold input date

    printf("Enter a date in natural language: ");
    fgets(inputDate, 30, stdin); // read input date from user

    /* remove newline character from input */
    size_t len = strlen(inputDate);
    if (inputDate[len - 1] == '\n') {
        inputDate[len - 1] = '\0';
    }

    char* convertedDate = convertDate(inputDate); // convert input date to mm/dd/yyyy format

    printf("Your date in mm/dd/yyyy format is: %s\n", convertedDate);

    free(convertedDate); // free allocated memory

    return 0;
}