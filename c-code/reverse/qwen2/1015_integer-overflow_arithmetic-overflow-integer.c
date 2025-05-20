#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void bubbleSort(int arr[], int n) {
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
    int n, choice, sum = 0, min, max;
    float avg;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    min = arr[0];
    max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    avg = (float)sum / n;

    printf("\nEnter operation to perform:\n");
    printf("1. Sum\n2. Average\n3. Min\n4. Max\n5. Sort\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Sum: %d\n", sum);
            break;
        case 2:
            printf("Average: %.2f\n", avg);
            break;
        case 3:
            printf("Min: %d\n", min);
            break;
        case 4:
            printf("Max: %d\n", max);
            break;
        case 5:
            bubbleSort(arr, n);
            printf("Sorted array: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
