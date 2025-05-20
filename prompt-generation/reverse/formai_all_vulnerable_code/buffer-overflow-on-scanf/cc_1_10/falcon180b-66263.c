//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function prototypes
int generateRandomNumber(int min, int max);
float calculateSquareRoot(float number);
float calculateCube(float number);
float calculateFactorial(int number);

int main() {
    srand(time(NULL)); // Seed the random number generator
    int choice;
    printf("Welcome to the Math Exercise Program!\n");
    printf("Please choose an option:\n");
    printf("1. Random Number Generator\n");
    printf("2. Square Root Calculator\n");
    printf("3. Cube Calculator\n");
    printf("4. Factorial Calculator\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            // Call generateRandomNumber function
            break;
        case 2:
            // Call calculateSquareRoot function
            break;
        case 3:
            // Call calculateCube function
            break;
        case 4:
            // Call calculateFactorial function
            break;
        default:
            printf("Invalid option selected.\n");
            break;
    }

    return 0;
}

int generateRandomNumber(int min, int max) {
    int randomNumber = rand() % (max - min + 1) + min;
    return randomNumber;
}

float calculateSquareRoot(float number) {
    float squareRoot = sqrt(number);
    return squareRoot;
}

float calculateCube(float number) {
    float cube = pow(number, 3);
    return cube;
}

float calculateFactorial(int number) {
    float factorial = 1;
    for(int i = 2; i <= number; i++) {
        factorial *= i;
    }
    return factorial;
}