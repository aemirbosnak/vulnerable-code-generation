//FormAI DATASET v1.0 Category: Math exercise ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, operator, answer, user_answer, correct_answers = 0, wrong_answers = 0;

    srand(time(NULL)); // seed the random number generator

    printf("Welcome to the Math Quiz!\n");

    for(int i = 1; i <= 10; i++) // loop 10 times for 10 questions
    {
        num1 = rand() % 10 + 1; // generates a random number between 1 and 10
        num2 = rand() % 10 + 1; // generates another random number between 1 and 10
        operator = rand() % 3; // generates a random operator between 0 and 2

        // print out the question and the available choices
        printf("\nQuestion %d: What is %d ", i, num1);
        switch(operator)
        {
            case 0:
                printf("+");
                answer = num1 + num2;
                break;
            case 1:
                printf("-");
                answer = num1 - num2;
                break;
            case 2:
                printf("*");
                answer = num1 * num2;
                break;
        }
        printf(" %d?\n", num2);
        printf("a) %d\n", answer - 1);
        printf("b) %d\n", answer);
        printf("c) %d\n", answer + 1);

        printf("Enter your answer (a, b, or c): ");
        scanf(" %c", &user_answer); // read in the user's answer

        if(user_answer == 'a' || user_answer == 'A')
        {
            printf("You chose %c) %d. ", user_answer, answer - 1);
            if(answer - 1 == answer)
            {
                printf("This is the correct answer!\n");
                correct_answers++;
            }
            else
            {
                printf("Sorry, the correct answer is %d.\n", answer);
                wrong_answers++;
            }
        }
        else if(user_answer == 'b' || user_answer == 'B')
        {
            printf("You chose %c) %d. ", user_answer, answer);
            if(answer == answer)
            {
                printf("This is the correct answer!\n");
                correct_answers++;
            }
            else
            {
                printf("Sorry, the correct answer is %d.\n", answer);
                wrong_answers++;
            }
        }
        else if(user_answer == 'c' || user_answer == 'C')
        {
            printf("You chose %c) %d. ", user_answer, answer + 1);
            if(answer + 1 == answer)
            {
                printf("This is the correct answer!\n");
                correct_answers++;
            }
            else
            {
                printf("Sorry, the correct answer is %d.\n", answer);
                wrong_answers++;
            }
        }
        else
        {
            printf("Invalid input. Skipping question.\n");
        }
    }

    printf("\nYou got %d out of 10 questions correct.\n", correct_answers);
    printf("You got %d out of 10 questions wrong.\n", wrong_answers);

    return 0;
}