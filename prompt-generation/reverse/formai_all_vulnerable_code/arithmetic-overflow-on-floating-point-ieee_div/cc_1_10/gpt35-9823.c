//FormAI DATASET v1.0 Category: Math exercise ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    //Welcome message
    printf("Welcome to the Math Quiz!\n");
    printf("Today, you will be challenged to solve some math problems\n");
    printf("Are you ready? Enter Y or N\n");

    char response;
    scanf("%c", &response);

    if (response == 'Y' || response == 'y') {
        printf("Great! Let's Begin.\n");
    } else {
        printf("Too bad, let's begin anyway!\n");
    }

    //Generate random numbers
    srand(time(0));
    int num1 = rand() % 101;
    int num2 = rand() % 101;
    int num3 = rand() % 101;

    //Ask addition problem
    printf("What is %d + %d?\n", num1, num2);
    int answer1;
    scanf("%d", &answer1);

    if (answer1 == num1 + num2) {
        printf("Correct! You're a math wizard!\n");
    } else {
        printf("Sorry, wrong answer. The correct answer is %d\n", num1 + num2);
    }

    //Ask subtraction problem
    printf("What is %d - %d?\n", num2, num3);
    int answer2;
    scanf("%d", &answer2);

    if (answer2 == num2 - num3) {
        printf("Correct! You're a math genius!\n");
    } else {
        printf("Sorry, wrong answer. The correct answer is %d\n", num2 - num3);
    }

    //Ask multiplication problem
    printf("What is %d * %d?\n", num1, num3);
    int answer3;
    scanf("%d", &answer3);

    if (answer3 == num1 * num3) {
        printf("Correct! You're a math guru!\n");
    } else {
        printf("Sorry, wrong answer. The correct answer is %d\n", num1 * num3);
    }

    //Ask division problem
    printf("What is %d / %d?\n", num1, num2);

    float answer4;
    scanf("%f", &answer4);

    float correctAnswer = (float)num1 / (float)num2;
    float diff = fabs(answer4 - correctAnswer);

    if (diff < 0.01) {
        printf("Correct! You're a math prodigy!\n");
    } else {
        printf("Sorry, wrong answer. The correct answer is %.2f\n", correctAnswer);
    }

    printf("Thanks for playing the Math Quiz! Be sure to come back for more challenges!\n");
    return 0;
}