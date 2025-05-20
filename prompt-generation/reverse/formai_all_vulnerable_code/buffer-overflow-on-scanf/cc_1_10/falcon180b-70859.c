//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2;
    char operator;
    int result;
    int choice;
    int score = 0;

    printf("Welcome to the Math Quiz!\n");
    printf("How many questions do you want to answer? ");
    scanf("%d", &choice);

    srand(time(NULL));
    int random_num1, random_num2;

    for (int i = 1; i <= choice; i++) {
        num1 = rand() % 50 + 1;
        num2 = rand() % 50 + 1;
        operator = rand() % 4;

        switch (operator) {
            case 0:
                printf("Question %d: %d + %d = ", i, num1, num2);
                scanf("%d", &result);
                if (result == num1 + num2) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Incorrect. The correct answer is %d.\n", num1 + num2);
                }
                break;
            case 1:
                printf("Question %d: %d - %d = ", i, num1, num2);
                scanf("%d", &result);
                if (result == num1 - num2) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Incorrect. The correct answer is %d.\n", num1 - num2);
                }
                break;
            case 2:
                printf("Question %d: %d * %d = ", i, num1, num2);
                scanf("%d", &result);
                if (result == num1 * num2) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Incorrect. The correct answer is %d.\n", num1 * num2);
                }
                break;
            case 3:
                printf("Question %d: %d / %d = ", i, num1, num2);
                scanf("%d", &result);
                if (result == num1 / num2) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Incorrect. The correct answer is %d.\n", num1 / num2);
                }
                break;
        }
    }

    printf("Your final score is %d out of %d.\n", score, choice);

    return 0;
}