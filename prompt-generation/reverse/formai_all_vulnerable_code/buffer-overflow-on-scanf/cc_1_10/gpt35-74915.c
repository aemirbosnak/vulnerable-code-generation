//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: modular
#include <stdio.h>

// Function to calculate Fibonacci sequence
int fibonacci(int n) {

    // Check for base cases
    if(n == 0) return 0;
    else if(n == 1) return 1;

    // Recursive call to calculate smaller sub-problems
    return fibonacci(n-1) + fibonacci(n-2);
}

// Function to print Fibonacci sequence up to a given index
void print_fibonacci_sequence(int n) {
    int i, fib_num;

    for(i=0; i<=n; i++) {
        fib_num = fibonacci(i);
        printf("%d ", fib_num);
    }
    printf("\n");
}

// Function to draw a horizontal line
void draw_horizontal_line(int length) {
    int i;
    for(i=0; i<length; i++) {
        printf("-");
    }
    printf("\n");
}

// Function to print Fibonacci sequence in graphical form
void print_fibonacci_sequence_graphical(int n) {
    int i, j, fib_num;

    for(i=0; i<=n; i++) {
        fib_num = fibonacci(i);

        // Draw a line representing the current Fibonacci number
        draw_horizontal_line(fib_num);

        // Print the Fibonacci number itself
        printf("%d\n", fib_num);
    }
}

// Main function to run the program
int main() {
    int n;

    printf("Enter the number of Fibonacci numbers to calculate: ");
    scanf("%d", &n);

    // Print the Fibonacci sequence as text
    printf("Fibonacci sequence:\n");
    print_fibonacci_sequence(n);

    // Print the Fibonacci sequence graphically
    printf("Graphical Fibonacci sequence:\n");
    print_fibonacci_sequence_graphical(n);

    return 0;
}