//Code Llama-13B DATASET v1.0 Category: Natural Language Date Converter ; Style: optimized
/*
 * nldateconv.c
 *
 * A program to convert natural language dates to ISO-8601 format.
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to convert natural language date to ISO-8601 format
char* convert_nldate(char* nldate) {
    // Initialize variables
    char* iso_date = malloc(sizeof(char) * 11);
    char* tokens[3];
    int i;

    // Split the natural language date into tokens
    tokens[0] = strtok(nldate, " ");
    for (i = 1; i < 3; i++) {
        tokens[i] = strtok(NULL, " ");
    }

    // Convert the tokens to integers
    int month = atoi(tokens[0]);
    int day = atoi(tokens[1]);
    int year = atoi(tokens[2]);

    // Check if the date is valid
    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1900 || year > 2099) {
        printf("Invalid date!\n");
        return NULL;
    }

    // Convert the date to ISO-8601 format
    sprintf(iso_date, "%04d-%02d-%02d", year, month, day);

    return iso_date;
}

int main() {
    // Test the function
    char* nldate = "25 December 2022";
    char* iso_date = convert_nldate(nldate);
    printf("ISO-8601 format: %s\n", iso_date);

    return 0;
}