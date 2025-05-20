//FormAI DATASET v1.0 Category: Math exercise ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int max){
    srand(time(NULL));
    int randomNumber = rand() % max;
    return randomNumber;
}

int main(){
    int randomNumber = generateRandomNumber(100);
    int guess, attempts = 0;
    printf("Welcome to the guessing game!\n");
    printf("I have chosen a number between 0 and 100. Try to guess it!\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < randomNumber) {
            printf("Too low! Try again.\n");
        } else if (guess > randomNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }
    } while (guess != randomNumber);

    int num = 25;
    int numFactorial = 1;

    for(int i = 1; i <= num; ++i){
        numFactorial *= i;
    }

    int numSqrt = sqrt(num);

    printf("Factorial of %d is: %d\n", num, numFactorial);
    printf("Square root of %d is: %d\n", num, numSqrt);

    int num1 = generateRandomNumber(50);
    int num2 = generateRandomNumber(50);
    int sum = num1 + num2;
    int difference = abs(num1 - num2);
    int product = num1 * num2;
    int quotient = num1 / num2;
    int remainder = num1 % num2;

    printf("For numbers %d and %d:\n", num1, num2);
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);
    printf("Product: %d\n", product);
    printf("Quotient: %d\n", quotient);
    printf("Remainder: %d\n", remainder);

    return 0;
}