//Falcon-180B DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // Maximum size of the array
#define INIT_SIZE 10 // Initial size of the array

int main() {
    int *arr; // Pointer to the array
    int size = INIT_SIZE; // Initial size of the array
    int capacity = INIT_SIZE; // Capacity of the array

    // Dynamically allocate memory for the array
    arr = (int *)malloc(sizeof(int) * capacity);

    if (arr == NULL) {
        printf("Error: Failed to allocate memory for the array.\n");
        return 1;
    }

    // Initialize the array with zeros
    for (int i = 0; i < capacity; i++) {
        arr[i] = 0;
    }

    int choice;
    do {
        printf("\n");
        printf("1. Add an element to the array\n");
        printf("2. Remove an element from the array\n");
        printf("3. Display the array\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Check if the array is full
                if (size == capacity) {
                    printf("Error: Array is full.\n");
                } else {
                    printf("\n");
                    printf("Enter the element to add: ");
                    scanf("%d", &arr[size]);
                    size++;
                    printf("\nElement added successfully.\n");
                }
                break;
            case 2:
                // Check if the array is empty
                if (size == 0) {
                    printf("Error: Array is empty.\n");
                } else {
                    printf("\n");
                    printf("Enter the element to remove: ");
                    scanf("%d", &arr[--size]);
                    printf("\nElement removed successfully.\n");
                }
                break;
            case 3:
                printf("\n");
                printf("The array is: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 4:
                printf("\n");
                printf("Exiting...\n");
                break;
            default:
                printf("\n");
                printf("Invalid choice.\n");
        }

    } while (choice!= 4);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}