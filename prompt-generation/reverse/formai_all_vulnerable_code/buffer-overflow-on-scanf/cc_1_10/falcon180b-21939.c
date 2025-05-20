//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    double x, sum = 0;

    // prompt user for number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // calculate sum of first n terms of geometric series
    for (int i = 1; i <= n; i++) {
        printf("Enter term %d: ", i);
        scanf("%lf", &x);
        sum += x;
    }

    // calculate sum of first n terms of arithmetic series
    double a = 1, d = 1;
    printf("Enter the common difference: ");
    scanf("%lf", &d);
    for (int i = 1; i <= n; i++) {
        printf("Term %d: %lf\n", i, a);
        a += d;
    }

    // calculate sum of first n terms of harmonic series
    double term, harmonic_sum = 0;
    printf("Enter the first term of the harmonic series: ");
    scanf("%lf", &term);
    for (int i = 1; i <= n; i++) {
        double reciprocal = 1 / i;
        harmonic_sum += reciprocal;
        printf("Term %d: %lf\n", i, reciprocal);
    }

    // calculate sum of first n terms of Fibonacci series
    int first_term, second_term, next_term, count = 0;
    printf("Enter the first term of the Fibonacci series: ");
    scanf("%d", &first_term);
    printf("Enter the second term of the Fibonacci series: ");
    scanf("%d", &second_term);
    while (count < n) {
        next_term = first_term + second_term;
        printf("Term %d: %d\n", count+1, next_term);
        first_term = second_term;
        second_term = next_term;
        count++;
    }

    return 0;
}