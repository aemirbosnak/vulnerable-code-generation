//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 100000

// Function to generate the Fibonacci sequence up to n terms
void generate_fibonacci(int n) {
    int first = 0, second = 1, next = 0;

    printf("Generating Fibonacci sequence up to %d terms...\n", n);
    srand(time(NULL)); // Seed the random number generator with the current time

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d ", first);
        } else if (i == 1) {
            printf("%d ", second);
        } else {
            next = first + second;
            first = second;
            second = next;
            printf("%d ", next);
        }
    }

    printf("\n");
}

// Function to display the Fibonacci sequence in a visual way
void visualize_fibonacci(int n) {
    int first = 0, second = 1, next = 0;

    printf("Visualizing Fibonacci sequence up to %d terms...\n", n);

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("Fibonacci sequence:\n\t%d\n", first);
        } else if (i == 1) {
            printf("\t%d", second);
        } else {
            next = first + second;
            first = second;
            second = next;
            printf("\n\t%d", next);
        }
    }

    printf("\n");
}

int main() {
    int choice, n;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n\n");
    printf("Please choose an option:\n");
    printf("1. Generate Fibonacci sequence\n");
    printf("2. Visualize Fibonacci sequence\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the number of terms to generate: ");
            scanf("%d", &n);

            if (n > MAX_TERMS) {
                printf("Sorry, the maximum number of terms is %d.\n", MAX_TERMS);
            } else {
                generate_fibonacci(n);
            }
            break;

        case 2:
            printf("Enter the number of terms to visualize: ");
            scanf("%d", &n);

            if (n > MAX_TERMS) {
                printf("Sorry, the maximum number of terms is %d.\n", MAX_TERMS);
            } else {
                visualize_fibonacci(n);
            }
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}