//FormAI DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
This program generates random multiplication problems with a mix of positive and negative integers, 
and prompts the user to solve them. The program provides feedback on correct/incorrect answers
and keeps track of the user's score. 
*/

int main()
{
    int num_problems = 10;  // Number of problems user will be asked to solve
    int score = 0;   // User's score
    int i; // loop counter
    
    srand(time(NULL));  // seed random number generator with current time

    // loop through num_problems and generate random multiplication problems
    for(i=0; i<num_problems; i++)
    {
        // generate two random numbers between -10 and 10
        int num1 = rand() % 21 - 10;
        int num2 = rand() % 21 - 10;

        // prompt user to solve the problem and get their answer
        int guess;
        printf("What is %d * %d?\n", num1, num2);
        scanf("%d", &guess);

        // calculate the correct answer
        int answer = num1 * num2;

        // provide feedback on user's answer
        if(guess == answer)
        {
            printf("Correct!\n");
            score++;  // increment user's score
        }
        else
        {
            printf("Incorrect. The correct answer is %d.\n", answer);
        }

        printf("\n");  // print blank line before next problem
    }

    // print final score and message based on user's performance
    printf("You scored %d out of %d.\n", score, num_problems);
    if(score == num_problems)
    {
        printf("Great job! You got them all correct!\n");
    }
    else if(score >= num_problems/2)
    {
        printf("Not bad! You got at least half of them correct.\n");
    }
    else
    {
        printf("You could do better. Keep practicing!\n");
    }

    return 0;
}