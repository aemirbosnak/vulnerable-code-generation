//Falcon-180B DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int *arr = (int *) malloc(MAX_SIZE * sizeof(int));
    int size = 0;

    while (1) {
        printf("\nEnter 1 to add an element, 2 to remove an element, or 3 to quit: ");
        int choice = scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (size == MAX_SIZE) {
                printf("Array is full.\n");
            } else {
                printf("Enter the element to add: ");
                scanf("%d", &arr[size]);
                size++;
            }
            break;
        case 2:
            if (size == 0) {
                printf("Array is empty.\n");
            } else {
                printf("Enter the element to remove: ");
                int element = scanf("%d", &element);
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
            printf("Exiting program.\n");
            free(arr);
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}