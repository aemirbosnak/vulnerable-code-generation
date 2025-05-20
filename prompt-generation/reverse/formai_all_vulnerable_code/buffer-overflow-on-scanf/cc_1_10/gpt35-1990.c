//FormAI DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, answer, userAnswer;
    srand(time(NULL)); // initialize random seed

    printf("=========== Math Exercise Game ===========\n");
    printf("Do you want to play with addition, subtraction, multiplication or division?\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &operator);

    switch(operator) {
        case 1: // Addition
            num1 = rand() % 101; // generate numbers between 0 - 100
            num2 = rand() % 101;
            answer = num1 + num2;

            printf("What is %d + %d ?\n", num1, num2);
            scanf("%d", &userAnswer);

            if(userAnswer == answer) {
                printf("Correct! %d + %d = %d", num1, num2, answer);
            } else {
                printf("Wrong answer :( The correct answer is %d + %d = %d", num1, num2, answer);
            }
            break;

        case 2: // Subtraction
            num1 = rand() % 101; // generate numbers between 0 - 100
            num2 = rand() % 101;
            answer = num1 - num2;

            printf("What is %d - %d ?\n", num1, num2);
            scanf("%d", &userAnswer);

            if(userAnswer == answer) {
                printf("Correct! %d - %d = %d", num1, num2, answer);
            } else {
                printf("Wrong answer :( The correct answer is %d - %d = %d", num1, num2, answer);
            }
            break;

        case 3: // Multiplication
            num1 = rand() % 11; // generate numbers between 0 - 10
            num2 = rand() % 11;
            answer = num1 * num2;

            printf("What is %d * %d ?\n", num1, num2);
            scanf("%d", &userAnswer);

            if(userAnswer == answer) {
                printf("Correct! %d * %d = %d", num1, num2, answer);
            } else {
                printf("Wrong answer :( The correct answer is %d * %d = %d", num1, num2, answer);
            }
            break;

        case 4: // Division
            num1 = (rand() % 10) + 1; // generate numbers between 1 - 10
            num2 = (rand() % 10) + 1;
            answer = num1 / num2;

            printf("What is %d / %d ?\n", num1, num2);
            scanf("%d", &userAnswer);

            if(userAnswer == answer) {
                printf("Correct! %d / %d = %d", num1, num2, answer);
            } else {
                printf("Wrong answer :( The correct answer is %d / %d = %d", num1, num2, answer);
            }
            break;

        default:
            printf("Invalid operator input. Please choose between 1 - 4.");
            break;
    }

    return 0;
}