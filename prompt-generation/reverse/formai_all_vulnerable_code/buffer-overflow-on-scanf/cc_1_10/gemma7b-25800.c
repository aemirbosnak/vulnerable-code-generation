//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input_date[20] = "";
    char month_name[3] = "";
    int day_number = 0;
    int year = 0;
    int is_valid = 0;

    printf("Enter the date in the format MM/DD/YYYY:");
    scanf("%s", input_date);

    // Validate the input date
    if (strlen(input_date) != 10) {
        printf("Invalid input format.\n");
        return 1;
    }

    // Extract the month name, day number, and year
    month_name[0] = input_date[0] - 48;
    month_name[1] = input_date[1] - 48;
    month_name[2] = '\0';
    day_number = atoi(&input_date[3]) ;
    year = atoi(&input_date[6]) ;

    // Check if the date is valid
    if (month_name[0] < 1 || month_name[0] > 12) {
        printf("Invalid month.\n");
        is_valid = 0;
    } else if (day_number < 1 || day_number > 31) {
        printf("Invalid day.\n");
        is_valid = 0;
    } else if (year < 1900 || year > 2023) {
        printf("Invalid year.\n");
        is_valid = 0;
    } else {
        is_valid = 1;
    }

    // If the date is valid, display the converted date
    if (is_valid) {
        printf("The converted date is: ");
        printf("%s %d, %d", month_name, day_number, year);
        printf("\n");
    } else {
        printf("Invalid date.\n");
    }

    return 0;
}