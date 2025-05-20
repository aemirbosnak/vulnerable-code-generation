//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to calculate the sum of squares of numbers from 1 to n
long long int calculate_sum_of_squares(int n)
{
    long long int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i * i;
    }
    return sum;
}

// Function to calculate the average time taken by the calculate_sum_of_squares function
double calculate_average_time(int n, int num_iterations)
{
    clock_t start_time, end_time;
    double total_time = 0.0;
    for (int i = 0; i < num_iterations; i++)
    {
        start_time = clock();
        calculate_sum_of_squares(n);
        end_time = clock();
        total_time += (double)(end_time - start_time) / CLOCKS_PER_SEC;
    }
    return total_time / num_iterations;
}

int main()
{
    int n, num_iterations;

    // Get input from user
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the number of iterations: ");
    scanf("%d", &num_iterations);

    // Calculate the sum of squares of numbers from 1 to n
    long long int sum = calculate_sum_of_squares(n);

    // Calculate the average time taken by the calculate_sum_of_squares function
    double average_time = calculate_average_time(n, num_iterations);

    // Display the results
    printf("The sum of squares of numbers from 1 to %d is %lld\n", n, sum);
    printf("The average time taken by the calculate_sum_of_squares function for %d iterations is %.2lf seconds\n", num_iterations, average_time);

    return 0;
}