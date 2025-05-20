//FormAI DATASET v1.0 Category: Math exercise ; Style: happy
#include <stdio.h>

int main() {
    printf("Welcome to the Happy Math Program!\n");
    printf("Let's start with something easy...\n");

    int num1 = 5;
    int num2 = 7;
    int sum = num1 + num2;

    printf("What is the sum of %d and %d? Enter your answer below:\n", num1, num2);

    int userAnswer;
    scanf("%d", &userAnswer);

    if (userAnswer == sum) {
        printf("Congratulations! You got it right!\n");
    } else {
        printf("Aww, that's not correct. The answer is %d. But don't worry, let's try another one!\n", sum);
    }

    printf("Now, let's move on to some multiplication!\n");

    int num3 = 4;
    int num4 = 6;
    int product = num3 * num4;

    printf("What is the product of %d and %d? Enter your answer below:\n", num3, num4);

    scanf("%d", &userAnswer);

    if (userAnswer == product) {
        printf("Yippee! You're on a roll!\n");
    } else {
        printf("Uh-oh, it looks like that answer is incorrect. The correct answer is %d.\n", product);
    }

    printf("Time for one final challenge!\n");

    int num5 = 10;
    double num6 = 3.5;
    double quotient = num5 / num6;

    printf("What is the quotient of %d divided by %.1f? Enter your answer below:\n", num5, num6);

    double userDoubleAnswer;
    scanf("%lf", &userDoubleAnswer);

    if (userDoubleAnswer == quotient) {
        printf("Hooray! You're a math wizard!\n");
    } else {
        printf("Oh no, looks like you need a bit more practice. The answer is %.2f.\n", quotient);
    }

    printf("Thanks for participating in the Happy Math Program!\n");

    return 0;
}