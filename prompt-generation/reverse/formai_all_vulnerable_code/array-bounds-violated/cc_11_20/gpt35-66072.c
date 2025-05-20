//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char date[11];
    printf("Enter a date in natural language (e.g. January 10th, 2022): ");
    fgets(date, 11, stdin); // Get input from user

    // Parse the month from the input
    char month[10];
    int i = 0;
    while (date[i] != ' ' && date[i] != '\n') {
        month[i] = date[i];
        i++;
    }
    month[i] = '\0';

    // Parse the day from the input
    char day[3];
    i += 2; // Skip the space and the first digit of the day
    int j = 0;
    while (date[i] != ',' && date[i] != '\n') {
        day[j] = date[i];
        i++;
        j++;
    }
    day[j] = '\0';

    // Parse the year from the input
    char year[5];
    i += 2; // Skip the comma and the space
    j = 0;
    while (date[i] != '\n') {
        year[j] = date[i];
        i++;
        j++;
    }
    year[j] = '\0';

    // Determine the numerical value of the month
    int numeric_month;
    if (strcmp(month, "January") == 0) {
        numeric_month = 1;
    } else if (strcmp(month, "February") == 0) {
        numeric_month = 2;
    } else if (strcmp(month, "March") == 0) {
        numeric_month = 3;
    } else if (strcmp(month, "April") == 0) {
        numeric_month = 4;
    } else if (strcmp(month, "May") == 0) {
        numeric_month = 5;
    } else if (strcmp(month, "June") == 0) {
        numeric_month = 6;
    } else if (strcmp(month, "July") == 0) {
        numeric_month = 7;
    } else if (strcmp(month, "August") == 0) {
        numeric_month = 8;
    } else if (strcmp(month, "September") == 0) {
        numeric_month = 9;
    } else if (strcmp(month, "October") == 0) {
        numeric_month = 10;
    } else if (strcmp(month, "November") == 0) {
        numeric_month = 11;
    } else {
        numeric_month = 12;
    }

    // Print the converted date in Cryptic format
    printf("%s-%d-%s\n", year, numeric_month, day);

    return 0;
}