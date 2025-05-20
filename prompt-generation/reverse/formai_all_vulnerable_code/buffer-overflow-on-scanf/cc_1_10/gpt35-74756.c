//FormAI DATASET v1.0 Category: Math exercise ; Style: decentralized
/**
 * This program demonstrates a decentralized style C Math exercise example in which
 * the user will be asked to solve addition, subtraction, multiplication or division 
 * problems with randomly generated numbers.
 * 
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1   // Minimum value for random number generation
#define MAX 10  // Maximum value for random number generation

// Function prototypes
int get_user_choice();
int generate_random_number();
int perform_operation(int, int, int);

// Main function
int main()
{
    // Set up random number generator
    srand(time(0));

    int operand_choice, result, user_answer;
    int num1 = generate_random_number();
    int num2 = generate_random_number();

    // Get user choice
    operand_choice = get_user_choice();

    // Perform the selected operation
    switch (operand_choice)
    {
    case 1:
        result = perform_operation(num1, num2, 1);
        printf("What is %d + %d? ", num1, num2);
        break;

    case 2:
        result = perform_operation(num1, num2, 2);
        printf("What is %d - %d? ", num1, num2);
        break;

    case 3:
        result = perform_operation(num1, num2, 3);
        printf("What is %d * %d? ", num1, num2);
        break;

    case 4:
        // Divisor cannot be 0, so keep generating a new number until it is not 0
        do {
            num2 = generate_random_number();
        } while (num2 == 0);

        result = perform_operation(num1, num2, 4);
        printf("What is %d / %d (rounded to the nearest whole number)? ", num1, num2);
        break;

    default:
        printf("Invalid input.\n");
        return 1;
    }

    // Get and check user's answer
    scanf("%d", &user_answer);
    if (user_answer == result) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is %d.\n", result);
    }
    return 0;
}

// Helper function: Gets user's choice of operation
int get_user_choice()
{
    int choice;
    printf("Please select an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &choice);
    return choice;
}

// Helper function: Generates a random number between MIN and MAX
int generate_random_number()
{
    return (rand() % (MAX - MIN + 1)) + MIN;
}

// Helper function: Performs the selected operation on num1 and num2
int perform_operation(int num1, int num2, int operation)
{
    int result;

    switch (operation)
    {
    case 1:
        result = num1 + num2;
        break;

    case 2:
        result = num1 - num2;
        break;

    case 3:
        result = num1 * num2;
        break;

    case 4:
        result = num1 / num2;
        break;

    default:
        printf("Error: Invalid operation.\n");
        return 0;
    }

    return result;
}