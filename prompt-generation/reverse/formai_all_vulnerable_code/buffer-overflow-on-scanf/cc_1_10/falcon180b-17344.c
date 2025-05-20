//Falcon-180B DATASET v1.0 Category: Memory management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int *array;
    int size = 0;
    int choice;

    srand(time(0));
    array = (int *)malloc(MAX_SIZE * sizeof(int));

    do {
        printf("Enter your choice:\n");
        printf("1. Add element\n");
        printf("2. Remove element\n");
        printf("3. Display array\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(size >= MAX_SIZE) {
                    printf("Array is full.\n");
                } else {
                    printf("Enter element to add:\n");
                    scanf("%d", &array[size]);
                    size++;
                }
                break;

            case 2:
                if(size == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Enter element to remove:\n");
                    scanf("%d", &array[--size]);
                }
                break;

            case 3:
                printf("Array: ");
                for(int i = 0; i < size; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;

            case 4:
                free(array);
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}