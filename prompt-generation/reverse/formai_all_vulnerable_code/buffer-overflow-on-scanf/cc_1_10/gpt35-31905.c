//FormAI DATASET v1.0 Category: Math exercise ; Style: automated
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Generate random integers for the operands
    int a = rand() % 100;
    int b = rand() % 100;

    // Choose a random operator
    char op;
    int result;
    switch(rand() % 4)
    {
        case 0:
            op = '+';
            result = a + b;
            break;
        case 1:
            op = '-';
            result = a - b;
            break;
        case 2:
            op = '*';
            result = a * b;
            break;
        case 3:
            op = '/';
            if (b == 0)
            {
                printf("Error: Division by zero!\n");
                return 1;
            }
            result = a / b;
            break;
    }

    printf("What is %d %c %d?\n", a, op, b);

    // Read in the user's guess
    int guess;
    scanf("%d", &guess);

    // Check the answer
    if (guess == result)
    {
        printf("Congratulations, you are correct!\n");
    }
    else
    {
        printf("Sorry, the correct answer is %d.\n", result);
    }

    return 0;
}