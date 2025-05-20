//Falcon-180B DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000 // maximum size of the array

int main() {
    int *array = NULL; // initialize pointer to NULL
    int size = 0; // initialize size to 0
    int choice; // variable to store user choice
    int num; // variable to store user input

    // seed the random number generator with the current time
    srand(time(NULL));

    // loop until the user chooses to exit
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Add element\n");
        printf("2. Remove element\n");
        printf("3. Display array\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // check if the array is full
                if (size == MAX_SIZE) {
                    printf("Array is full. Cannot add element.\n");
                } else {
                    printf("Enter the element to add:\n");
                    scanf("%d", &num);
                    array = (int *) realloc(array, sizeof(int) * (size + 1)); // reallocate memory
                    if (array == NULL) {
                        printf("Memory error. Cannot add element.\n");
                    } else {
                        array[size] = num;
                        size++;
                    }
                }
                break;
            case 2:
                // check if the array is empty
                if (size == 0) {
                    printf("Array is empty. Cannot remove element.\n");
                } else {
                    printf("Enter the element to remove:\n");
                    scanf("%d", &num);
                    int i;
                    for (i = 0; i < size; i++) {
                        if (array[i] == num) {
                            array = (int *) realloc(array, sizeof(int) * (size - 1)); // reallocate memory
                            if (array == NULL) {
                                printf("Memory error. Cannot remove element.\n");
                            } else {
                                size--;
                            }
                            break;
                        }
                    }
                    if (i == size) {
                        printf("Element not found.\n");
                    }
                }
                break;
            case 3:
                if (size == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array:\n");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", array[i]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}