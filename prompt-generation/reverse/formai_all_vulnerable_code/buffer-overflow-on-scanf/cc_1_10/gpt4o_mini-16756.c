//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void generate_fibonacci(int n, long long *sequence) {
    sequence[0] = 0;
    sequence[1] = 1;
    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }
}

void print_fibonacci(long long *sequence, int n) {
    printf("Fibonacci Sequence (up to %d terms):\n", n);
    for (int i = 0; i < n; i++) {
        printf("%lld ", sequence[i]);
    }
    printf("\n");
}

void visualize_fibonacci(long long *sequence, int n) {
    printf("\nVisualizing Fibonacci Sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("%lld: ", sequence[i]);
        for (long long j = 0; j < sequence[i]; j += 100000) {
            printf("#");
        }
        printf("\n");
    }
}

void save_fibonacci_to_file(long long *sequence, int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing: %s\n", filename);
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%lld\n", sequence[i]);
    }
    fclose(file);
    printf("Fibonacci sequence saved to %s\n", filename);
}

int main() {
    int num_terms;
    char filename[100];
    
    printf("Enter the number of Fibonacci terms to generate: ");
    scanf("%d", &num_terms);
    
    if (num_terms < 2) {
        fprintf(stderr, "Error: Please enter a number greater than or equal to 2.\n");
        return EXIT_FAILURE;
    }
    
    long long *fibonacci_sequence = (long long *)malloc(num_terms * sizeof(long long));
    if (fibonacci_sequence == NULL) {
        fprintf(stderr, "Error allocating memory for Fibonacci sequence.\n");
        return EXIT_FAILURE;
    }
    
    generate_fibonacci(num_terms, fibonacci_sequence);
    print_fibonacci(fibonacci_sequence, num_terms);
    visualize_fibonacci(fibonacci_sequence, num_terms);
    
    printf("Enter a filename to save the sequence: ");
    scanf("%s", filename);
    save_fibonacci_to_file(fibonacci_sequence, num_terms, filename);

    free(fibonacci_sequence);
    return EXIT_SUCCESS;
}