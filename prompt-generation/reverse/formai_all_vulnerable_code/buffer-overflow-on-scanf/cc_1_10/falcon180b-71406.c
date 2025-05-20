//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 1000

int main() {
    int num_terms;
    int *fibonacci_terms;
    int i;
    int choice;
    int seed;

    printf("Enter the number of Fibonacci terms to generate: ");
    scanf("%d", &num_terms);

    if (num_terms > MAX_TERMS) {
        printf("Error: Number of terms must be less than or equal to %d.\n", MAX_TERMS);
        exit(1);
    }

    fibonacci_terms = (int *) malloc(num_terms * sizeof(int));

    printf("Enter the seed value for the random number generator (0 to 999999): ");
    scanf("%d", &seed);
    srand(seed);

    for (i = 0; i < num_terms; i++) {
        fibonacci_terms[i] = rand() % 1000000;
    }

    printf("Enter the choice of visualization:\n1. Bar Chart\n2. Line Chart\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Fibonacci Sequence (Bar Chart):\n");
            for (i = 0; i < num_terms; i++) {
                printf("Term %d: %d\n", i + 1, fibonacci_terms[i]);
            }
            break;
        case 2:
            printf("Fibonacci Sequence (Line Chart):\n");
            printf("Term\tValue\n");
            for (i = 0; i < num_terms; i++) {
                printf("%d\t%d\n", i + 1, fibonacci_terms[i]);
            }
            break;
        default:
            printf("Invalid choice.\n");
            exit(1);
    }

    free(fibonacci_terms);
    return 0;
}