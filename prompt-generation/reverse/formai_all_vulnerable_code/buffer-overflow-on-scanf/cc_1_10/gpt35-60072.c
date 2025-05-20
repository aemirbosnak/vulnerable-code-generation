//FormAI DATASET v1.0 Category: Math exercise ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OPERATIONS 10
#define MIN_NUMBER 1
#define MAX_NUMBER 20

int generateNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL)); // initialize random seed

    int operationCount = generateNumber(1, MAX_OPERATIONS);
    int correctAnswers = 0;

    printf("Welcome to the math exercise program!\n\n");
    printf("You will be presented with %d math problems.\n", operationCount);
    printf("Please input your answer for each problem.\n\n");

    for (int i = 1; i <= operationCount; i++) {
        int num1 = generateNumber(MIN_NUMBER, MAX_NUMBER);
        int num2 = generateNumber(MIN_NUMBER, MAX_NUMBER);
        int operation = generateNumber(1, 3);
        int result;

        printf("Problem %d: ", i);

        switch (operation) {
            case 1:
                printf("%d + %d = ", num1, num2);
                result = num1 + num2;
                break;
            case 2:
                printf("%d - %d = ", num1, num2);
                result = num1 - num2;
                break;
            case 3:
                printf("%d * %d = ", num1, num2);
                result = num1 * num2;
                break;
            default:
                printf("\n");
                continue;
        }

        int answer;
        scanf("%d", &answer);

        if (answer == result) {
            printf("Correct!\n\n");
            correctAnswers++;
        } else {
            printf("Incorrect. The correct answer is %d.\n\n", result);
        }
    }

    double score = ((double) correctAnswers / operationCount) * 100;

    printf("You got %d out of %d correct!\n", correctAnswers, operationCount);
    printf("Your score is %.2lf%%.\n", score);

    if (score >= 70) {
        printf("Congratulations, you passed the math exercise program!\n");
    } else {
        printf("Unfortunately, you did not pass the math exercise program. Please try again!\n");
    }

    return 0;
}