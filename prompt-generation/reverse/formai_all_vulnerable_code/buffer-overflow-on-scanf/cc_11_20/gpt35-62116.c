//FormAI DATASET v1.0 Category: Math exercise ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    const int NUM_QUESTIONS = 5;
    const int MAX_NUM = 20;
    const int MIN_NUM = 1;
    int correctAnswers = 0;
    srand(time(NULL));

    for (int i = 1; i <= NUM_QUESTIONS; i++) {
        int a = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
        int b = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
        int operator = rand() % 3;

        printf("%d) ", i);
        switch (operator) {
            case 0:
                printf("%d + %d = ", a, b);
                int sum;
                scanf("%d", &sum);
                if (sum == a + b) {
                    printf("Correct!\n");
                    correctAnswers++;
                } else {
                    printf("Incorrect. The answer is %d.\n", a + b);
                }
                break;
            case 1:
                printf("%d - %d = ", a > b ? a : b, a > b ? b : a);
                int difference;
                scanf("%d", &difference);
                if (difference == a > b ? a - b : b - a) {
                    printf("Correct!\n");
                    correctAnswers++;
                } else {
                    printf("Incorrect. The answer is %d.\n", a > b ? a - b : b - a);
                }
                break;
            case 2:
                printf("%d * %d = ", a, b);
                int product;
                scanf("%d", &product);
                if (product == a * b) {
                    printf("Correct!\n");
                    correctAnswers++;
                } else {
                    printf("Incorrect. The answer is %d.\n", a * b);
                }
                break;
        }
    }

    printf("You answered %d out of %d questions correctly.\n", correctAnswers, NUM_QUESTIONS);

    return 0;
}