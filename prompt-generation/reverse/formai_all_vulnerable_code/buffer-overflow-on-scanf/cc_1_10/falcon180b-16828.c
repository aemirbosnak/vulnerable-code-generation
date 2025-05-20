//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MIN_VALUE 0
#define MAX_VALUE 100

int main() {
    int i, j, n, sum = 0, min_val, max_val;
    float avg, dev;
    srand(time(NULL));

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[MAX_SIZE];
    for (i = 0; i < n; i++) {
        arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    avg = (float)sum / n;

    for (i = 0; i < n; i++) {
        dev += pow((arr[i] - avg), 2);
    }

    dev = sqrt(dev / n);

    min_val = arr[0];
    max_val = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    printf("The array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nThe sum of the array is: %d", sum);
    printf("\nThe average of the array is: %.2f", avg);
    printf("\nThe standard deviation of the array is: %.2f", dev);
    printf("\nThe minimum value in the array is: %d", min_val);
    printf("\nThe maximum value in the array is: %d", max_val);

    return 0;
}