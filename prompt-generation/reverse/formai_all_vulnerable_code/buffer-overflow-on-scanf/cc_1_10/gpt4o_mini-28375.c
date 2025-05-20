//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void print_fibonacci(int n);
void visualize_fibonacci(int n);
void draw_graph(int value, int max_value);

int main() {
    int number_of_terms;

    printf("Enter the number of terms for the Fibonacci sequence: ");
    scanf("%d", &number_of_terms);

    if (number_of_terms <= 0) {
        printf("Please enter a positive integer greater than zero.\n");
        return 1;
    }

    printf("\nFibonacci Sequence:\n");
    print_fibonacci(number_of_terms);
    printf("\nFibonacci Visualization:\n");
    visualize_fibonacci(number_of_terms);

    return 0;
}

void print_fibonacci(int n) {
    unsigned long long int first = 0, second = 1, next;

    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i; // First two Fibonacci numbers are 0 and 1
        } else {
            next = first + second; // Fibonacci equation F(n) = F(n-1) + F(n-2)
            first = second; // Update first number
            second = next; // Update second number
        }
        printf("%llu ", next);
    }
    printf("\n");
}

void visualize_fibonacci(int n) {
    unsigned long long int first = 0, second = 1, next;
    unsigned long long int max_value = 0;

    // Determine the maximum value for scaling the graph
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        if (next > max_value) {
            max_value = next; // Keep track of the largest Fibonacci number
        }
    }

    // Reset for printing the actual graph
    first = 0;
    second = 1;
    printf("\nGraphical Representation:\n");

    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        draw_graph(next, max_value);
    }
}

void draw_graph(int value, int max_value) {
    int length = 70; // Length of the graph line
    int scaled_value = (int)((double)value / max_value * length);

    // Print the scaled value graphically
    printf("%3d | ", value);
    for (int i = 0; i < scaled_value; i++) {
        printf("#");
    }
    printf("\n");
}