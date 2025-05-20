//FormAI DATASET v1.0 Category: Math exercise ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, choice, correct = 0, incorrect = 0, difficulty, num1, num2, answer, correctAnswer;
    srand(time(NULL));

    // Introduction
    printf("Welcome to the post-apocalyptic math exercise program!\n");
    printf("Answer the following questions correctly to survive the dangerous wasteland.\n");

    // Difficulty selection
    printf("Choose your difficulty level:\n");
    printf("1 - Easy (numbers 1-10)\n");
    printf("2 - Medium (numbers 1-50)\n");
    printf("3 - Hard (numbers 1-100)\n");
    scanf("%d", &difficulty);

    // Generating math exercises and checking answers
    for (i = 0; i < 10; i++) {
        switch (difficulty) {
            case 1: // Easy difficulty
                num1 = rand() % 10 + 1;
                num2 = rand() % 10 + 1;
                correctAnswer = num1 + num2;
                printf("%d) What is %d + %d?\n", i+1, num1, num2);
                break;
            case 2: // Medium difficulty
                num1 = rand() % 50 + 1;
                num2 = rand() % 50 + 1;
                if (num1 >= num2) {
                    correctAnswer = num1 - num2;
                    printf("%d) What is %d - %d?\n", i+1, num1, num2);
                } else {
                    correctAnswer = num1 * num2;
                    printf("%d) What is %d * %d?\n", i+1, num1, num2);
                }
                break;
            case 3: // Hard difficulty
                num1 = rand() % 100 + 1;
                num2 = rand() % 100 + 1;
                if (num1 % num2 == 0) {
                    correctAnswer = num1 / num2;
                    printf("%d) What is %d / %d?\n", i+1, num1, num2);
                } else {
                    correctAnswer = num1 % num2;
                    printf("%d) What is %d %% %d?\n", i+1, num1, num2);
                }
                break;
            default:
                printf("Invalid difficulty level selected.\n");
                exit(0);
        }
        scanf("%d", &answer);
        if (answer == correctAnswer) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect, correct answer is %d.\n", correctAnswer);
            incorrect++;
        }
    }

    // Results
    printf("You answered %d questions correctly and %d questions incorrectly.\n", correct, incorrect);
    if (correct >= 7) {
        printf("You have survived the wasteland and are now a true post-apocalyptic math warrior!\n");
    } else {
        printf("You have not answered enough questions correctly to survive the wasteland. Good luck.\n");
    }

    return 0;
}