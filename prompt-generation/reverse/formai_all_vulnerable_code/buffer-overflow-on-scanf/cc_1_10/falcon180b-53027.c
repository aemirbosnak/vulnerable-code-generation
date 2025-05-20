//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 1000000

int main() {
    int i, n, a = 0, b = 1, c, fib_seq[MAX_TERMS];
    double start_time, end_time;
    char input[10];

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Ask the user for the number of terms to generate
    printf("Enter the number of terms to generate: ");
    scanf("%d", &n);

    // Generate the Fibonacci sequence
    for (i = 0; i < n; i++) {
        fib_seq[i] = rand() % 1000000;
    }

    // Print the sequence to the console
    printf("Fibonacci sequence:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", fib_seq[i]);
    }

    // Ask the user if they want to save the sequence to a file
    printf("Do you want to save the sequence to a file? (y/n): ");
    scanf("%s", input);

    if (strcmp(input, "y") == 0) {
        // Get the file name from the user
        printf("Enter the file name: ");
        scanf("%s", input);

        // Open the file in write mode
        FILE *file = fopen(input, "w");

        if (file == NULL) {
            printf("Error opening file.\n");
            exit(1);
        }

        // Write the sequence to the file
        for (i = 0; i < n; i++) {
            fprintf(file, "%d\n", fib_seq[i]);
        }

        // Close the file
        fclose(file);
    }

    // Measure the time it took to generate the sequence
    start_time = clock();
    for (i = 0; i < n; i++) {
        fib_seq[i] = rand() % 1000000;
    }
    end_time = clock();

    printf("Time taken to generate sequence: %.6lf seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}