//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to generate random numbers
double randDouble(double min, double max) {
    double randNum = (double)rand() / RAND_MAX;
    return min + randNum * (max - min);
}

// Function to generate an array of random numbers
void generateArray(int n, int *arr) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to print an array
void printArray(int n, int *arr) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bucket sort function
void bucketSort(int n, int *arr) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int range = max - min + 1;
    int *bucket = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (bucket[i] > 0) {
            arr[index++] = i + min;
            bucket[i]--;
        }
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    generateArray(n, arr);
    printf("Unsorted array:\n");
    printArray(n, arr);
    bucketSort(n, arr);
    printf("Sorted array:\n");
    printArray(n, arr);
    return 0;
}