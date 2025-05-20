//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_FACTORIAL 12

// Function to calculate the nth Fibonacci number
long long fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1 || n == 2) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to clear the console
void clear() {
    system("clear");
}

// Function to print the Fibonacci sequence up to n terms
void print_fibonacci(int n) {
    int i;
    long long prev = 0, curr = 1;

    for (i = 1; i <= n; i++) {
        printf("%lld ", curr);
        long long temp = curr;
        curr += prev;
        prev = temp;
    }
}

// Function to print the factorial of a number
void print_factorial(int n) {
    printf("%d! = %d\n", n, factorial(n));
}

int main() {
    srand(time(NULL));
    int width = WIDTH, height = HEIGHT, max_factor = MAX_FACTORIAL;
    char c;

    clear();

    do {
        // Print header
        printf("FIBONACCI SEQUENCE VISUALIZER\n\n");
        printf("Width: %d\nHeight: %d\nMax Factor: %d\n", width, height, max_factor);
        printf("Press any key to continue...\n");

        // Get user input for sequence parameters
        scanf("%c", &c);

        // Validate input
        while (c!= '\n') {
            printf("Invalid input. Please enter a valid integer.\n");
            scanf("%c", &c);
        }

        // Update sequence parameters
        if (c == '\n') {
            printf("\nUpdating sequence parameters...\n");
            scanf("%d%c%d%c", &width, &c, &height, &c);
            scanf("%d%c", &max_factor, &c);
            clear();
        }

    } while (1);

    return 0;
}