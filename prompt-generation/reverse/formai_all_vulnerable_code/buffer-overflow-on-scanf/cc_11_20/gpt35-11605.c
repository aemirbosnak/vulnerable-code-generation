//FormAI DATASET v1.0 Category: System boot optimizer ; Style: mathematical
#include <stdio.h>

int main() {
    // Initializing variables
    int x, y, z, a, b;

    printf("Enter values of x, y, z, a, and b:\n");
    scanf("%d %d %d %d %d", &x, &y, &z, &a, &b);

    // Check if input is valid
    if (x <= 0 || y <= 0 || z <= 0 || a <= 0 || b <= 0) {
        printf("Invalid input! All values must be greater than zero.\n");
        return 1;
    }

    // Calculate the sum and average of the inputs
    int sum = x + y + z + a + b;
    float average = sum / 5.0;

    // Calculate the product of the inputs
    int product = x * y * z * a * b;

    // Calculate the GCD of the inputs
    int gcd = x;
    if (gcd > y) {
        gcd = y;
    }
    if (gcd > z) {
        gcd = z;
    }
    if (gcd > a) {
        gcd = a;
    }
    if (gcd > b) {
        gcd = b;
    }
    while (gcd > 1) {
        if (x % gcd == 0 && y % gcd == 0 && z % gcd == 0 &&
            a % gcd == 0 && b % gcd == 0) {
            break;
        }
        gcd--;
    }

    // Print the results
    printf("Sum: %d\n", sum);
    printf("Average: %f\n", average);
    printf("Product: %d\n", product);
    printf("GCD: %d\n", gcd);

    return 0;
}