//FormAI DATASET v1.0 Category: Math exercise ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, answer, userAnswer, count = 0;
    char operator;
    srand(time(0)); //seeding the random number generator

    printf("Welcome to this math exercise program, I am grateful to help you!\n");
    printf("You will be given a set of math problems to solve.\n");
    printf("Please enter your answers and I will let you know if you're correct or not.\n");
    printf("Are you ready? Let's get started!\n");

    //generate random math problems and check user's answer
    for (int i = 0; i < 10; i++)
    {
        //generate two random numbers between 1 and 100
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;

        //generate a random operator (+, -, *)
        switch(rand() % 3)
        {
            case 0:
                operator = '+';
                answer = num1 + num2;
                break;
            case 1:
                operator = '-';
                answer = num1 - num2;
                break;
            case 2:
                operator = '*';
                answer = num1 * num2;
                break;
        }

        //ask user to solve math problem and check answer
        printf("\n%d) What is %d %c %d?\n", i+1, num1, operator, num2);
        scanf("%d", &userAnswer);
        fflush(stdin);

        if (answer == userAnswer)
        {
            printf("Correct! Good job!\n");
            count++;
        } 
        else 
        {
            printf("Incorrect. The answer is %d.\n", answer);
        }
    }

    //display final score
    printf("\nYou got %d out of 10 correct. Thank you for playing!\n", count);

    return 0;
}