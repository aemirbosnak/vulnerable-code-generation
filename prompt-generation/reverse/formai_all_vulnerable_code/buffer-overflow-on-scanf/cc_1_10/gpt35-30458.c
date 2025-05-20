//FormAI DATASET v1.0 Category: Math exercise ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Oh my gosh, I just generated a random Math exercise for you!\n");
    printf("Are you ready to solve it? Let's get started!\n\n");

    srand(time(NULL)); // Seed for random number generation

    int num1 = rand() % 100; // Generate a random number from 0 to 99
    int num2 = rand() % 100;
    int choice = rand() % 3; // Randomly choose between addition, subtraction or multiplication

    int answer;
    char operation;

    switch(choice)
    {
        case 0:
            // Addition
            answer = num1 + num2;
            operation = '+';
            break;

        case 1:
            // Subtraction
            answer = num1 - num2;
            operation = '-';
            break;

        case 2:
            // Multiplication
            answer = num1 * num2;
            operation = '*';
            break;
    }

    printf("Your Math exercise is: %d %c %d = ?\n", num1, operation, num2);

    int user_answer;
    scanf("%d", &user_answer);

    if(user_answer == answer)
    {
        printf("\nOh wow, you got the correct answer! Congratulations!\n");
    }
    else
    {
        printf("\nOops, your answer is incorrect. Better luck next time!\n");
    }

    return 0;
}