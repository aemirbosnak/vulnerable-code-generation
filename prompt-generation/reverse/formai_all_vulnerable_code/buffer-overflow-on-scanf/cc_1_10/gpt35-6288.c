//FormAI DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, c, d;
    char operator1, operator2, operator3;
    srand(time(NULL));
    a = (rand() % 100) + 1;
    b = (rand() % 100) + 1;
    c = (rand() % 100) + 1;
    d = (rand() % 100) + 1;

    if (a % 2 == 0) {
        operator1 = '+';
    } else {
        operator1 = '-';
    }

    if (b % 2 == 0) {
        operator2 = '+';
    } else {
        operator2 = '-';
    }

    if (c % 2 == 0) {
        operator3 = '+';
    } else {
        operator3 = '-';
    }

    printf("What is the result of the following equation:\n");
    printf("%d %c %d %c %d %c %d\n", a, operator1, b, operator2, c, operator3, d);

    // Calculate the answer
    int answer;
    if (operator1 == '+') {
        answer = a + b;
    } else {
        answer = a - b;
    }
    if (operator2 == '+') {
        answer += c;
    } else {
        answer -= c;
    }
    if (operator3 == '+') {
        answer += d;
    } else {
        answer -= d;
    }

    // Get user input and check answer
    int userAnswer;
    printf("Enter your answer: ");
    scanf("%d", &userAnswer);
    if (userAnswer == answer) {
        printf("Correct, congratulations!\n");
    } else {
        printf("Incorrect, the answer is %d\n", answer);
    }
    return 0;
}