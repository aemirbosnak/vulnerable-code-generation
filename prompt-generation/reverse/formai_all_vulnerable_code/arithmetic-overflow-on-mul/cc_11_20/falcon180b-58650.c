//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int main() {

    int arr[SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 256;
    }

    printf("Original Array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }

    printf("Sum of all elements: %d\n", sum);

    int product = 1;
    for (int i = 0; i < SIZE; i++) {
        product *= arr[i];
    }

    printf("Product of all elements: %d\n", product);

    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < SIZE; i++) {
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
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    printf("Number of even elements: %d\n", even_count);
    printf("Number of odd elements: %d\n", odd_count);

    int bitwise_sum = 0;
    for (int i = 0; i < SIZE; i++) {
        bitwise_sum += arr[i] & 0x0F;
    }

    printf("Bitwise sum of elements: %d\n", bitwise_sum);

    return 0;
}