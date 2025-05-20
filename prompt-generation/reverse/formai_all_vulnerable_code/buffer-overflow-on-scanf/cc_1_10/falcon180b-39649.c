//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

// Function to calculate the sum of squares of first n natural numbers
long long int sum_of_squares(int n) {
    long long int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

int main() {
    int choice;
    printf("Enter your choice:\n");
    printf("1. Calculate the sum of squares of first n natural numbers\n");
    printf("2. Benchmarking test\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int n;
            printf("Enter the value of n: ");
            scanf("%d", &n);
            long long int result = sum_of_squares(n);
            printf("The sum of squares of first %d natural numbers is: %lld\n", n, result);
            break;
        }
        case 2: {
            clock_t start, end;
            double cpu_time_used;

            start = clock();
            for (int i = 0; i < N; i++) {
                sum_of_squares(100000);
            }
            end = clock();

            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

            printf("CPU time used: %lf seconds\n", cpu_time_used);
            break;
        }
        default: {
            printf("Invalid choice\n");
        }
    }

    return 0;
}