//FormAI DATASET v1.0 Category: Math exercise ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int num1, num2, result, answer;
    char operator;

    srand(time(NULL));

    printf("Welcome to the Math Exercise Program!\n\n");

    for(int i = 1; i <= 10; i++) {
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;
        operator = rand() % 4;

        switch(operator) {
            case 0:
                printf("%d + %d = ", num1, num2);
                result = num1 + num2;
                break;
            case 1:
                printf("%d - %d = ", num1, num2);
                result = num1 - num2;
                break;
            case 2:
                printf("%d * %d = ", num1, num2);
                result = num1 * num2;
                break;
            case 3:
                printf("%d / %d = ", num1, num2);
                result = num1 / num2;
                break;
            default:
                printf("Invalid operator\n");
                exit(1);
        }

        scanf("%d", &answer);

        if(answer == result) {
            printf("Correct!\n\n");
        } else {
            printf("Incorrect. The answer is %d.\n\n", result);
        }
    }

    printf("Congratulations! You have completed all the exercises.\n");

    return 0;
}