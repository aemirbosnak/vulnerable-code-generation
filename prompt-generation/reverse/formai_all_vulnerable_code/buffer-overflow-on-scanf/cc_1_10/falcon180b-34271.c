//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUM 1000000
#define MAX_OP 1000000

int main() {
    srand(time(NULL));
    int num1, num2, operator, result;
    char operation[MAX_OP];

    printf("Welcome to the Arithmetic Game!\n");
    printf("You will be given an arithmetic problem to solve.\n");
    printf("Enter the correct answer within 5 seconds.\n");
    printf("Score 1 point for each correct answer.\n\n");

    int score = 0;
    int max_score = MAX_NUM * 2;

    while (score < max_score) {
        num1 = rand() % MAX_NUM + 1;
        num2 = rand() % MAX_NUM + 1;
        operator = rand() % 4;

        switch (operator) {
            case 0:
                result = num1 + num2;
                sprintf(operation, "%d + %d = ", num1, num2);
                break;
            case 1:
                result = num1 - num2;
                sprintf(operation, "%d - %d = ", num1, num2);
                break;
            case 2:
                result = num1 * num2;
                sprintf(operation, "%d * %d = ", num1, num2);
                break;
            case 3:
                if (num2 == 0) {
                    num2 = rand() % MAX_NUM + 1;
                }
                result = num1 / num2;
                sprintf(operation, "%d / %d = ", num1, num2);
                break;
        }

        printf("%s\n", operation);
        fflush(stdout);

        int input;
        scanf("%d", &input);

        if (input == result) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", result);
        }

        fflush(stdout);
        usleep(100000);
    }

    printf("Congratulations! You scored %d points out of %d.\n", score, max_score);

    return 0;
}