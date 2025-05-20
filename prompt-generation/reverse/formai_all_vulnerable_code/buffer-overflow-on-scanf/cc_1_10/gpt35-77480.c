//FormAI DATASET v1.0 Category: Math exercise ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int num1, num2, userAns, actualAns, min, max;
    char operator;
    srand(time(NULL));
    int correct = 0, total = 0;

    printf("Welcome to the Math Exercise Program!\n");
    printf("How many questions would you like to answer? ");
    scanf("%d", &total);

    printf("What would you like the minimum value to be? ");
    scanf("%d", &min);

    printf("What would you like the maximum value to be? ");
    scanf("%d", &max);

    printf("\n\n");

    for (int i = 0; i < total; i++) {
        num1 = rand() % (max - min + 1) + min;
        num2 = rand() % (max - min + 1) + min;

        int opChoice = rand() % 4;

        if (opChoice == 0) {
            operator = '+';
            actualAns = num1 + num2;
        } else if (opChoice == 1) {
            operator = '-';
            actualAns = num1 - num2;
        } else if (opChoice == 2) {
            operator = '*';
            actualAns = num1 * num2;
        } else {
            operator = '/';
            if (num2 == 0) {
                i--;
                continue;
            }
            actualAns = num1 / num2;
        }


        printf("Question %d: %d %c %d = ", i + 1, num1, operator, num2);
        scanf("%d", &userAns);

        if (actualAns == userAns) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect! Correct answer is %d\n", actualAns);
        }

        printf("\n");
    }

    printf("Score: %d/%d\n", correct, total);

    return 0;

}