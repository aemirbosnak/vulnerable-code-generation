//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define FACT_MAX 50

double factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        int mean, variance;
        double left, right, result;
        
        clock_t start = clock();
        
        left = factorial(n-1);
        right = (double)n / (n-1);
        
        mean = (int)lround(left + right);
        variance = pow(abs(left - mean), 2);
        
        result = mean;
        
        if (variance > pow(0.1 * abs(mean), 2)) {
            result = result * (n-1) + factorial(n-1);
        }
        
        clock_t end = clock();
        
        printf("n = %d, result = %lf, time taken = %lfs\n", n, result, (double)(end-start)/CLOCKS_PER_SEC);
        
        return result;
    }
}

int main() {
    int number;

    printf("Enter a number to find its factorial: ");
    scanf("%d", &number);

    if (number > FACT_MAX) {
        printf("Factorial of %d is too big to calculate.\n", number);
    } else {
        factorial(number);
    }

    return 0;
}