//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void print_array(const int arr[], int size) {
    printf("Array Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void fill_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Fill with random numbers between 0 and 99
    }
}

int sum_array(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

double average_array(const int arr[], int size) {
    if (size == 0) return 0.0;
    return (double)sum_array(arr, size) / size;
}

void sort_array(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void find_min_max(const int arr[], int size, int *min, int *max) {
    if (size == 0) return;
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

void display_statistics(const int arr[], int size) {
    if (size == 0) {
        printf("No elements to display statistics.\n");
        return;
    }
    
    int min, max;
    find_min_max(arr, size, &min, &max);
    double average = average_array(arr, size);
    printf("Statistics:\n");
    printf("Sum: %d\n", sum_array(arr, size));
    printf("Average: %.2f\n", average);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Fill array with random values\n");
    printf("2. Display array\n");
    printf("3. Show statistics\n");
    printf("4. Sort array\n");
    printf("5. Exit\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    srand(time(NULL)); // Seed random number generator

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the size of the array (max %d): ", MAX_SIZE);
                scanf("%d", &size);
                if (size > MAX_SIZE || size < 1) {
                    printf("Invalid size. Please enter a number between 1 and %d.\n", MAX_SIZE);
                    size = 0; // Reset size
                } else {
                    fill_array(arr, size);
                    printf("Array filled with random values.\n");
                }
                break;
            case 2:
                if (size > 0) {
                    print_array(arr, size);
                } else {
                    printf("Array is empty. Please fill the array first.\n");
                }
                break;
            case 3:
                display_statistics(arr, size);
                break;
            case 4:
                if (size > 0) {
                    sort_array(arr, size);
                    printf("Array sorted in ascending order.\n");
                } else {
                    printf("Array is empty. Please fill the array first.\n");
                }
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}