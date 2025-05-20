//FormAI DATASET v1.0 Category: Math exercise ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int generateRandomNumber(int limit) {
    srand(time(NULL));
    return (rand() % limit) + 1;
}

int main() {
    int num1, num2, result, answer;
    char operator;

    // Generate two random numbers between 1 and 10
    num1 = generateRandomNumber(10);
    num2 = generateRandomNumber(10);

    // Generate a random operator (+, -, *, /)
    int operatorIndex = generateRandomNumber(4);
    switch (operatorIndex) {
        case 1:
            operator = '+';
            result = num1 + num2;
            break;
        case 2:
            operator = '-';
            result = num1 - num2;
            break;
        case 3:
            operator = '*';
            result = num1 * num2;
            break;
        case 4:
            operator = '/';
            result = num1 / num2;
            break;
    }

    printf("What is %d %c %d?\n", num1, operator, num2);
    scanf("%d", &answer);

    if (answer == result) {
        printf("Congratulation! You are correct.\n");
    } else {
        printf("Sorry, the correct answer is %d.\n", result);
    }

    return 0;
}