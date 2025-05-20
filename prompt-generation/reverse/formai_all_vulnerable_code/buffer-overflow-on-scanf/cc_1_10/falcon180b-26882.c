//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 1000000 // maximum number of Fibonacci numbers to generate

// function to generate a random Fibonacci number
int generate_random_fibonacci_number(int a, int b) {
    int result = rand() % (b - a + 1) + a;
    return result;
}

// function to print the Fibonacci sequence
void print_fibonacci_sequence(int a, int b, int num_terms) {
    printf("Fibonacci sequence from %d to %d (%d terms):\n", a, b, num_terms);
    for (int i = 0; i < num_terms; i++) {
        int term = generate_random_fibonacci_number(a, b);
        printf("%d ", term);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // seed the random number generator with the current time

    int a, b, num_terms;
    printf("Enter the starting number (a): ");
    scanf("%d", &a);
    printf("Enter the ending number (b): ");
    scanf("%d", &b);
    printf("Enter the number of terms: ");
    scanf("%d", &num_terms);

    // check for invalid input
    if (a <= 0 || b <= 0 || num_terms <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    if (a > b) {
        printf("a must be less than or equal to b.\n");
        return 1;
    }

    if (num_terms > MAX_NUMBERS) {
        printf("Number of terms must be less than or equal to %d.\n", MAX_NUMBERS);
        return 1;
    }

    print_fibonacci_sequence(a, b, num_terms);

    return 0;
}