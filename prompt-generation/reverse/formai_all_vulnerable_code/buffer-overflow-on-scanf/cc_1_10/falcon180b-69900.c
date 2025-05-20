//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 1000000

// Function to generate Fibonacci sequence
void generateFibonacciSequence() {
    int firstNumber = 0, secondNumber = 1, nextNumber = 0, count = 0;

    printf("Enter the number of Fibonacci numbers you want to generate: ");
    scanf("%d", &count);

    if(count <= 0 || count > MAX_NUMBERS) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_NUMBERS);
        return;
    }

    printf("Fibonacci Sequence:\n");
    printf("0 ");
    printf("1 ");

    while(count > 2) {
        nextNumber = firstNumber + secondNumber;
        printf("%d ", nextNumber);
        firstNumber = secondNumber;
        secondNumber = nextNumber;
        count--;
    }
}

int main() {
    srand(time(NULL));

    int choice;

    do {
        printf("\n1. Generate Fibonacci sequence\n2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                generateFibonacciSequence();
                break;
            case 2:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 2);

    return 0;
}