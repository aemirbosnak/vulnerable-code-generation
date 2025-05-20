//FormAI DATASET v1.0 Category: Data validation ; Style: statistical
#include <stdio.h>

int main() {
    // Declaring variables to store inputs
    int age, income, zipcode;
    char gender;

    // Prompting the user for inputs
    printf("Welcome to our program on data validation!\n");
    printf("Please enter your age (in years): ");
    scanf("%d", &age);
    printf("Please enter your gender (M/F): ");
    scanf(" %c", &gender);
    printf("Please enter your annual income (in USD): ");
    scanf("%d", &income);
    printf("Please enter your zipcode (5-digit): ");
    scanf("%d", &zipcode);

    // Validating age input
    if (age < 0 || age > 120) {
        printf("Invalid age input! Age should be between 0-120 years.\n");
    } else {
        printf("Age input is valid.\n");
    }

    // Validating gender input
    if (gender != 'M' && gender != 'F') {
        printf("Invalid gender input! Gender should be either M or F.\n");
    } else {
        printf("Gender input is valid.\n");
    }

    // Validating income input
    if (income < 0) {
        printf("Invalid income input! Income should be a positive number.\n");
    } else {
        printf("Income input is valid.\n");
    }

    // Validating zipcode input
    if (zipcode < 10000 || zipcode > 99999) {
        printf("Invalid zipcode input! Zipcode should be a 5-digit number.\n");
    } else {
        printf("Zipcode input is valid.\n");
    }

    // Displaying final message
    printf("Thank you for using our program on data validation!\n");

    return 0;
}