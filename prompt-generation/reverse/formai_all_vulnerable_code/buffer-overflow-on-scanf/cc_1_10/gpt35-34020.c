//FormAI DATASET v1.0 Category: Math exercise ; Style: irregular
/*
 * This program generates a unique math exercise for the user.
 * The exercise is a bit irregular, but it ensures a good workout for the brain!
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between a and b (inclusive)
int random_int(int a, int b)
{
    return rand() % (b - a + 1) + a;
}

// Function to generate a random operator
char random_operator()
{
    int r = random_int(1, 4);
    switch (r)
    {
        case 1: return '+';
        case 2: return '-';
        case 3: return '*';
        case 4: return '/';
    }
}

int main()
{
    srand(time(NULL)); // Seed the random number generator

    // Print a welcome message
    printf("Welcome to the math exercise program!\n\n");
    printf("You will be presented with a series of math exercises.\n");
    printf("Your task is to solve each exercise as fast as possible.\n");
    printf("Type your answer and press enter to submit.\n");
    printf("The program will tell you if your answer is correct or not.\n");
    printf("You will get 1 point for each correct answer.\n");
    printf("Good luck!\n\n");

    int score = 0; // Keep track of the user's score

    // Generate 10 math exercises
    for (int i = 1; i <= 10; i++)
    {
        // Generate three random numbers and an operator
        int a = random_int(1, 10);
        int b = random_int(1, 10);
        int c = random_int(1, 10);
        char op1 = random_operator();
        char op2 = random_operator();

        // Print the exercise
        printf("%d. %d %c %d %c %d = ", i, a, op1, b, op2, c);

        // Get the user's answer
        int answer;
        scanf("%d", &answer);

        // Evaluate the expression
        int result;
        switch (op1)
        {
            case '+':
                switch (op2)
                {
                    case '+': result = a + b + c; break;
                    case '-': result = a + b - c; break;
                    case '*': result = a + b * c; break;
                    case '/': result = a + b / c; break;
                }
                break;
            case '-':
                switch (op2)
                {
                    case '+': result = a - b + c; break;
                    case '-': result = a - b - c; break;
                    case '*': result = a - b * c; break;
                    case '/': result = a - b / c; break;
                }
                break;
            case '*':
                switch (op2)
                {
                    case '+': result = a * b + c; break;
                    case '-': result = a * b - c; break;
                    case '*': result = a * b * c; break;
                    case '/': result = a * b / c; break;
                }
                break;
            case '/':
                switch (op2)
                {
                    case '+': result = a / b + c; break;
                    case '-': result = a / b - c; break;
                    case '*': result = a / b * c; break;
                    case '/': result = a / b / c; break;
                }
                break;
        }

        // Check if the answer is correct
        if (answer == result)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect! The correct answer is %d.\n", result);
        }
    }

    // Print the final score
    printf("\nCongratulation! You have finished all the exercises.\n");
    printf("Your score is %d out of 10.\n", score);

    return 0;
}