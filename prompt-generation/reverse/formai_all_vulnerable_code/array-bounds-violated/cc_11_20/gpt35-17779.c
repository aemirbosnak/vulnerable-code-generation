//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Cryptic
#include <stdio.h>

// Function to convert a date from natural language to a valid date format
void dateConverter(char* inputDate) {
    int day = 0, month = 0, year = 0;
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    char monthString[10];

    // Loop through the input string to extract day, month, and year
    for (i = 0; i < strlen(inputDate); i++) {
        if (isdigit(inputDate[i])) {
            if (j == 0) {
                k = i;
            }
            j++;
        } else if (isalpha(inputDate[i])) {
            if (l == 0) {
                m = i;
            }
            l++;
        }

        if (j == 2) {
            day = (inputDate[k] - '0') * 10 + (inputDate[k+1] - '0');
        } else if (j == 4) {
            year = (inputDate[k] - '0') * 1000 + (inputDate[k+1] - '0') * 100 + (inputDate[k+2] - '0') * 10 + (inputDate[k+3] - '0');
        }

        if (l > 0) {
            monthString[n] = inputDate[i];
            n++;
        }
    }
    monthString[n] = '\0';

    // Convert the month string to a numerical value
    if (strcasecmp(monthString, "january") == 0) {
        month = 1;
    } else if (strcasecmp(monthString, "february") == 0) {
        month = 2;
    } else if (strcasecmp(monthString, "march") == 0) {
        month = 3;
    } else if (strcasecmp(monthString, "april") == 0) {
        month = 4;
    } else if (strcasecmp(monthString, "may") == 0) {
        month = 5;
    } else if (strcasecmp(monthString, "june") == 0) {
        month = 6;
    } else if (strcasecmp(monthString, "july") == 0) {
        month = 7;
    } else if (strcasecmp(monthString, "august") == 0) {
        month = 8;
    } else if (strcasecmp(monthString, "september") == 0) {
        month = 9;
    } else if (strcasecmp(monthString, "october") == 0) {
        month = 10;
    } else if (strcasecmp(monthString, "november") == 0) {
        month = 11;
    } else if (strcasecmp(monthString, "december") == 0) {
        month = 12;
    } else {
        printf("Invalid month entered!\n");
        return;
    }

    // Output the result in a valid date format
    printf("%d-%02d-%02d\n", year, month, day);
}

int main() {
    char inputDate[50];
    printf("Enter a date in natural language (e.g. March 4th, 2021): ");
    fgets(inputDate, 50, stdin);
    inputDate[strcspn(inputDate, "\n")] = '\0'; // Remove new line character from input

    dateConverter(inputDate);

    return 0;
}