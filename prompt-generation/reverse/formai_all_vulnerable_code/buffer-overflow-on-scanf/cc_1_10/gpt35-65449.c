//FormAI DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // generate random numbers for the math problems
    srand(time(NULL));
    int num1 = rand() % 50; 
    int num2 = rand() % 10;
    int num3 = rand() % 100;
    int num4 = rand() % 5;
    
    // display the problem to the user
    printf("Let's do some math!\n");
    printf("What is %d x %d + %d - %d?\n", num1, num2, num3, num4);
    
    // get the user's answer
    int userAnswer;
    scanf("%d", &userAnswer);
    
    // calculate the correct answer
    int correctAnswer = num1 * num2 + num3 - num4;
    
    // check if the user's answer is correct
    if (userAnswer == correctAnswer) {
        printf("Congratulations! You got it right!\n");
    } else {
        printf("Oh no! The correct answer was %d.\n", correctAnswer);
    }
    
    // generate another math problem
    int num5 = rand() % 50;
    int num6 = rand() % 10;
    int num7 = rand() % 100;
    int num8 = rand() % 5;
    
    // display the problem to the user
    printf("Let's try another one!\n");
    printf("What is %d + %d x %d / %d?\n", num5, num6, num7, num8);
    
    // get the user's answer
    scanf("%d", &userAnswer);
    
    // calculate the correct answer
    int correctAnswer2 = num5 + num6 * num7 / num8;
    
    // check if the user's answer is correct
    if (userAnswer == correctAnswer2) {
        printf("Amazing! You got it right!\n");
    } else {
        printf("Oops! The correct answer was %d.\n", correctAnswer2);
    }
    
    printf("Thanks for playing! Come back soon for more exciting math problems!");
    
    return 0;
}