//Falcon-180B DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int *array;
    int size = 0;
    int choice;

    srand(time(NULL));

    do {
        printf("Enter 1 to add an element, 2 to remove an element, 3 to display the array, 0 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (size >= MAX_SIZE) {
                    printf("Array is full.\n");
                } else {
                    array = (int *) realloc(array, sizeof(int) * (size + 1));
                    if (array == NULL) {
                        printf("Memory allocation failed.\n");
                    } else {
                        array[size] = rand() % 100;
                        size++;
                    }
                }
                break;
            case 2:
                if (size == 0) {
                    printf("Array is empty.\n");
                } else {
                    size--;
                    array = (int *) realloc(array, sizeof(int) * size);
                    if (array == NULL) {
                        printf("Memory allocation failed.\n");
                    }
                }
                break;
            case 3:
                for (int i = 0; i < size; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;
            case 0:
                free(array);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 0);

    return 0;
}