//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function prototypes
int generateRandomNumber(int min, int max);
float calculateAverage(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int n;
    int arr[1000];
    int i, j;

    srand(time(NULL));

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        arr[i] = generateRandomNumber(1, 100);
    }

    printf("Original array:\n");
    printArray(arr, n);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Sorted array:\n");
    printArray(arr, n);

    float avg = calculateAverage(arr, n);
    printf("Average: %.2f\n", avg);

    return 0;
}

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

float calculateAverage(int arr[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}