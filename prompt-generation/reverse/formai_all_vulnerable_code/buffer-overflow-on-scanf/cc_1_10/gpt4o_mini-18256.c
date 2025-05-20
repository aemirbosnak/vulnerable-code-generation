//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void save_primes_to_file(int *primes, int count) {
    FILE *file = fopen("primes.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\n", primes[i]);
    }
    fclose(file);
    printf("Saved %d prime numbers to 'primes.txt'.\n", count);
}

bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void generate_primes(int limit) {
    int *primes = malloc(limit * sizeof(int));
    if (primes == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    int count = 0;
    
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            primes[count++] = i;
            printf("%d ", i); // Print the prime number as it's found
        }
    }
    printf("\n");
    save_primes_to_file(primes, count);
    free(primes);
}

void display_saved_primes() {
    FILE *file = fopen("primes.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "No saved primes found.\n");
        return;
    }
    
    printf("Saved Prime Numbers from 'primes.txt':\n");
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

int main() {
    int limit;
    char choice;

    while (true) {
        printf("Enter a positive integer limit to generate prime numbers: ");
        while (scanf("%d", &limit) != 1 || limit < 1) {
            printf("Invalid input. Please enter a positive integer: ");
            while (getchar() != '\n'); // Clear input buffer
        }

        generate_primes(limit);

        printf("\nDo you want to display previously saved primes? (y/n): ");
        while (getchar() != '\n'); // Clear input buffer
        choice = getchar();

        if (choice == 'y' || choice == 'Y') {
            display_saved_primes();
        }

        printf("\nDo you want to generate primes for another limit? (y/n): ");
        while (getchar() != '\n'); // Clear input buffer
        choice = getchar();
        
        if (choice != 'y' && choice != 'Y')
            break;
    }
    
    printf("Thank you for using the Prime Number Generator!\n");
    return 0;
}