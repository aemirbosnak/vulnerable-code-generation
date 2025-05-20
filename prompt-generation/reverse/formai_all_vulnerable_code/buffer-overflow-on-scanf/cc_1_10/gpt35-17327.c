//FormAI DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// function for generating random number
int generateRandomNumber(int min, int max) {
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

// function for calculating factorial of a number
int calculateFactorial(int num) {
    int fact = 1;
    for(int i=1; i<=num; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    srand(time(NULL)); // seed for random number generator

    // generate two random numbers between 1 and 10
    int num1 = generateRandomNumber(1, 10);
    int num2 = generateRandomNumber(1, 10);

    // calculate the sum, difference and product of the two numbers
    int sum = num1 + num2;
    int diff = abs(num1 - num2);
    int prod = num1 * num2;

    // calculate the square root of the sum
    double sqrtSum = sqrt(sum);

    // calculate the factorial of the smaller number
    int fact = calculateFactorial((num1 < num2) ? num1 : num2);

    // print the question and ask for the answer
    printf("What is the result of (%d + %d)^(1/2) * (%d! / %d)?\n", num1, num2, (num1 < num2) ? num1 : num2, diff);
    int answer;
    scanf("%d", &answer);

    // calculate the correct answer
    double correctAnswer = sqrtSum * fact / diff;

    // check if the answer is correct and print the result
    if(answer == (int)correctAnswer) {
        printf("Congratulations! Your answer is correct.\n");
    } else {
        printf("Oops! Your answer is incorrect. The correct answer is %d.\n", (int)correctAnswer);
    }

    return 0;
}