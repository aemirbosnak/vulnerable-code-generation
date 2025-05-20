//FormAI DATASET v1.0 Category: Math exercise ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program generates a math quiz for the user.
 * The quiz consists of 10 random math problems.
 * The user has to answer the problems as quick as possible.
 * The program calculates the time taken by the user to complete the quiz.
 * The user receives a score based on the number of correct answers
 * and the time taken to complete the quiz.
 */

int main()
{
    int i, a, b, answer, correct = 0;
    time_t start, end;
    double time_taken;
    
    time(&start); // getting the current time
    
    srand(time(NULL)); // initializing the random number generator
    
    printf("Welcome to the Math Quiz!\n");
    printf("You will have to answer 10 math problems as quick as possible.\n");
    printf("You will be given a score based on the number of correct answers and the time taken.\n");
    printf("Let's begin!\n\n");
    
    for (i = 1; i <= 10; i++)
    {
        a = rand() % 50 + 1; // generating a random number between 1 and 50
        b = rand() % 50 + 1; // generating another random number between 1 and 50
        
        printf("Problem %d: What is %d + %d? ", i, a, b);
        scanf("%d", &answer);
        
        if (answer == a + b)
        {
            printf("Correct!\n\n");
            correct++;
        }
        else
        {
            printf("Incorrect!\n\n");
        }
    }
    
    time(&end); // getting the current time
    
    time_taken = difftime(end, start); // calculating the time taken
    
    printf("Congratulations! You have completed the quiz.\n");
    printf("You have answered %d out of 10 problems correctly.\n", correct);
    printf("Your time taken was %.2f seconds.\n", time_taken);
    
    if (correct == 10)
    {
        printf("Wow! You have earned a perfect score!\n");
    }
    else if (correct >= 7)
    {
        printf("Great job! You have earned a good score!\n");
    }
    else
    {
        printf("Better luck next time! You have earned an average score.\n");
    }
    
    return 0;
}