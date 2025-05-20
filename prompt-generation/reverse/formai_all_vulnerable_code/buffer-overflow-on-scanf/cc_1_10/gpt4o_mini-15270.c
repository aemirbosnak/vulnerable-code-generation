//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function
#include <stdbool.h>

void draw_fibonacci(int n) {
    int a = 0, b = 1, next;
    printf("\nFibonacci sequence visualizer for the first %d terms:\n", n);
    printf("Index: ");
    for(int i = 0; i < n; i++) {
        printf("%-4d ", i);
    }
    printf("\nValue: ");
    for(int i = 0; i < n; i++) {
        if (i <= 1)
            next = i; // The 0th and 1st Fibonacci numbers are 0 and 1
        else {
            next = a + b; // Calculate next Fibonacci number
            a = b; 
            b = next;
        }
        printf("%-4d ", next);
        fflush(stdout); // Ensure the output is displayed immediately
        usleep(300000); // Wait 300ms before the next iteration
    }
    printf("\n\nExplore the beauty of numbers, one at a time!\n");
}

bool is_even(int num) {
    return num % 2 == 0;
}

void draw_even_indices_fibonacci(int n) {
    int a = 0, b = 1, next;
    
    printf("\nEven-indexed Fibonacci Numbers:\n");
    for(int i = 0; i < n; i++) {
        if (i <= 1)
            next = i;
        else {
            next = a + b; 
            a = b; 
            b = next;
        }
        if (is_even(i)) {
            printf("Index %d: %d\n", i, next);
        }
    }
}

void draw_star_pattern(int num) {
    printf("\nStar Pattern for Fibonacci values:\n");
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        printf("*\n");
        fflush(stdout);
        usleep(500000); // Wait 500ms for visual effect
    }
}

int main() {
    int n;

    printf("Welcome to Fibonacci Sequence Visualizer!\n");
    printf("Please enter the number of terms you want to visualize (e.g., 10): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The number of terms must be greater than zero!\n");
        return 1;
    }

    draw_fibonacci(n);
    draw_even_indices_fibonacci(n);
    draw_star_pattern(n);

    printf("Thank you for exploring Fibonacci numbers with us!\n");
    return 0;
}