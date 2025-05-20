//FormAI DATASET v1.0 Category: Online Examination System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // seed for random number generator
    int numQuestions = 10;  // number of questions
    int numCorrect = 0;  // number of correct answers
    int i;

    printf("Welcome to the C Online Examination System!\n\n");
    printf("You will be asked %d questions. Please answer them to the best of your ability.\n\n", numQuestions);
    
    for (i = 0; i < numQuestions; i++) {
        int num1 = rand() % 20 + 1;  // random number between 1 and 20
        int num2 = rand() % 20 + 1;  // random number between 1 and 20
        int result;  // holds the value of the result
        
        // Generate a random operator ( +, -, *, / )
        int op = rand() % 4;
        
        // Ask the question based on the randomly generated operator
        switch(op) {
            case 0:  // Addition
                printf("Question %d: What is %d + %d?\n", i+1, num1, num2);
                result = num1 + num2;
                break;
            case 1:  // Subtraction
                printf("Question %d: What is %d - %d?\n", i+1, num1, num2);
                result = num1 - num2;
                break;
            case 2:  // Multiplication
                printf("Question %d: What is %d * %d?\n", i+1, num1, num2);
                result = num1 * num2;
                break;
            case 3:  // Division
                printf("Question %d: What is %d / %d?\n", i+1, num1, num2);
                result = num1 / num2;
                break;
        }
        
        // Get the user's answer
        int userAnswer;
        scanf("%d", &userAnswer);
        
        // Check if the user's answer is correct
        if (userAnswer == result) {
            printf("Correct!\n\n");
            numCorrect++;
        } else {
            printf("Incorrect. The correct answer is: %d\n\n", result);
        }
    }
    
    // Calculate the user's score and display it
    float score = ((float)numCorrect / numQuestions) * 100;
    printf("You answered %d out of %d questions correctly.\n", numCorrect, numQuestions);
    printf("Your score is %.2f%%.\n\n", score);
    
    printf("Thank you for taking the C Online Examination System. Goodbye!\n");
    
    return 0;
}