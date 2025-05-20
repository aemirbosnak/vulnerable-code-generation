//Falcon-180B DATASET v1.0 Category: Error handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice = 0;
    int element = 0;

    while (choice!= 4) {
        printf("Enter your choice:\n");
        printf("1. Add element\n");
        printf("2. Remove element\n");
        printf("3. Display array\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (size == MAX_SIZE) {
                    printf("Array is full! Cannot add more elements.\n");
                } else {
                    printf("Enter the element to add:\n");
                    scanf("%d", &element);
                    arr[size] = element;
                    size++;
                }
                break;

            case 2:
                if (size == 0) {
                    printf("Array is empty! Cannot remove any element.\n");
                } else {
                    printf("Enter the element to remove:\n");
                    scanf("%d", &element);
                    for (int i = 0; i < size; i++) {
                        if (arr[i] == element) {
                            for (int j = i; j < size - 1; j++) {
                                arr[j] = arr[j + 1];
                            }
                            size--;
                            break;
                        }
                    }
                }
                break;

            case 3:
                if (size == 0) {
                    printf("Array is empty! Cannot display any element.\n");
                } else {
                    printf("The array is:\n");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}