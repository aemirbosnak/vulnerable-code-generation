//FormAI DATASET v1.0 Category: Data validation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    printf("Welcome to the Data Validation Program!\n\n");

    char input[20]; // Initializing input char array
    int num;

    printf("Please enter your favorite number (between 1 and 10, inclusive): ");
    fgets(input, 20, stdin); // Reading the input from user

    // Validating the input data
    while ((sscanf(input, "%d", &num) != 1) || (num < 1) || (num > 10)) 
    {
        printf("Oops! Invalid input. Please enter a number between 1 and 10: ");
        fgets(input, 20, stdin); // Re-prompting for input
    }

    printf("\nGreat! You entered %d as your favorite number. Now let's validate your age.\n", num);

    int age;

    printf("\nPlease enter your age (between 18 and 99, inclusive): ");
    fgets(input, 20, stdin); // Reading the input from user

    // Validating the input data
    while ((sscanf(input, "%d", &age) != 1) || (age < 18) || (age > 99)) 
    {
        printf("Oops! Invalid input. Please enter your age (between 18 and 99, inclusive): ");
        fgets(input, 20, stdin); // Re-prompting for input
    }

    printf("\nCongratulations! You are eligible to use this program as you are %d years old.\n", age);

    printf("\nTime to validate your GPA. Please enter your GPA (between 0.0 and 4.0, inclusive): ");

    float gpa;

    fgets(input, 20, stdin); // Reading the input from user

    // Validating the input data
    while ((sscanf(input, "%f", &gpa) != 1) || (gpa < 0.0) || (gpa > 4.0)) 
    {
        printf("Oops! Invalid input. Please enter your GPA (between 0.0 and 4.0, inclusive): ");
        fgets(input, 20, stdin); // Re-prompting for input
    }

    printf("\nThat's amazing! You have a %0.2f GPA.\n", gpa);

    printf("\nThank you for using our Data Validation Program! We hope you enjoy using it!\n");

    return 0;
}