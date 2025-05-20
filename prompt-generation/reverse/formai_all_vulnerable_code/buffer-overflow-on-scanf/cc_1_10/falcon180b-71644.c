//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void generate_random_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[MAX_SIZE];
    generate_random_array(arr, size);

    printf("The original array is:\n");
    print_array(arr, size);

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    printf("The sum of the array is: %d\n", sum);

    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("The minimum value in the array is: %d\n", min);
    printf("The maximum value in the array is: %d\n", max);

    return 0;
}