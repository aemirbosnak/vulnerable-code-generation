//FormAI DATASET v1.0 Category: Data mining ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

void read_data(int* array, int n) {
    printf("Enter %d integers to store in the array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
}

void display_data(int* array, int n) {
    printf("\nDisplaying the array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}

void find_maximum(int* array, int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    printf("\n\nThe maximum value in the array is: %d", max);
}

void find_minimum(int* array, int n) {
    int min = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    printf("\n\nThe minimum value in the array is: %d", min);
}

void calculate_average(int* array, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    double average = (double)sum / n;
    printf("\n\nThe average value of the array is: %.2f", average);
}

int main() {
    int n;
    printf("Enter the number of integers you want to store in the array: ");
    scanf("%d", &n);

    int* array = (int*)malloc(n * sizeof(int));
    read_data(array, n);
    display_data(array, n);
    find_maximum(array, n);
    find_minimum(array, n);
    calculate_average(array, n);
    free(array);

    return 0;
}