//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to calculate the sum of squares of first n natural numbers
int sum_of_squares(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

// Function to calculate the nth prime number
int nth_prime(int n) {
    int count = 0;
    int num = 2;
    while (count < n) {
        int is_prime = 1;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            count++;
        }
        num++;
    }
    return num - 1;
}

int main() {
    int n, m;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of m: ");
    scanf("%d", &m);
    clock_t start_time = clock();
    int result1 = sum_of_squares(n);
    int result2 = nth_prime(m);
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("The sum of squares of first %d natural numbers is: %d\n", n, result1);
    printf("The %dth prime number is: %d\n", m, result2);
    printf("Time taken to execute the program: %.6f seconds\n", time_taken);
    return 0;
}