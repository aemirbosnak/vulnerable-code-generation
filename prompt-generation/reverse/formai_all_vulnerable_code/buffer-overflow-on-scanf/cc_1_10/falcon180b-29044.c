//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num1, num2, operation;
    printf("Welcome to the Happy Math Adventure!\n");
    printf("Let's start with some addition.\n");
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;
    printf("What is %d + %d?\n", num1, num2);
    scanf("%d", &operation);
    if (operation == num1 + num2) {
        printf("Correct! You're a math superstar!\n");
    } else {
        printf("Sorry, that's incorrect. The answer is %d.\n", num1 + num2);
    }

    printf("\nNow let's try some subtraction.\n");
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;
    printf("What is %d - %d?\n", num1, num2);
    scanf("%d", &operation);
    if (operation == num1 - num2) {
        printf("Correct! You're on a roll!\n");
    } else {
        printf("Sorry, that's incorrect. The answer is %d.\n", num1 - num2);
    }

    printf("\nLet's mix it up with some multiplication.\n");
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;
    printf("What is %d x %d?\n", num1, num2);
    scanf("%d", &operation);
    if (operation == num1 * num2) {
        printf("Correct! You're a math whiz!\n");
    } else {
        printf("Sorry, that's incorrect. The answer is %d.\n", num1 * num2);
    }

    printf("\nFinally, let's end with some division.\n");
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;
    printf("What is %d / %d?\n", num1, num2);
    scanf("%d", &operation);
    if (operation == num1 / num2) {
        printf("Correct! You're a math genius!\n");
    } else {
        printf("Sorry, that's incorrect. The answer is %.2f.\n", (float)num1 / num2);
    }

    return 0;
}