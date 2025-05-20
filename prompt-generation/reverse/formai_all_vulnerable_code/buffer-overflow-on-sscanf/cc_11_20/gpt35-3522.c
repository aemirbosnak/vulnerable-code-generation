//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: excited
// Welcome to the Natural Language Date Converter!
// This program converts verbal dates to numeric format.

#include <stdio.h>
#include <string.h>

int main() {
    char month[10], date[3], year[5], input[20];
    int month_num, date_num, year_num;

    printf("Welcome to the Natural Language Date Converter! \n");
    printf("Please enter a date in the following format: \n");
    printf("[Month] [Date], [Year]\n");

    fgets(input, 20, stdin); // Get input from user

    // Extracting month, date and year from input using sscanf function
    sscanf(input, "%s %s, %s", month, date, year);

    // Converting month from string to integer
    if (strncmp(month, "January", 7) == 0) {
        month_num = 1;
    } else if (strncmp(month, "February", 8) == 0) {
        month_num = 2;
    } else if (strncmp(month, "March", 5) == 0) {
        month_num = 3;
    } else if (strncmp(month, "April", 5) == 0) {
        month_num = 4;
    } else if (strncmp(month, "May", 3) == 0) {
        month_num = 5;
    } else if (strncmp(month, "June", 4) == 0) {
        month_num = 6;
    } else if (strncmp(month, "July", 4) == 0) {
        month_num = 7;
    } else if (strncmp(month, "August", 6) == 0) {
        month_num = 8;
    } else if (strncmp(month, "September", 9) == 0) {
        month_num = 9;
    } else if (strncmp(month, "October", 7) == 0) {
        month_num = 10;
    } else if (strncmp(month, "November", 8) == 0) {
        month_num = 11;
    } else if (strncmp(month, "December", 8) == 0) {
        month_num = 12;
    } else {
        printf("Sorry, I didn't understand the month. Please try again! \n");
        return 1;
    }

    // Converting date and year from string to integer
    date_num = atoi(date);
    year_num = atoi(year);

    // Outputting numeric format of the date
    printf("The numeric format of the date you entered is: \n");
    printf("%02d/%02d/%04d \n", month_num, date_num, year_num);

    printf("Thank you for using the Natural Language Date Converter! \n");

    return 0; // Program executed successfully
}