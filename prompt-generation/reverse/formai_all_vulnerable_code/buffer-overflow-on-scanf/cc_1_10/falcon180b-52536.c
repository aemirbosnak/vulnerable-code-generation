//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a number
long long int factorial(int num) {
    long long int result = 1;
    for (int i = 2; i <= num; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Calculate the factorial of the number
    long long int fact = factorial(num);

    // Calculate the sum of the digits of the factorial
    int sum = 0;
    while (fact!= 0) {
        sum += fact % 10;
        fact /= 10;
    }

    // Calculate the product of the digits of the factorial
    int prod = 1;
    while (fact!= 0) {
        prod *= fact % 10;
        fact /= 10;
    }

    // Calculate the average of the digits of the factorial
    float avg;
    if (sum == 0) {
        avg = 0;
    } else {
        avg = (float)sum / num;
    }

    // Print the results
    printf("Factorial of %d is: %lld\n", num, fact);
    printf("Sum of the digits of the factorial is: %d\n", sum);
    printf("Product of the digits of the factorial is: %d\n", prod);
    printf("Average of the digits of the factorial is: %.2f\n", avg);

    return 0;
}