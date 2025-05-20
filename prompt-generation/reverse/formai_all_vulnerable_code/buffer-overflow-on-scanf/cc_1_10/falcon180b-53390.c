//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int i, j, n;
    float a, b, c;
    double d, e, f;
    char str[100];

    // Prompt user for input
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);

    // Generate random numbers
    for (i = 0; i < n; i++) {
        a = rand() % 100;
        b = rand() % 100;
        c = rand() % 100;
        d = rand() % 1000;
        e = rand() % 1000;
        f = rand() % 1000;

        // Print random numbers
        printf("Random number %d: %f\n", i+1, a);
        printf("Random number %d: %f\n", i+2, b);
        printf("Random number %d: %f\n", i+3, c);
        printf("Random number %d: %lf\n", i+4, d);
        printf("Random number %d: %lf\n", i+5, e);
        printf("Random number %d: %lf\n", i+6, f);
    }

    // Prompt user for input
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the string
    for (i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");

    // Calculate the factorial of a number
    printf("Enter a number: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        a = i * factorial(i-1);
        printf("%d! = %d\n", i, a);
    }

    return 0;
}

int factorial(int n) {
    int i, result = 1;

    for (i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}