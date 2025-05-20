//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100 // maximum size of array

// function to calculate sum of all elements in an array
double calculate_sum(int arr[], int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

// function to calculate mean of all elements in an array
double calculate_mean(int arr[], int n)
{
    double sum = calculate_sum(arr, n);
    double mean = sum / n;
    return mean;
}

// function to calculate standard deviation of all elements in an array
double calculate_std_dev(int arr[], int n)
{
    double mean = calculate_mean(arr, n);
    double sum_of_squares = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum_of_squares += pow((arr[i] - mean), 2);
    }
    double std_dev = sqrt(sum_of_squares / n);
    return std_dev;
}

int main()
{
    int arr[MAX_SIZE];
    int n = 0; // number of elements in array
    double sum = 0.0;
    double mean = 0.0;
    double std_dev = 0.0;

    // prompt user to enter elements of array
    printf("Enter elements of array (enter -1 to stop):\n");
    while (scanf("%d", &arr[n]) == 1 && arr[n]!= -1)
    {
        n++; // increment number of elements in array
        if (n >= MAX_SIZE)
        {
            printf("Array size limit reached (%d).\n", MAX_SIZE);
            exit(1);
        }
    }

    // calculate sum, mean, and standard deviation
    sum = calculate_sum(arr, n);
    mean = calculate_mean(arr, n);
    std_dev = calculate_std_dev(arr, n);

    // print results
    printf("Sum of array elements: %.2f\n", sum);
    printf("Mean of array elements: %.2f\n", mean);
    printf("Standard deviation of array elements: %.2f\n", std_dev);

    return 0;
}