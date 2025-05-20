//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, l;
    long int n, m, o;
    char c;

    printf("Surprised! I didn't expect you to run this program!\n");

    // Generate a random number between 1 and 100
    n = rand() % 100 + 1;

    // Calculate the factorial of n
    m = n * factorial(n - 1);

    // Calculate the sum of the factorial of n and 1
    o = m + 1;

    // Print the result
    printf("The result of n * factorial(n - 1) + 1 is %ld\n", o);

    // Ask the user for input
    printf("Enter a number (1-100): ");
    scanf("%d", &i);

    // Check if the user input is between 1 and 100
    if (i > 100 || i < 1) {
        printf("Oops! That's not a valid input. Try again.\n");
        return 1;
    }

    // Calculate the factorial of the user input
    j = factorial(i - 1);

    // Calculate the product of the user input and the factorial of the user input
    k = i * j;

    // Add 1 to the product
    l = k + 1;

    // Print the result
    printf("The result of %d * factorial(%d) + 1 is %ld\n", i, j, l);

    return 0;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}