//Falcon-180B DATASET v1.0 Category: Recursive ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to calculate the mean of an array of numbers
double calc_mean(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double) sum / n;
}

// Function to calculate the standard deviation of an array of numbers
double calc_stddev(int arr[], int n) {
    double mean = calc_mean(arr, n);
    int sum_squares = 0;
    for (int i = 0; i < n; i++) {
        sum_squares += pow(arr[i] - mean, 2);
    }
    return sqrt(sum_squares / n);
}

// Function to generate an array of random numbers
void generate_array(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand_num(1, 100);
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    generate_array(arr, n);

    printf("The array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    double mean = calc_mean(arr, n);
    printf("The mean is: %.2f\n", mean);

    double stddev = calc_stddev(arr, n);
    printf("The standard deviation is: %.2f\n", stddev);

    return 0;
}