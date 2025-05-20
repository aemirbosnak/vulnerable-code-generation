//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000
#define MAX_NUM 1000000000

// Function to generate random numbers
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to calculate the sum of an array
int sum_array(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to calculate the average of an array
double avg_array(int arr[], int size) {
    int sum = sum_array(arr, size);
    double avg = (double) sum / size;
    return avg;
}

// Function to fill an array with random numbers
void fill_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand_num(1, MAX_NUM);
    }
}

// Function to benchmark the performance of the program
void benchmark(int size, int num_iterations) {
    int arr[SIZE];
    fill_array(arr, size);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (int i = 0; i < num_iterations; i++) {
        int sum = sum_array(arr, size);
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("CPU time used: %.2lf seconds\n", cpu_time_used);
    printf("Size of array: %d\n", size);
    printf("Number of iterations: %d\n", num_iterations);
}

int main() {
    int size, num_iterations;

    // Get input from user
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the number of iterations: ");
    scanf("%d", &num_iterations);

    // Benchmark the program
    benchmark(size, num_iterations);

    return 0;
}