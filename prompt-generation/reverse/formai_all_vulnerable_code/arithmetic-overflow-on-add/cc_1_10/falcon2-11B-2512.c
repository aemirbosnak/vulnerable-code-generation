//Falcon2-11B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 20
#define HEIGHT 10

// Function to print the Fibonacci sequence as ASCII art
void printFibonacci() {
    int i;
    for (i = 1; i <= 50; i++) {
        if (i <= 5) {
            printf("%c", '*' + i);
        } else if (i % 3 == 0) {
            printf(" _ ");
        } else if (i % 5 == 0) {
            printf(" \\ ");
        } else {
            printf(" | ");
        }
    }
    printf("\n");
}

int main() {
    srand(time(0));

    // Generate random numbers for the first two Fibonacci numbers
    int firstNum = 1 + rand() % 10;
    int secondNum = 1 + rand() % 10;

    // Print the first two Fibonacci numbers as ASCII art
    printf("First two Fibonacci numbers: %d, %d\n", firstNum, secondNum);
    printf("-------------------------\n");
    printFibonacci();

    // Generate the rest of the Fibonacci sequence
    int nextNum;
    for (int i = 2; i < 50; i++) {
        nextNum = firstNum + secondNum;
        firstNum = secondNum;
        secondNum = nextNum;

        printf("Next Fibonacci number: %d\n", nextNum);
        printf("-------------------------\n");
        printFibonacci();
    }

    return 0;
}