//FormAI DATASET v1.0 Category: Math exercise ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x, y, z, answer, result, correct_answers = 0, incorrect_answers = 0;
    srand(time(NULL));

    printf("Welcome to the Math Game! Please select a difficulty level:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("Enter your choice: ");
    scanf("%d", &z);

    switch(z) {
        case 1:
            printf("You've selected Easy level!\n");
            for(int i = 0; i < 10; i++) {
                x = rand() % 11;
                y = rand() % 11;
                result = x + y;
                printf("%d + %d = ", x, y);
                scanf("%d", &answer);
                if(answer == result) {
                    printf("Correct!\n");
                    correct_answers++;
                } else {
                    printf("Incorrect! The answer is %d.\n", result);
                    incorrect_answers++;
                }
            }
            break;
        case 2:
            printf("You've selected Medium level!\n");
            for(int i = 0; i < 10; i++) {
                x = rand() % 21;
                y = rand() % 21;
                result = x - y;
                printf("%d - %d = ", x, y);
                scanf("%d", &answer);
                if(answer == result) {
                    printf("Correct!\n");
                    correct_answers++;
                } else {
                    printf("Incorrect! The answer is %d.\n", result);
                    incorrect_answers++;
                }
            }
            break;
        case 3:
            printf("You've selected Hard level!\n");
            for(int i = 0; i < 10; i++) {
                x = rand() % 101;
                y = rand() % 101;
                result = x * y;
                printf("%d * %d = ", x, y);
                scanf("%d", &answer);
                if(answer == result) {
                    printf("Correct!\n");
                    correct_answers++;
                } else {
                    printf("Incorrect! The answer is %d.\n", result);
                    incorrect_answers++;
                }
            }
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    printf("You've answered %d questions correctly and %d questions incorrectly.\n", correct_answers, incorrect_answers);
    printf("Thank you for playing the Math Game!\n");

    return 0;
}