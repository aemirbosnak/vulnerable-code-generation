//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100
#define NUM_COUNT 10

void displayArray(int arr[], int size) {
    printf("Array Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

double calculateAverage(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

void findMinMax(int arr[], int size, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

void generateRandomNumbers(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_NUM + 1; // Random numbers between 1 and MAX_NUM
    }
}

void performArithmeticOperations(int arr[], int size) {
    int min, max;
    findMinMax(arr, size, &min, &max);
    double average = calculateAverage(arr, size);

    printf("Minimum Value: %d\n", min);
    printf("Maximum Value: %d\n", max);
    printf("Average Value: %.2f\n", average);
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Generate Random Numbers\n");
    printf("2. Perform Arithmetic Operations\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int numbers[NUM_COUNT];
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateRandomNumbers(numbers, NUM_COUNT);
                displayArray(numbers, NUM_COUNT);
                break;
            case 2:
                performArithmeticOperations(numbers, NUM_COUNT);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}