//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, result, choice;
    char playAgain;

    srand(time(NULL));

    printf("Welcome to Retro Arithmetic!\n");
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    if (choice < 1 || choice > 4)
    {
        printf("Invalid choice. Exiting...\n");
        return 0;
    }

    num1 = rand() % 100;
    num2 = rand() % 100;

    switch (choice)
    {
        case 1:
            result = num1 + num2;
            printf("The result is: %d\n", result);
            break;
        case 2:
            if (num1 > num2)
            {
                result = num1 - num2;
            }
            else
            {
                result = num2 - num1;
            }
            printf("The result is: %d\n", result);
            break;
        case 3:
            result = num1 * num2;
            printf("The result is: %d\n", result);
            break;
        case 4:
            if (num2 == 0)
            {
                printf("Cannot divide by zero. Exiting...\n");
                return 0;
            }
            result = num1 / num2;
            printf("The result is: %d\n", result);
            break;
    }

    printf("Do you want to play again? (y/n) ");
    scanf(" %c", &playAgain);

    if (playAgain == 'y' || playAgain == 'Y')
    {
        main();
    }
    else
    {
        printf("Exiting...\n");
        return 0;
    }

    return 0;
}