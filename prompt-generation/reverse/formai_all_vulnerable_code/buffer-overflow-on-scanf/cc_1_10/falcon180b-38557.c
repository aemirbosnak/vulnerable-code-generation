//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUM 100
#define MIN_NUM 1
#define MAX_OPERATIONS 10

int main() {
    int num1, num2, result, operation, i;
    char repeat;

    srand(time(NULL));
    num1 = rand() % MAX_NUM + MIN_NUM;
    num2 = rand() % MAX_NUM + MIN_NUM;

    printf("Welcome to the Math Exercise Game!\n");
    printf("Please solve the following problem:\n");
    printf("%d %c %d = ", num1, (rand() % 4) + 1, num2);

    scanf("%d", &result);

    if (result == (num1 % num2)) {
        printf("Correct! You're a math whiz!\n");
    } else {
        printf("Incorrect. The correct answer is %d.\n", num1 % num2);
    }

    printf("\nDo you want to play again? (y/n): ");
    scanf(" %c", &repeat);

    while (repeat == 'y' || repeat == 'Y') {
        num1 = rand() % MAX_NUM + MIN_NUM;
        num2 = rand() % MAX_NUM + MIN_NUM;
        operation = rand() % 4;

        printf("\nSolve the following problem:\n");
        switch (operation) {
            case 0:
                printf("%d + %d = ", num1, num2);
                break;
            case 1:
                printf("%d - %d = ", num1, num2);
                break;
            case 2:
                printf("%d * %d = ", num1, num2);
                break;
            case 3:
                printf("%d / %d = ", num1, num2);
                break;
        }

        scanf("%d", &result);

        if (result == (num1 % num2)) {
            printf("Correct! You're a math whiz!\n");
        } else {
            printf("Incorrect. The correct answer is %d.\n", num1 % num2);
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &repeat);
    }

    return 0;
}