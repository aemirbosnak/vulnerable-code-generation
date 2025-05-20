//FormAI DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random arithmetic operation (+, -, *, /)
char generateOperation() {
    int num = rand() % 4;
    switch(num) {
        case 0:
            return '+';
        case 1:
            return '-';
        case 2:
            return '*';
        case 3:
            return '/';
    }
}

// Function to generate a random integer in a given range
int generateNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to calculate the result of a given arithmetic operation
int calculateResult(int num1, int num2, char operation) {
    switch(operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0;
    }
}

int main() {
    srand(time(NULL));
    int score = 0;
    int num1, num2, result, answer;
    char operation;
    for (int i = 1; i <= 10; i++) {
        num1 = generateNumber(1, 20);
        num2 = generateNumber(1, 20);
        operation = generateOperation();
        printf("Question %d: %d %c %d = ", i, num1, operation, num2);
        scanf("%d", &answer);
        result = calculateResult(num1, num2, operation);
        if (answer == result) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %d\n", result);
        }
    }
    printf("Your final score is %d/10\n", score);
    return 0;
}