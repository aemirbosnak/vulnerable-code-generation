//Falcon-180B DATASET v1.0 Category: Memory management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 1000

int main() {
    int *array;
    int size = 0;
    int choice = 0;
    int element = 0;

    array = (int*)malloc(MAX_ARRAY_SIZE * sizeof(int));
    if (array == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }

    while (choice!= 5) {
        printf("\n");
        printf("1. Add element\n");
        printf("2. Remove element\n");
        printf("3. Display array\n");
        printf("4. Change array size\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &element);
                array[size++] = element;
                break;
            case 2:
                printf("Enter element to remove: ");
                scanf("%d", &element);
                for (int i = 0; i < size; i++) {
                    if (array[i] == element) {
                        for (int j = i; j < size - 1; j++) {
                            array[j] = array[j + 1];
                        }
                        size--;
                        break;
                    }
                }
                break;
            case 3:
                printf("Array: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;
            case 4:
                printf("Enter new array size: ");
                scanf("%d", &size);
                array = (int*)realloc(array, size * sizeof(int));
                if (array == NULL) {
                    printf("Error: Memory could not be reallocated.\n");
                    exit(1);
                }
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    free(array);
    return 0;
}