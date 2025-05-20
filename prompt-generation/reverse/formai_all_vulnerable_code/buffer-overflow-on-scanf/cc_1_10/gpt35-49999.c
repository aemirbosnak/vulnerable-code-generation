//FormAI DATASET v1.0 Category: Math exercise ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * MIND-BENDING MATH EXERCISE!
 * In this program, we generate a random sequence of equations and ask the user to solve for 'x'.
 * But beware! These equations are not ordinary equations, they involve some math wizardry that might bend your mind a little.
 */

// Function to generate a random integer within a specified range
int random_int(int min, int max)
{
    return (rand() % (max - min + 1) + min);
}

// Function to generate a random operator (either + or -)
char random_operator()
{
    int op = random_int(0, 1);
    if (op == 0)
    {
        return '+';
    }
    else
    {
        return '-';
    }
}

// Function to generate a random equation that includes some math wizardry
void generate_equation(int *a, int *b, char *op1, char *op2, int *c, int *d, char *op3)
{
    // Choose random values for a, b, c, and d
    *a = random_int(1, 10);
    *b = random_int(1, 10);
    *c = random_int(1, 10);
    *d = random_int(1, 10);

    // Choose random operators for op1, op2, and op3
    *op1 = random_operator();
    *op2 = random_operator();
    *op3 = random_operator();

    // Generate the equation
    printf("%d%s(%d %c %d)%s%d %c %d = x\n", *a, op1, *b, op2, *c, op3, *d, op3, *c);
}

int main()
{
    srand(time(NULL)); // Initialize the random number generator with the current time

    int score = 0; // Keep track of the user's score

    printf("Welcome to the Mind-Bending Math Exercise!\n\n");
    printf("In this exercise, we will generate a sequence of equations that involve some math wizardry. Your task is to solve for 'x'.\n");
    printf("Each correct answer earns you one point, and each incorrect answer deducts one point.\n");
    printf("Let's get started!\n\n");

    // Generate 10 equations for the user to solve
    for (int i = 0; i < 10; i++)
    {
        int a, b, c, d;
        char op1, op2, op3;
        generate_equation(&a, &b, &op1, &op2, &c, &d, &op3);

        // Calculate the correct answer for the equation
        int correct_answer = 0;
        if (op3 == '+')
        {
            correct_answer = a * b + c + d;
        }
        else
        {
            correct_answer = a * b - c - d;
        }

        // Prompt the user for their answer
        int user_answer = 0;
        printf("Enter your answer: ");
        scanf("%d", &user_answer);

        // Check if the user's answer is correct
        if (user_answer == correct_answer)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect. The correct answer is %d.\n", correct_answer);
            score--;
        }

        printf("\n");
    }

    // Print the user's final score
    printf("Congratulations! You have completed the Mind-Bending Math Exercise.\n");
    printf("Your final score is %d. Well done!\n", score);

    return 0;
}