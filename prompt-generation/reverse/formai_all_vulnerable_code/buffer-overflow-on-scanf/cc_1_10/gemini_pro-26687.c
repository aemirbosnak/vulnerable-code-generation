//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main() {
    uint64_t a, b, c;
    printf("Enter two numbers: ");
    scanf("%llu %llu", &a, &b);

    // Check for overflow
    if (a > UINT64_MAX - b) {
        printf("Overflow error!\n");
        return EXIT_FAILURE;
    }

    // Perform addition and check for overflow
    c = a + b;
    if (c < a || c < b) {
        printf("Overflow error!\n");
        return EXIT_FAILURE;
    }

    // Perform subtraction and check for underflow
    c = a - b;
    if (c > a || (b != 0 && c == 0)) {
        printf("Underflow error!\n");
        return EXIT_FAILURE;
    }

    // Perform multiplication and check for overflow
    c = a * b;
    if (c / a != b) {
        printf("Overflow error!\n");
        return EXIT_FAILURE;
    }

    // Perform division and check for divide-by-zero
    if (b == 0) {
        printf("Divide-by-zero error!\n");
        return EXIT_FAILURE;
    }
    c = a / b;

    // Perform modulus and check for divide-by-zero
    if (b == 0) {
        printf("Divide-by-zero error!\n");
        return EXIT_FAILURE;
    }
    c = a % b;

    // Print the results
    printf("Sum: %llu\n", c);
    printf("Difference: %llu\n", c);
    printf("Product: %llu\n", c);
    printf("Quotient: %llu\n", c);
    printf("Remainder: %llu\n", c);

    return EXIT_SUCCESS;
}