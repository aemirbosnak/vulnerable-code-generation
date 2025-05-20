//FormAI DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with current time
    
    int a, b, answer, userAnswer, numQuestions;
    float score;
    
    printf("Welcome to the Math Exercise program!\n");
    
    // get user input for number of questions
    printf("How many questions would you like to answer? ");
    scanf("%d", &numQuestions);
    
    // loop through the number of questions specified
    for (int i = 1; i <= numQuestions; i++) {
        printf("\nQuestion %d:\n", i);
        
        // generate two random numbers between 1 and 10
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        
        // generate a random math operator (+, -, or *)
        int op = rand() % 3;
        char operatorChar;
        switch (op) {
            case 0:
                answer = a + b;
                operatorChar = '+';
                break;
            case 1:
                answer = a - b;
                operatorChar = '-';
                break;
            case 2:
                answer = a * b;
                operatorChar = '*';
                break;
        }
        
        // output the question and prompt the user for answer
        printf("What is %d %c %d? ", a, operatorChar, b);
        scanf("%d", &userAnswer);
        
        // check if user answer is correct and update score accordingly
        if (userAnswer == answer) {
            printf("Correct! ");
            score++;
        } else {
            printf("Incorrect. ");
        }
        
        // output current score and percentage
        printf("Your score is %.0f / %d (%.0f%%)\n", score, i, (score/i)*100);
    }
    
    // output final score and percentage
    printf("\nThanks for playing!\nYour final score is %.0f / %d (%.0f%%)", score, numQuestions, (score/numQuestions)*100);
    
    return 0;
}