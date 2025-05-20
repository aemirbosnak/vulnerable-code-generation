//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_fibonacci_sequence(int n);
void visualize_fibonacci(int n);
void delay(unsigned int seconds);

int main() {
    int terms;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of terms you want to see (greater than 0): ");
    scanf("%d", &terms);

    if (terms <= 0) {
        printf("Please enter a valid number of terms.\n");
        return -1;
    }

    print_fibonacci_sequence(terms);
    visualize_fibonacci(terms);

    return 0;
}

void print_fibonacci_sequence(int n) {
    long long a = 0, b = 1, temp;

    printf("\nThe first %d terms of the Fibonacci sequence are:\n", n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%lld ", a);
        } else if (i == 1) {
            printf("%lld ", b);
        } else {
            temp = a + b;
            a = b;
            b = temp;
            printf("%lld ", b);
        }
    }
    printf("\n");
}

void visualize_fibonacci(int n) {
    long long a = 0, b = 1, temp;
    int i;

    printf("\nVisualizing the first %d terms of the Fibonacci sequence:\n", n);
    for (i = 0; i < n; i++) {
        if (i == 0) {
            printf("Term %d: ", i);
            for (int j = 0; j < a; j++) {
                printf("X");
            }
            printf(" (0)\n");
        } else if (i == 1) {
            printf("Term %d: ", i);
            for (int j = 0; j < b; j++) {
                printf("X");
            }
            printf(" (1)\n");
        } else {
            temp = a + b;
            a = b;
            b = temp;

            printf("Term %d: ", i);
            for (int j = 0; j < b; j++) {
                printf("X");
            }
            printf(" (%lld)\n", b);
        }
        delay(1); // Wait for 1 second between visualizations
    }
}

void delay(unsigned int seconds) {
    unsigned int ret_time = time(0) + seconds; // Get the current time + seconds to wait
    while (time(0) < ret_time); // Wait until the time is met
}