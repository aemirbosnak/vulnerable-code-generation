//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TERMS 30
#define SECRET_KEY 999  // A paranoid way to terminate the program

// Function to calculate the Fibonacci sequence.
void calculate_fibonacci(int terms, unsigned long long fib_sequence[]) {
    fib_sequence[0] = 0;
    fib_sequence[1] = 1;
    for (int i = 2; i < terms; i++) {
        fib_sequence[i] = fib_sequence[i - 1] + fib_sequence[i - 2];
    }
}

// Function to visualize the Fibonacci sequence.
void visualize_fibonacci(int terms, unsigned long long fib_sequence[]) {
    printf("\nFibonacci Sequence Visualization:\n");
    printf("----------------------------------\n");
    for (int i = 0; i < terms; i++) {
        printf("F(%d) = %llu\n", i, fib_sequence[i]);
    }
    printf("----------------------------------\n");
}

// Function to prompt for user input with paranoia checks.
bool prompt_for_terms(int *terms) {
    int input;
    printf("How many terms of Fibonacci sequence would you like to see? (Max %d): ", MAX_TERMS);
    
    int count = 0;
    while (true) {
        if (count > 0) {
            printf("Invalid input, please enter a number between 1 and %d or %d to quit: ", MAX_TERMS, SECRET_KEY);
        }
        int result = scanf("%d", &input);
        if (result != 1) {
            // Clear the bad input and reset input buffer.
            while (getchar() != '\n');
            count++;
            continue;
        }

        if (input == SECRET_KEY) {
            printf("Exiting paranoia mode. Stay safe!\n");
            return false;  // Exit when the secret key is input
        }

        if (input > 0 && input <= MAX_TERMS) {
            *terms = input;
            return true;
        } else {
            count++;
        }
    }
}

int main() {
    int terms = 0;
    unsigned long long fib_sequence[MAX_TERMS];

    // The paranoid loop continues until the user chooses to exit.
    while (prompt_for_terms(&terms)) {
        calculate_fibonacci(terms, fib_sequence);
        visualize_fibonacci(terms, fib_sequence);

        printf("Do you want to continue? (yes/no): ");
        char response[4];
        scanf("%s", response);
        
        // Checking for response validity
        if (response[0] != 'y' && response[0] != 'Y') {
            printf("Exiting paranoia mode. Don't let your guard down!\n");
            break;
        }
    }

    printf("Take care and stay vigilant!\n");
    return 0;
}