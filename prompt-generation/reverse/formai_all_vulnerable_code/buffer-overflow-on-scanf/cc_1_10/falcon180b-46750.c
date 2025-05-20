//Falcon-180B DATASET v1.0 Category: Error handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Add an element\n");
        printf("2. Remove an element\n");
        printf("3. Display the array\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (size == MAX_SIZE) {
                    printf("Array is full. Cannot add more elements.\n");
                } else {
                    printf("Enter the element to add:\n");
                    scanf("%d", &arr[size]);
                    size++;
                }
                break;

            case 2:
                if (size == 0) {
                    printf("Array is empty. Cannot remove any elements.\n");
                } else {
                    printf("Enter the element to remove:\n");
                    scanf("%d", &arr[--size]);
                }
                break;

            case 3:
                if (size == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("The array is:\n");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice!= 4);

    return 0;
}