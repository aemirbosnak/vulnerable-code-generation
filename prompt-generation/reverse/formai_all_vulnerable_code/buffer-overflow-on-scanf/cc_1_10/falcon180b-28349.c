//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VALUE 100

void generate_random_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size, max_value;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the maximum value for each element: ");
    scanf("%d", &max_value);

    int arr[MAX_SIZE];
    if (size > MAX_SIZE) {
        printf("Error: Array size too large\n");
        return 1;
    }

    generate_random_array(arr, size);
    printf("Original array:\n");
    print_array(arr, size);

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    int avg = sum / size;
    printf("Average value: %d\n", avg);

    int max_count = 0;
    int max_value_count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == max_value) {
            max_value_count++;
        }
        if (arr[i] > avg) {
            max_count++;
        }
    }

    printf("Number of elements greater than average: %d\n", max_count);
    printf("Number of elements equal to maximum value: %d\n", max_value_count);

    return 0;
}