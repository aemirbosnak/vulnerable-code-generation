//FormAI DATASET v1.0 Category: Math exercise ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Let's play a game of C Math exercise
    
    printf("Welcome to the Math Land! Let's see how good you are at Maths.\n\n");
    printf("In this game, we will generate two random numbers and you have to choose the correct equation to solve them!\n\n");
    
    srand(time(NULL)); // seed the random number generator with current time
    
    int num1 = rand() % 10; // generate a random number between 0 and 9
    int num2 = rand() % 10; // generate another random number between 0 and 9
    
    int result; // variable to store user's answer
    
    int option = rand() % 4; // generate a random number between 0 and 3 to determine the equation
    
    switch(option)
    {
        case 0:
            printf("What is the result of %d + %d? ", num1, num2);
            scanf("%d", &result);
            if(result == (num1 + num2))
                printf("Awesome! You got it right!\n");
            else
                printf("Sorry, that's incorrect. The correct answer is %d\n", (num1 + num2));
            break;
            
        case 1:
            printf("What is the result of %d - %d? ", num1, num2);
            scanf("%d", &result);
            if(result == (num1 - num2))
                printf("Excellent! You nailed it!\n");
            else
                printf("Oops, that's not correct. The right answer is %d\n", (num1 - num2));
            break;
            
        case 2:
            printf("What is the result of %d x %d? ", num1, num2);
            scanf("%d", &result);
            if(result == (num1 * num2))
                printf("Bravo! You are good at multiplication!\n");
            else
                printf("Incorrect. The answer is %d\n", (num1 * num2));
            break;
            
        case 3:
            printf("What is the result of %d / %d? (rounded to nearest integer) ", num1, num2);
            scanf("%d", &result);
            if(result == (num1 / num2))
                printf("Amazing! You got it right!\n");
            else
                printf("Sorry, incorrect. The correct answer is %d\n", (num1 / num2));    
            break;
            
        default:
            printf("Oops, something went wrong. Please try again.\n");
            break;
    }
    
    return 0;
}