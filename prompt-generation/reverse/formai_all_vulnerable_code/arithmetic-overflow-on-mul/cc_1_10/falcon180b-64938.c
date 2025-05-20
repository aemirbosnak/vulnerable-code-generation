//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int i, j;
    int arr[SIZE];
    int max = 0, min = 100;
    int sum = 0;
    int product = 1;
    int count = 0;
    int even_count = 0;
    int odd_count = 0;
    int bitwise_sum = 0;
    int bitwise_product = 1;
    int bitwise_count = 0;

    srand(time(NULL));

    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 101;
    }

    for (i = 0; i < SIZE; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
        sum += arr[i];
        product *= arr[i];
        bitwise_sum |= arr[i];
        bitwise_product &= arr[i];
        if (arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
        bitwise_count ^= arr[i];
    }

    printf("The maximum value in the array is: %d\n", max);
    printf("The minimum value in the array is: %d\n", min);
    printf("The sum of all values in the array is: %d\n", sum);
    printf("The product of all values in the array is: %d\n", product);
    printf("The bitwise OR of all values in the array is: %d\n", bitwise_sum);
    printf("The bitwise AND of all values in the array is: %d\n", bitwise_product);
    printf("The number of even values in the array is: %d\n", even_count);
    printf("The number of odd values in the array is: %d\n", odd_count);
    printf("The bitwise XOR of all values in the array is: %d\n", bitwise_count);

    return 0;
}