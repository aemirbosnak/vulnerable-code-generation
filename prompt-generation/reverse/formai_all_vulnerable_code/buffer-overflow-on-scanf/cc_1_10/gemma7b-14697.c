//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void main()
{
    int num1, num2, choice;
    float result;

    // Display menu options
    printf("Enter 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division:\n");
    scanf("%d", &choice);

    // Get the two numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Perform the operation based on the choice
    switch (choice)
    {
        case 1:
            result = (float)num1 + (float)num2;
            break;
        case 2:
            result = (float)num1 - (float)num2;
            break;
        case 3:
            result = (float)num1 * (float)num2;
            break;
        case 4:
            if (num2 == 0)
            {
                printf("Cannot divide by zero\n");
            }
            else
            {
                result = (float)num1 / (float)num2;
            }
            break;
        default:
            printf("Invalid choice\n");
    }

    // Display the result
    if (result != -1)
    {
        printf("The result is: %.2f\n", result);
    }

    return;
}