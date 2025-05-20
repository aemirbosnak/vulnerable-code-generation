//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MIN_VALUE 1e-10
#define MAX_VALUE 1e10

int main() {
    int numOfQuestions = 10;
    int currentQuestion = 0;
    double score = 0;
    double totalScore = 0;
    char answer;

    // Generate random numbers for the math exercises
    srand(time(NULL));
    for (int i = 0; i < numOfQuestions; i++) {
        int num1 = (int)((double)rand() / RAND_MAX * (MAX_VALUE - MIN_VALUE)) + MIN_VALUE;
        int num2 = (int)((double)rand() / RAND_MAX * (MAX_VALUE - MIN_VALUE)) + MIN_VALUE;
        int op = (int)((double)rand() / RAND_MAX * 4) % 4;
        double result = 0;

        switch (op) {
            case 0: // +
                result = num1 + num2;
                break;
            case 1: // -
                result = num1 - num2;
                break;
            case 2: // *
                result = num1 * num2;
                break;
            case 3: // /
                result = num1 / num2;
                break;
        }

        // Print the math exercise
        printf("Question %d: %d %c %d = %lf\n", i + 1, num1, (char)op, num2, result);

        // Get the user's answer
        printf("Enter your answer: ");
        scanf("%lf", &answer);

        // Check if the user's answer is correct
        if (fabs(result - answer) < MIN_VALUE) {
            score++;
            totalScore += result;
        } else {
            printf("Incorrect. The correct answer is %lf\n", result);
        }
    }

    // Print the results
    printf("You scored %d out of %d questions correct\n", score, numOfQuestions);
    printf("Your total score is %lf\n", totalScore);

    return 0;
}