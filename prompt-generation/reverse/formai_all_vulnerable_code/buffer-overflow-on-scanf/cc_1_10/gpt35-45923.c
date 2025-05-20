//FormAI DATASET v1.0 Category: Math exercise ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Math Exercise Program!\n");

    // Seed the random number generator
    srand(time(NULL));

    int num1 = rand() % 100 + 1;  // Generate a random number between 1 and 100
    int num2 = rand() % 100 + 1;  // Generate another random number between 1 and 100
    int answer1, answer2, answer3;  // Declare variables to hold user input for each question

    printf("\nLet's start with an addition problem:\n");
    printf("%d + %d = ", num1, num2);
    scanf("%d", &answer1);

    if (answer1 == num1 + num2) {
        printf("Great job! You got it right!\n");
    } else {
        printf("Oops, %d + %d is actually %d.\n", num1, num2, num1 + num2);
    }

    num1 = rand() % 100 + 1;  // Generate two new random numbers for the next problem
    num2 = rand() % 100 + 1;

    printf("\nNow let's try a subtraction problem:\n");
    printf("%d - %d = ", num1, num2);
    scanf("%d", &answer2);

    if (answer2 == num1 - num2) {
        printf("Awesome! You got it right!\n");
    } else {
        printf("Oh no, %d - %d is actually %d.\n", num1, num2, num1 - num2);
    }

    num1 = rand() % 10 + 1;  // Generate two smaller numbers for multiplication
    num2 = rand() % 10 + 1;

    printf("\nTime for a multiplication problem:\n");
    printf("%d * %d = ", num1, num2);
    scanf("%d", &answer3);

    if (answer3 == num1 * num2) {
        printf("Excellent! You got it right!\n");
    } else {
        printf("Uh oh, %d * %d is actually %d.\n", num1, num2, num1 * num2);
    }

    printf("\nThanks for using the Math Exercise Program! Keep practicing to improve your math skills.\n");

    return 0;
}