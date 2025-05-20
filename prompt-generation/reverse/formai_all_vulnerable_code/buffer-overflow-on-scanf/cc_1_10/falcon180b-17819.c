//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100
#define MIN_VALUE 1
#define MAX_VALUE 100

void generate_random_numbers(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int num_elements;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &num_elements);

    if (num_elements < 1 || num_elements > MAX_NUMBERS) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    int arr[MAX_NUMBERS];
    generate_random_numbers(arr, num_elements);

    printf("Original array:\n");
    print_array(arr, num_elements);

    int min_index = 0;
    for (int i = 1; i < num_elements; i++) {
        if (arr[i] < arr[min_index]) {
            min_index = i;
        }
    }

    int min_value = arr[min_index];
    printf("Minimum value: %d\n", min_value);

    return 0;
}