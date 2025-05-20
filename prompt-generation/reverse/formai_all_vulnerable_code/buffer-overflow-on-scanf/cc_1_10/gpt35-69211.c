//FormAI DATASET v1.0 Category: Math exercise ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, answer, userAnswer, score = 0;
    printf("\t\tMath Exercise Program\n\n");
    printf("Instructions: You will be given a math problem,\n");
    printf("and you have to solve it by inputting the correct answer.\n");
    printf("For each correct answer, you will get 10 points.\n");
    printf("For each wrong answer, you will lose 5 points.\n");
    printf("If you input an incorrect answer 3 times,\n");
    printf("the correct answer will be displayed.\n\n");
    srand(time(0)); // initialize random seed
  
    for (int i = 0; i < 10; i++) { // 10 questions
        num1 = rand() % 20 + 1; // generate random number between 1 and 20
        num2 = rand() % 20 + 1;
        operator = rand() % 4; // generate random operator
        switch (operator) { // determine operator based on random number
            case 0:
                answer = num1 + num2;
                printf("%d + %d = ", num1, num2);
                break;
            case 1:
                answer = num1 - num2;
                printf("%d - %d = ", num1, num2);
                break;
            case 2:
                answer = num1 * num2;
                printf("%d * %d = ", num1, num2);
                break;
            case 3:
                answer = num1 / num2;
                printf("%d / %d = ", num1, num2);
                break;
            default:
                break;
        }
        scanf("%d", &userAnswer);
        if (userAnswer == answer) {
            printf("Correct!\n");
            score += 10;
        } else {
            printf("Incorrect.\n");
            score -= 5;
            for (int j = 0; j < 2; j++) { // 3 tries total
                printf("Try again: ");
                scanf("%d", &userAnswer);
                if (userAnswer == answer) {
                    printf("Correct!\n");
                    score += 10;
                    break; // exit loop if correct
                } else {
                    printf("Incorrect.\n");
                    score -= 5;
                }
            }
            if (userAnswer != answer) { // all tries incorrect
                printf("The correct answer is %d\n", answer);
            }
        }
        printf("Current score: %d\n", score);
    }
    printf("\nFinal score: %d", score);
    return 0;
}