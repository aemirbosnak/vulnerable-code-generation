//FormAI DATASET v1.0 Category: Math exercise ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int num1, num2, answer, userAnswer, score = 0, attempt = 0;

    // Display a welcome message
    printf("Welcome to the Math Mania game!\n\n");

    // Seed the random number generator with current time
    srand(time(NULL));

    // Loop through 10 questions
    for(int i = 0; i < 10; i++) {
        
        // Generate two random numbers between 1 and 100
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;
        
        // Generate a random operator
        char operator;
        int operatorNum = rand() % 3;
        if(operatorNum == 0) {
            operator = '+';
            answer = num1 + num2;
        } else if(operatorNum == 1) {
            operator = '-';
            answer = num1 - num2;
        } else {
            operator = '*';
            answer = num1 * num2;
        }
        
        // Ask the question
        printf("Question %d: What is %d %c %d?\n", i+1, num1, operator, num2);
        
        // Get the user's answer and validate it
        scanf("%d", &userAnswer);
        attempt++;
        if(userAnswer == answer) {
            // Correct answer
            printf("Correct!\n\n");
            score++;
        } else {
            // Incorrect answer
            printf("Incorrect. The correct answer is %d.\n\n", answer);
        }
    }
    
    // Display the final score and number of attempts
    printf("Game over! Final score: %d / 10\n", score);
    printf("You attempted %d questions.\n", attempt);
    
    // Return success
    return 0;
}