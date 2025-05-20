//FormAI DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random integer between min and max (inclusive)
int generateRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int num1, num2, answer, userInput;
    char operation;
    int score = 0;
    srand(time(0));
    for (int i = 1; i <= 10; i++) {
        num1 = generateRandomInt(1, 100);
        num2 = generateRandomInt(1, 100);
        // randomly choose whether to add, subtract, multiply or divide
        switch (generateRandomInt(1, 4)) {
            case 1:
                operation = '+';
                answer = num1 + num2;
                break;
            case 2:
                operation = '-';
                answer = num1 - num2;
                break;
            case 3:
                operation = '*';
                answer = num1 * num2;
                break;
            case 4:
                operation = '/';
                answer = num1 / num2; // integer division
                break;
        }
        printf("Question %d: What is %d %c %d?\n", i, num1, operation, num2);
        scanf("%d", &userInput);
        if (userInput == answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Sorry, the correct answer is %d.\n", answer);
        }
    }
    printf("Your final score is %d out of 10.\n", score);
    if (score >= 8) {
        printf("Excellent job!\n");
    } else if (score >= 6) {
        printf("Good job.\n");
    } else {
        printf("Better luck next time.\n");
    }
    return 0;
}