//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char operator;
    float num1, num2, result;

    // Futuristic beep sound
    system("play beep.wav");

    // Display a holographic menu
    printf("\nWelcome to the Quantum Calculator!\n");
    printf("Please select an operator:");
    printf("\n1. Addition (+)");
    printf("\n2. Subtraction (-)");
    printf("\n3. Multiplication (*)");
    printf("\n4. Division (/)");
    printf("\nPlease enter your choice:");

    // Get the user's choice
    scanf("%c", &operator);

    // Validate the user's choice
    if (operator != '1' && operator != '2' && operator != '3' && operator != '4')
    {
        printf("Invalid operator. Please try again.\n");
        return;
    }

    // Get the first number
    printf("Enter the first number:");
    scanf("%f", &num1);

    // Get the second number
    printf("Enter the second number:");
    scanf("%f", &num2);

    // Perform the calculation
    switch (operator)
    {
        case '1':
            result = num1 + num2;
            break;
        case '2':
            result = num1 - num2;
            break;
        case '3':
            result = num1 * num2;
            break;
        case '4':
            result = num1 / num2;
            break;
    }

    // Display the result
    printf("The result is: %.2f\n", result);

    // Futuristic chime sound
    system("play chime.wav");
}