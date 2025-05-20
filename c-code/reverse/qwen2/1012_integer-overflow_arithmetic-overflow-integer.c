#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {32767, 32768, -32768, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Intentional overflow vulnerability
    }

    float avg = (float)sum / n;

    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);

    sort(arr, n);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
