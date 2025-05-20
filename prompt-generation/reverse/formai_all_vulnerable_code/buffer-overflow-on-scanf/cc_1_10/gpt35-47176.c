//FormAI DATASET v1.0 Category: Math exercise ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // initialize variables
    int num1, num2, ans, userAns;
    int score = 0;
    time_t t;

    // display welcome message
    printf("Welcome to the Math Quiz!\n");
    
    // generate random numbers within a range 
    srand((unsigned) time(&t)); 
    num1 = rand() % 100;
    num2 = rand() % 100;

    // display the math problem and prompt user for input
    printf("What is %d multiplied by %d?\n", num1, num2);
    scanf("%d", &userAns);
    
    // calculate the correct answer
    ans = num1 * num2;
    
    // compare user answer with correct answer
    if (userAns == ans) {
        printf("Congratulations! You got it right!\n");
        score++;
    } else {
        printf("Sorry, %d multiplied by %d is %d\n", num1, num2, ans);
    }
    
    // repeat the process 4 more times
    for (int i = 0; i < 4; i++) {
        num1 = rand() % 100;
        num2 = rand() % 100;
        printf("\nWhat is %d multiplied by %d?\n", num1, num2);
        scanf("%d", &userAns);
        ans = num1 * num2;
        if (userAns == ans) {
            printf("Congratulations! You got it right!\n");
            score++;
        } else {
            printf("Sorry, %d multiplied by %d is %d\n", num1, num2, ans);
        }
    }

    // display final score
    printf("\nYou got %d out of 5 questions correct.\n", score);

    return 0;
}