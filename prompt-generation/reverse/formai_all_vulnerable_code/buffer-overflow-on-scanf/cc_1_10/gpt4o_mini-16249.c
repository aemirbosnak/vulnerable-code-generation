//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void clearScreen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void printFibonacci(int n) {
    long long first = 0, second = 1, next;
    
    printf("Generating Fibonacci sequence:\n");
    for(int i = 0; i < n; i++) {
        if(i <= 1) {
            next = i; // first two Fibonacci numbers
        } else {
            next = first + second; // calculate the next number in the sequence
            first = second; // shifting values to next pair
            second = next;
        }

        // Visualize the numbers
        printf("%lld ", next);
        fflush(stdout); // Flush the output buffer
        for(int j = 0; j < next % 10; j++) { // Modulo for visual effect
            printf("*");
            fflush(stdout);
            sleep(1); // Pause for a second to create animation effect
        }
        printf("\n");
        sleep(1); // Pause before moving to the next number
    }
    printf("\nFibonacci sequence generation complete!\n");
}

int main() {
    int num;

    clearScreen(); // Clear the screen for fresh start

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of Fibonacci terms you wish to generate: ");
    scanf("%d", &num);

    if(num < 0) {
        printf("Please enter a non-negative number.\n");
        return 1;
    }

    printFibonacci(num);

    return 0;
}