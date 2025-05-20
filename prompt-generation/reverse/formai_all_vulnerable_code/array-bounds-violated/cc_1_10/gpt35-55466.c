//FormAI DATASET v1.0 Category: Data validation ; Style: inquisitive
// Have you ever wondered how to validate data in C programs?
// Well, wonder no more! I present to you this unique data validation example program.

#include <stdio.h>

// Let's start by defining a function that checks if the input is a valid integer
int is_valid_integer(char input[])
{
    int i = 0;

    // Check if input is negative
    if (input[0] == '-')
        i = 1;

    // Check for non-digit characters
    for (; input[i] != '\0'; i++)
    {
        if (input[i] < '0' || input[i] > '9')
            return 0;
    }

    return 1;
}

int main()
{
    char age[3];
    char income[7];

    // Let's ask the user for their age
    printf("What is your age? ");

    // Now we need to validate the input to make sure it's a valid integer
    while (fgets(age, sizeof age, stdin))
    {
        // Remove newline character from input
        if (age[strlen(age) - 1] == '\n')
            age[strlen(age) - 1] = '\0';

        // Check if input is valid
        if (is_valid_integer(age))
            break;
        else
            printf("Invalid input. Please enter a valid age: ");
    }

    // Great! Now let's ask the user for their income
    printf("What is your income? ");

    // Same process: validate input to make sure it's a valid integer
    while (fgets(income, sizeof income, stdin))
    {
        // Remove newline character from input
        if (income[strlen(income) - 1] == '\n')
            income[strlen(income) - 1] = '\0';

        // Check if input is valid
        if (is_valid_integer(income))
            break;
        else
            printf("Invalid input. Please enter a valid income: ");
    }

    // Finally, let's print out the user's age and income
    printf("Your age is %d and your income is $%d.\n", atoi(age), atoi(income));

    return 0;
}