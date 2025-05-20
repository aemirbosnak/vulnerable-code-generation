//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUMBERS 1000
#define MAX_DIGITS 1000
#define MAX_ITERATIONS 1000

#define PI 3.14159265358979323846

int main() {
    int i, j, k;
    int num_digits, num_numbers;
    double sum = 0.0;
    double numbers[MAX_NUMBERS];
    double pi_estimate;
    time_t start_time, end_time;

    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &num_numbers);

    printf("Enter the number of digits for each random number: ");
    scanf("%d", &num_digits);

    srand(time(NULL));

    for (i = 0; i < num_numbers; i++) {
        do {
            numbers[i] = (double)rand() / RAND_MAX;
        } while (num_digits > 0 && floor(numbers[i])!= numbers[i]);
        num_digits--;
    }

    printf("Random numbers: ");
    for (i = 0; i < num_numbers; i++) {
        printf("%lf ", numbers[i]);
    }
    printf("\n");

    start_time = time(NULL);
    for (j = 0; j < MAX_ITERATIONS; j++) {
        for (i = 0; i < num_numbers; i++) {
            sum += numbers[i] * numbers[i];
        }
    }
    end_time = time(NULL);

    printf("The sum of the squares of %d random numbers is %lf\n", num_numbers, sum);
    printf("Time taken: %ld seconds\n", end_time - start_time);

    pi_estimate = 6.0 / sum;
    printf("The estimate of pi is %lf\n", pi_estimate);

    return 0;
}