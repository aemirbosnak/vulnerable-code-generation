//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 1000

int main() {
    int num_terms, i, choice;
    int fibonacci_series[MAX_TERMS];

    printf("Enter the number of terms you want to generate: ");
    scanf("%d", &num_terms);

    for (i = 0; i < num_terms; i++) {
        fibonacci_series[i] = (i == 0)? 0 : (i == 1)? 1 : fibonacci_series[i - 1] + fibonacci_series[i - 2];
    }

    printf("\nFibonacci Series:\n");
    printf("------------------------------------------------\n");
    for (i = 0; i < num_terms; i++) {
        printf("%d\t", fibonacci_series[i]);
    }
    printf("\n");

    while (1) {
        printf("\nPress 1 to generate another series\n");
        printf("Press 2 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter the number of terms you want to generate: ");
            scanf("%d", &num_terms);

            for (i = 0; i < num_terms; i++) {
                fibonacci_series[i] = (i == 0)? 0 : (i == 1)? 1 : fibonacci_series[i - 1] + fibonacci_series[i - 2];
            }

            printf("\nFibonacci Series:\n");
            printf("------------------------------------------------\n");
            for (i = 0; i < num_terms; i++) {
                printf("%d\t", fibonacci_series[i]);
            }
            printf("\n");
        }
        else if (choice == 2) {
            exit(0);
        }
        else {
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}