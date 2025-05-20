//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE];
    int size;
    int sum = 0;
    int max = 0;
    int min = 1000000;
    int avg;
    int count = 0;
    int i;
    srand(time(0));

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Generates random numbers between 0 and 999
    }

    printf("The array is: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < size; i++) {
        sum += arr[i]; // Calculates the sum of all elements in the array
    }

    avg = sum / size; // Calculates the average of all elements in the array

    printf("The sum of all elements in the array is: %d\n", sum);
    printf("The average of all elements in the array is: %d\n", avg);

    for (i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i]; // Finds the maximum element in the array
        }
        if (arr[i] < min) {
            min = arr[i]; // Finds the minimum element in the array
        }
    }

    printf("The maximum element in the array is: %d\n", max);
    printf("The minimum element in the array is: %d\n", min);

    return 0;
}