//Falcon-180B DATASET v1.0 Category: Memory management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int *arr;
    int size = 0;
    int choice;

    do {
        printf("Enter the size of the array (1-1000): ");
        scanf("%d", &size);
    } while (size < 1 || size > MAX_SIZE);

    arr = (int *) malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter the elements of the array:\n");

    for (int i = 0; i < size; i++) {
        scanf("%d", arr + i);
    }

    do {
        printf("Enter your choice:\n");
        printf("1. Display the array\n");
        printf("2. Add an element\n");
        printf("3. Remove an element\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("The array is: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;

        case 2:
            printf("Enter the element to add:\n");
            scanf("%d", arr + size);
            size++;
            break;

        case 3:
            printf("Enter the element to remove:\n");
            scanf("%d", arr + size - 1);
            for (int i = size - 1; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            size--;
            break;

        case 4:
            printf("Exiting...\n");
            free(arr);
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}