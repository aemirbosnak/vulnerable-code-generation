//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

void generate_fibonacci(int n, long long int *fib) {
    fib[0] = 0;
    if(n > 1) fib[1] = 1;
    for(int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void print_fibonacci(long long int *fib, int n) {
    printf("Fibonacci Sequence up to %d terms: ", n);
    for(int i = 0; i < n; i++) {
        printf("%lld ", fib[i]);
    }
    printf("\n");
}

void visualize_fibonacci(long long int *fib, int n) {
    printf("Visualizing Fibonacci Sequence:\n");
    for(int i = 0; i < n; i++) {
        printf("%3lld: ", fib[i]);
        for(long long int j = 0; j < fib[i]; j += 5) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int player_count, terms;
    printf("Welcome to the Multiplayer Fibonacci Sequence Visualizer!\n");

    printf("Enter number of players: ");
    scanf("%d", &player_count);
    
    printf("Each player will input which Fibonacci number they want to see.\n");
    printf("Enter the number of terms to generate in Fibonacci sequence: ");
    scanf("%d", &terms);

    if(terms <= 0) {
        printf("Number of terms must be positive!\n");
        return 1;
    }

    long long int *fibonacci_sequence = (long long int *)malloc(terms * sizeof(long long int));
    if(fibonacci_sequence == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    generate_fibonacci(terms, fibonacci_sequence);
    
    for(int i = 0; i < player_count; i++) {
        int index;
        printf("\nPlayer %d, enter the index (0 to %d) of the Fibonacci number you want to view: ", i + 1, terms - 1);
        scanf("%d", &index);
        
        if(index < 0 || index >= terms) {
            printf("Invalid index! Please enter a number between 0 and %d.\n", terms - 1);
            i--; // repeat current iteration for invalid input
        } else {
            printf("Fibonacci number at index %d is %lld\n", index, fibonacci_sequence[index]);
        }
    }

    print_fibonacci(fibonacci_sequence, terms);
    visualize_fibonacci(fibonacci_sequence, terms);

    free(fibonacci_sequence);
    return 0;
}