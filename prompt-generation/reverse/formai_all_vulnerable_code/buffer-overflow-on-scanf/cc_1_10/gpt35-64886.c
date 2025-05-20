//FormAI DATASET v1.0 Category: Math exercise ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(){

    srand(time(NULL)); //set seed for random function to produce different numbers each time the program runs
    int num1 = rand() % 100; //generate random number between 0 and 99
    int num2 = rand() % 100;
    
    printf("Welcome to the Math Exercise Program!\n\n");
    printf("Today's exercise is to find the hypotenuse of a right triangle.\n");
    printf("The two legs of the triangle are %.2d and %.2d.\n\n", num1, num2);
    
    double hypotenuse = sqrt((double)((num1 * num1) + (num2 * num2))); //calculate hypotenuse using Pythagorean Theorem (c = sqrt(a^2 + b^2))
    
    printf("Using the Pythagorean Theorem, the hypotenuse of the triangle is: %.2f\n\n", hypotenuse);
    
    printf("Now, it's your turn to solve some problems!\n");
    printf("What is the length of the hypotenuse of a right triangle with legs of 8 and 15?\n\n");
    
    double userAnswer;
    scanf("%lf", &userAnswer); //get user input for their answer
    
    double correctAnswer = sqrt(8*8 + 15*15); //calculate correct answer using Pythagorean Theorem
    
    if(fabs(userAnswer - correctAnswer) < 0.001){ //use fabs function to get absolute value of difference between user answer and correct answer. If it is less than 0.001 (i.e. within an acceptable margin of error), then the answer is considered correct.
        printf("\nCongratulations! Your answer of %.2f is correct!\n\n", userAnswer);
    } else {
        printf("\nI'm sorry, your answer of %.2f is incorrect. The correct answer is %.2f\n\n", userAnswer, correctAnswer);
    }
    
    printf("Let's try another problem.\n");
    printf("What is the length of the hypotenuse of a right triangle with legs of 5 and 12?\n\n");
    
    double userAnswer2;
    scanf("%lf", &userAnswer2);
    
    double correctAnswer2 = sqrt(5*5 + 12*12);
    
    if(fabs(userAnswer2 - correctAnswer2) < 0.001){
        printf("\nCongratulations! Your answer of %.2f is correct!\n\n", userAnswer2);
    } else {
        printf("\nI'm sorry, your answer of %.2f is incorrect. The correct answer is %.2f\n\n", userAnswer2, correctAnswer2);
    }
    
    printf("Great job! You're becoming a math whiz!\n");
    
    return 0;
}