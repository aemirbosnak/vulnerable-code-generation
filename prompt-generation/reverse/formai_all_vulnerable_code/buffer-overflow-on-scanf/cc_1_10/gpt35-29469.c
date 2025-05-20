//FormAI DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, result, answer, count = 0;
    char operation;

    srand(time(0)); // Seed the random number generator with current time

    while(count < 10) // Generate 10 math problems
    {
        num1 = rand() % 100; // Generate a random number between 0 and 99
        num2 = rand() % 100; // Generate a random number between 0 and 99

        if(num1 % 2 == 0 && num2 % 2 == 0) // Check if both numbers are even
        {
            operation = '+';
            result = num1 + num2; // Calculate the result of addition
            printf("%d %c %d = ", num1, operation, num2);
            scanf("%d", &answer); // Get the user's answer
            if(result == answer)
            {
                printf("Correct!\n");
            }
            else
            {
                printf("Incorrect. The answer is %d\n", result);
            }
        }
        else if(num1 % 2 != 0 && num2 % 2 != 0) // Check if both numbers are odd
        {
            operation = '-';
            result = num1 - num2; // Calculate the result of subtraction
            printf("%d %c %d = ", num1, operation, num2);
            scanf("%d", &answer); // Get the user's answer
            if(result == answer)
            {
                printf("Correct!\n");
            }
            else
            {
                printf("Incorrect. The answer is %d\n", result);
            }
        }
        else // If one number is even and the other is odd
        {
            operation = '*';
            result = num1 * num2; // Calculate the result of multiplication
            printf("%d %c %d = ", num1, operation, num2);
            scanf("%d", &answer); // Get the user's answer
            if(result == answer)
            {
                printf("Correct!\n");
            }
            else
            {
                printf("Incorrect. The answer is %d\n", result);
            }
        }

        count++; // Increment the problem count
    }

    printf("Congratulations! You have completed the math exercise!\n");

    return 0;
}