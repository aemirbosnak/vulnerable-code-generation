//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: excited
#include <stdio.h>

int main() {
    printf("Welcome to the C Natural Language Date Converter!\n");
    printf("This program converts dates from natural language to numerical format.\n");

    char month[10];
    int day, year;

    printf("Please enter the month in natural language (e.g. January): ");
    scanf("%s", month);

    printf("Please enter the day of the month (e.g. 17): ");
    scanf("%d", &day);

    printf("Please enter the year (e.g. 2021): ");
    scanf("%d", &year);

    printf("\nProcessing...\n\n");
    
    // Convert month to numerical format
    int num_month;
    if (strcmp(month, "January") == 0) {
        num_month = 1;
    }
    else if (strcmp(month, "February") == 0) {
        num_month = 2;
    }
    else if (strcmp(month, "March") == 0) {
        num_month = 3;
    }
    else if (strcmp(month, "April") == 0) {
        num_month = 4;
    }
    else if (strcmp(month, "May") == 0) {
        num_month = 5;
    }
    else if (strcmp(month, "June") == 0) {
        num_month = 6;
    }
    else if (strcmp(month, "July") == 0) {
        num_month = 7;
    }
    else if (strcmp(month, "August") == 0) {
        num_month = 8;
    }
    else if (strcmp(month, "September") == 0) {
        num_month = 9;
    }
    else if (strcmp(month, "October") == 0) {
        num_month = 10;
    }
    else if (strcmp(month, "November") == 0) {
        num_month = 11;
    }
    else if (strcmp(month, "December") == 0) {
        num_month = 12;
    }
    else {
        printf("Invalid month input!\n");
        return -1;
    }

    // Output the converted date
    printf("The numerical equivalent of the date you entered is: %02d/%02d/%04d\n", num_month, day, year);

    printf("\nThank you for using the C Natural Language Date Converter! Have a nice day :)\n");

    return 0;
}