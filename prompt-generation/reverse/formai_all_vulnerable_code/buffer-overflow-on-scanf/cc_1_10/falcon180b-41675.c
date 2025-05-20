//Falcon-180B DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_SIZE 100

int main() {
    int *ptr;
    int size = 0;
    int choice;
    int value;

    do {
        printf("\n\nMemory Management Program\n");
        printf("1. Allocate Memory\n2. Deallocate Memory\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the size of the memory block: ");
                scanf("%d", &value);
                if(value <= MAX_SIZE) {
                    ptr = (int *)malloc(value * sizeof(int));
                    if(ptr!= NULL) {
                        printf("Memory block allocated successfully\n");
                        size += value;
                    } else {
                        printf("Memory allocation failed\n");
                    }
                } else {
                    printf("Invalid block size\n");
                }
                break;

            case 2:
                if(size > 0) {
                    printf("Enter the size of the memory block to deallocate: ");
                    scanf("%d", &value);
                    if(value <= size) {
                        free(ptr);
                        size -= value;
                        printf("Memory block deallocated successfully\n");
                    } else {
                        printf("Invalid block size\n");
                    }
                } else {
                    printf("No memory block allocated yet\n");
                }
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice!= 3);

    return 0;
}