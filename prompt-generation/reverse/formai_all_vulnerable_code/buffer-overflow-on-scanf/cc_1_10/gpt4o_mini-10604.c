//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: Claude Shannon
#include <stdio.h>

/**
 * Function to calculate Fibonacci sequence recursively.
 * The Fibonacci sequence is defined as follows:
 * F(0) = 0, F(1) = 1,
 * F(n) = F(n-1) + F(n-2) for n >= 2
 *
 * @param n: The nth Fibonacci number to calculate.
 * @return: The nth Fibonacci number.
 */
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/**
 * Function to print the Fibonacci sequence up to n terms.
 *
 * @param terms: The number of terms to print.
 */
void printFibonacci(int terms) {
    printf("Fibonacci sequence up to %d terms:\n", terms);
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

/**
 * Function to calculate the entropy of the Fibonacci sequence based on frequency of digits.
 *
 * @param terms: The number of terms to analyze.
 * @return: The calculated entropy.
 */
double calculateEntropy(int terms) {
    int counts[10] = {0}; // count of digits 0-9
    int total_count = 0;
    
    // Calculate frequencies of digits in Fibonacci numbers
    for (int i = 0; i < terms; i++) {
        int fib_num = fibonacci(i);
        total_count++;

        // Count occurrences of each digit in fib_num
        while (fib_num > 0) {
            int digit = fib_num % 10;
            counts[digit]++;
            fib_num /= 10;
        }
    }
    
    // Calculate entropy
    double entropy = 0.0;
    for (int i = 0; i < 10; i++) {
        if (counts[i] > 0) {
            double probability = (double)counts[i] / total_count;
            entropy -= probability * log10(probability); // Using base-10 logarithm
        }
    }
    
    return entropy;
}

/**
 * Main function to execute the program.
 */
int main() {
    int terms;

    printf("Enter the number of Fibonacci terms to generate: ");
    scanf("%d", &terms);

    // Print Fibonacci sequence
    printFibonacci(terms);

    // Calculate and print entropy
    double entropy = calculateEntropy(terms);
    printf("The entropy of the Fibonacci sequence with %d terms is: %.4f\n", terms, entropy);

    return 0;
}