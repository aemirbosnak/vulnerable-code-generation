//FormAI DATASET v1.0 Category: Online Examination System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numQuestions = 10; //Change the number of questions as needed
    int score = 0;
    int answer;
    srand(time(0)); //Seed the random number generator
    
    printf("Welcome to the Math Exam!\n");
    printf("You will be given %d questions.\n", numQuestions);
    printf("Please enter your answer for each question and hit enter.\n");
    
    for (int i = 0; i < numQuestions; i++) {
        int a = rand() % 100; //Random number from 0 to 99
        int b = rand() % 100; //Random number from 0 to 99
        
        //Choose a random mathematical operation
        int operation = rand() % 4;
        switch (operation) {
            case 0: //Addition
                printf("%d + %d = ", a, b);
                answer = a + b;
                break;
            case 1: //Subtraction
                printf("%d - %d = ", a, b);
                answer = a - b;
                break;
            case 2: //Multiplication
                printf("%d * %d = ", a, b);
                answer = a * b;
                break;
            case 3: //Division
                while (b == 0) { //Make sure b is not 0
                    b = rand() % 100; //Choose a random number again
                }
                printf("%d / %d = ", a, b);
                answer = a / b;
                break;
        }
        
        //Check the user's answer
        int userAnswer;
        scanf("%d", &userAnswer);
        if (userAnswer == answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", answer);
        }
    }
    
    printf("You have completed the exam.\n");
    printf("Your score is %d out of %d.\n", score, numQuestions);
    return 0;
}