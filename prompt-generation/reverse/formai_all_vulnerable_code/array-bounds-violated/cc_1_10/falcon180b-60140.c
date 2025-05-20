//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_NUMBERS 100

// Function to generate Fibonacci sequence up to n terms
void generate_fibonacci(int n) {
    int fib_sequence[n];
    fib_sequence[0] = 0;
    fib_sequence[1] = 1;

    for (int i = 2; i < n; i++) {
        fib_sequence[i] = fib_sequence[i - 1] + fib_sequence[i - 2];
    }
}

// Function to print the Fibonacci sequence in a formatted manner
void print_fibonacci(int fib_sequence[], int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fib_sequence[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}

// Function to clear the console screen
void clear_screen() {
    system("clear");
}

// Function to get user input for number of terms in Fibonacci sequence
int get_user_input() {
    int n;

    do {
        printf("Enter the number of terms in the Fibonacci sequence: ");
        scanf("%d", &n);

        if (n <= 0 || n > MAX_NUMBERS) {
            printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_NUMBERS);
        }
    } while (n <= 0 || n > MAX_NUMBERS);

    return n;
}

int main() {
    srand(time(NULL));

    int n = get_user_input();
    int fib_sequence[n];

    generate_fibonacci(n);
    print_fibonacci(fib_sequence, n);

    return 0;
}