//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int i, n;

    srand(time(NULL));
    n = rand() % MAX_SIZE + 1;

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int sum = 0;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("Sum of elements: %d\n", sum);

    int product = 1;
    for (i = 0; i < n; i++) {
        product *= arr[i];
    }
    printf("Product of elements: %d\n", product);

    int min = arr[0];
    int max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    int even_count = 0;
    int odd_count = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even_count++;
        }
        else {
            odd_count++;
        }
    }
    printf("Number of even elements: %d\n", even_count);
    printf("Number of odd elements: %d\n", odd_count);

    int avg = sum / n;
    printf("Average of elements: %.2f\n", (float)avg / n);

    return 0;
}