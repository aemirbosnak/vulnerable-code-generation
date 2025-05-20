//Falcon-180B DATASET v1.0 Category: Recursive ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to calculate the mean of an array of integers
double calc_mean(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double) sum / size;
}

// Function to calculate the standard deviation of an array of integers
double calc_std_dev(int arr[], int size, double mean) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow(arr[i] - mean, 2);
    }
    return sqrt(sum / size);
}

// Function to print an array of integers
void print_arr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Recursive function to generate an array of random integers
void gen_arr(int arr[], int size, int min, int max) {
    if (size == 0) {
        return;
    }
    arr[size - 1] = rand_num(min, max);
    gen_arr(arr, size - 1, min, max);
}

int main() {
    int size, min, max;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the minimum value: ");
    scanf("%d", &min);
    printf("Enter the maximum value: ");
    scanf("%d", &max);

    int arr[size];
    srand(time(NULL)); // Seed the random number generator with the current time
    gen_arr(arr, size, min, max); // Generate an array of random integers

    printf("The array is: ");
    print_arr(arr, size);

    double mean = calc_mean(arr, size);
    printf("The mean is: %.2lf\n", mean);

    double std_dev = calc_std_dev(arr, size, mean);
    printf("The standard deviation is: %.2lf\n", std_dev);

    return 0;
}