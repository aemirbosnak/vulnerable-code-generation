//Falcon-180B DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int *ptr;
    int size;
    int choice;

    do {
        printf("Enter the size of the array (1 - %d): ", MAX_SIZE);
        scanf("%d", &size);

        if (size <= 0 || size > MAX_SIZE) {
            printf("Invalid size. Please try again.\n");
        }
    } while (size <= 0 || size > MAX_SIZE);

    ptr = (int *) malloc(size * sizeof(int));

    if (ptr == NULL) {
        printf("Memory could not be allocated.\n");
        exit(0);
    }

    printf("Enter the elements of the array:\n");

    for (int i = 0; i < size; i++) {
        scanf("%d", &ptr[i]);
    }

    do {
        printf("\nSelect an option:\n");
        printf("1. Display the array\n");
        printf("2. Modify an element\n");
        printf("3. Sort the array\n");
        printf("4. Free the memory\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nArray elements:\n");
                for (int i = 0; i < size; i++) {
                    printf("%d ", *(ptr + i));
                }
                printf("\n");
                break;

            case 2:
                printf("Enter the element to modify: ");
                scanf("%d", &ptr[0]);
                break;

            case 3:
                for (int i = 0; i < size - 1; i++) {
                    for (int j = 0; j < size - i - 1; j++) {
                        if (*(ptr + j) > *(ptr + j + 1)) {
                            int temp = *(ptr + j);
                            *(ptr + j) = *(ptr + j + 1);
                            *(ptr + j + 1) = temp;
                        }
                    }
                }
                printf("\nArray sorted:\n");
                for (int i = 0; i < size; i++) {
                    printf("%d ", *(ptr + i));
                }
                printf("\n");
                break;

            case 4:
                free(ptr);
                printf("\nMemory freed.\n");
                break;

            case 0:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 0);

    return 0;
}