//FormAI DATASET v1.0 Category: Math exercise ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Generate two random numbers between 1 and 100
    srand(time(NULL));
    int num1 = rand() % 100 + 1;
    int num2 = rand() % 100 + 1;

    printf("Welcome to the Math Exercise Program!\n");
    printf("Today's exercise will involve the numbers %d and %d.\n\n", num1, num2);

    // Ask the user to perform addition, subtraction, multiplication, or division
    char operator;
    printf("What operation would you like to perform? (+, -, *, /): ");
    scanf("%c", &operator);

    // Perform the chosen operation and print the result
    int result;
    switch(operator)
    {
        case '+':
            result = num1 + num2;
            printf("%d + %d = %d\n", num1, num2, result);
            break;
        
        case '-':
            result = num1 - num2;
            printf("%d - %d = %d\n", num1, num2, result);
            break;
        
        case '*':
            result = num1 * num2;
            printf("%d * %d = %d\n", num1, num2, result);
            break;

        case '/':
            result = num1 / num2;
            printf("%d / %d = %d (integer division)\n", num1, num2, result);
            float fresult = (float) num1 / num2;
            printf("%d / %d = %.2f (floating-point division)\n", num1, num2, fresult);
            break;

        default:
            printf("Invalid operator entered.\n");
            break;
    }

    // Generate a new set of numbers and repeat the process
    printf("\n");
    main();

    return 0;
}