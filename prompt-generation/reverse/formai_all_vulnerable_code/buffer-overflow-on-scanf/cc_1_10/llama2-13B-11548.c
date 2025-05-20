//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

void calculate_pi(void);
double calculate_fibonacci(int n);

int main() {
    int i, j, k;
    double result;

    // Initialize variables
    for (i = 0; i < 10; i++) {
        srand(time(NULL));
        j = rand() % 2;
        k = (i % 2) == j;
        if (k) {
            printf("Odd %d\n", i);
        } else {
            printf("Even %d\n", i);
        }
    }

    // Calculate pi
    calculate_pi();

    // Calculate Fibonacci sequence
    result = calculate_fibonacci(5);
    printf("Fibonacci of 5: %f\n", result);

    // Play a game of rock-paper-scissors
    for (i = 0; i < 10; i++) {
        printf("Please enter your choice (rock, paper, or scissors): ");
        scanf("%c", &j);
        if (j == 'r' || j == 'R') {
            if (rand() % 2 == 0) {
                printf("You lose! I chose rock too :(\n");
            } else {
                printf("You win! I chose paper :)\n");
            }
        } else if (j == 'p' || j == 'P') {
            if (rand() % 2 == 0) {
                printf("You lose! I chose paper too :(\n");
            } else {
                printf("You win! I chose rock :)\n");
            }
        } else if (j == 's' || j == 'S') {
            if (rand() % 2 == 0) {
                printf("You lose! I chose scissors too :(\n");
            } else {
                printf("You win! I chose rock :)\n");
            }
        }
    }

    // Print the famous last words of famous mathematicians
    printf("Famous last words of famous mathematicians:\n");
    printf("- Archimedes: 'Don't disturb my circles!'\n");
    printf("- Isaac Newton: 'I can calculate the motion of celestial bodies, but I cannot calculate the motion of the human heart.'\n");
    printf("- Albert Einstein: 'The only thing that interferes with my learning is my education.'\n");
    printf("- Stephen Hawking: 'The greatest glory in living lies not in never falling, but in rising every time we fall.'\n");

    return 0;
}

void calculate_pi(void) {
    double result = 0;
    int i, j;

    // Calculate pi using the Gregory-Leibniz series
    for (i = 0; i < 100; i++) {
        result += (double)i / (double)i;
    }
    result = 4 * result;

    // Print the result
    printf("Pi approximation: %f\n", result);
}

double calculate_fibonacci(int n) {
    double result = 0;
    int i, j;

    // Calculate Fibonacci sequence using the recurrence relation
    if (n == 0) {
        result = 0;
    } else if (n == 1) {
        result = 1;
    } else {
        for (i = 0; i < n; i++) {
            result += (double)i / (double)i;
        }
        result = result / (double)i;
    }

    // Print the result
    printf("Fibonacci of %d: %f\n", n, result);

    return result;
}