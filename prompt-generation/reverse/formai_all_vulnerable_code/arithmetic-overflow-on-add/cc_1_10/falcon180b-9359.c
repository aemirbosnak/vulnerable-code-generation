//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: portable
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to check if a string is a valid date
int is_valid_date(char *date) {
    struct tm tm;
    strptime(date, "%d-%m-%Y", &tm);
    if (tm.tm_year + 1900 < 1000 || tm.tm_year + 1900 > 9999) {
        return 0;
    }
    return 1;
}

// Function to convert a date string to a numerical representation
int date_to_num(char *date) {
    struct tm tm;
    strptime(date, "%d-%m-%Y", &tm);
    return mktime(&tm);
}

// Function to convert a numerical representation to a date string
void num_to_date(int num, char *date) {
    time_t t = num;
    struct tm *tm = localtime(&t);
    strftime(date, 20, "%d-%m-%Y", tm);
}

// Main function to prompt user for input and call other functions
int main() {
    char input[80];
    char date[20];
    int choice;
    int num;

    printf("Enter a date in DD-MM-YYYY format: ");
    scanf("%s", input);

    if (is_valid_date(input)) {
        printf("Valid date!\n");
    } else {
        printf("Invalid date.\n");
    }

    printf("Enter your choice:\n1. Convert date to numerical representation\n2. Convert numerical representation to date\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            num = date_to_num(input);
            printf("Numerical representation: %d\n", num);
            break;
        case 2:
            printf("Enter numerical representation: ");
            scanf("%d", &num);
            num_to_date(num, date);
            printf("Date: %s\n", date);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}