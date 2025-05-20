//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000 // Maximum size of the array
#define INITIAL_SIZE 10 // Initial size of the array

int main() {
    int *array = NULL; // Pointer to the array
    int size = INITIAL_SIZE; // Current size of the array
    int max_size = MAX_SIZE; // Maximum size of the array
    int count = 0; // Count of elements in the array
    int choice; // User's choice
    bool quit = false; // Flag to quit the program

    do {
        system("clear"); // Clear the console
        printf("Sherlock Holmes' RAM Usage Monitor\n\n");
        printf("Current size of array: %d\n", size);
        printf("Maximum size of array: %d\n", max_size);
        printf("Number of elements in array: %d\n\n", count);
        printf("1. Add element\n");
        printf("2. Remove element\n");
        printf("3. Display array\n");
        printf("4. Change array size\n");
        printf("5. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (count >= size) {
                printf("Array is full. Cannot add element.\n");
            } else {
                int value;
                printf("Enter value to add: ");
                scanf("%d", &value);
                array[count] = value;
                count++;
            }
            break;
        case 2:
            if (count == 0) {
                printf("Array is empty. Cannot remove element.\n");
            } else {
                count--;
            }
            break;
        case 3:
            printf("Array:\n");
            for (int i = 0; i < count; i++) {
                printf("%d ", array[i]);
            }
            printf("\n");
            break;
        case 4:
            printf("Enter new array size (1-%d): ", max_size);
            scanf("%d", &size);
            if (size > count) {
                array = realloc(array, size * sizeof(int));
            } else {
                int *temp = malloc(size * sizeof(int));
                for (int i = 0; i < count; i++) {
                    temp[i] = array[i];
                }
                free(array);
                array = temp;
            }
            max_size = size;
            break;
        case 5:
            quit = true;
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }

    } while (!quit);

    return 0;
}