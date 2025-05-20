//FormAI DATASET v1.0 Category: Math exercise ; Style: lively
/* Welcome to the Math Academy's Tricky Math Test! */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    /* Initializing variables */
    int num1, num2, answer, userAnswer, score = 0;
    char operator;

    /* Initializing random seed */
    srand(time(0));

    /* Looping through 10 Math questions */
    for(int i = 1; i <= 10; i++) {
        /* Generating random numbers between 1 and 100 */
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;

        /* Randomly choosing operator */
        switch(rand() % 4) {
            case 0:
                operator = '+';
                answer = num1 + num2;
                break;
            case 1:
                operator = '-';
                answer = num1 - num2;
                break;
            case 2:
                operator = '*';
                answer = num1 * num2;
                break;
            case 3:
                operator = '/';
                answer = num1 / num2;
                break;
        }

        /* Prompting the user to answer the question */
        printf("\nQuestion %d: What is %d %c %d? ", i, num1, operator, num2);
        scanf("%d", &userAnswer);

        /* Checking if user's answer matches the real answer */
        if(userAnswer == answer) {
            printf("Correct!");
            score++;
        }
        else {
            printf("Wrong! The real answer is %d", answer);
        }
    }

    /* Printing the final score and a message according to the score */
    printf("\n\nYour final score is %d out of 10.", score);
    if(score == 10) {
        printf(" Congratulations, you are a Math genius!");
    }
    else if(score >= 7) {
        printf(" Well done!");
    }
    else if(score >= 5) {
        printf(" Not bad, but you can do better!");
    }
    else {
        printf(" Better luck next time!");
    }

    return 0;
}