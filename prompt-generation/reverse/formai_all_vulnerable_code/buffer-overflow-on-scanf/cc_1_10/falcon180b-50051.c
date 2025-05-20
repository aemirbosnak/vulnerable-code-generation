//Falcon-180B DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum size of the array

int main() {
    int size = 0;
    int *array = NULL;
    int choice;

    while(1) {
        printf("\nEnter 1 to add an element to the array\nEnter 2 to remove an element from the array\nEnter 3 to display the array\nEnter 0 to exit\n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                if(size == MAX_SIZE) {
                    printf("Array is full\n");
                } else {
                    printf("Enter the element to be added\n");
                    scanf("%d",&array[size]);
                    size++;
                }
                break;

            case 2:
                if(size == 0) {
                    printf("Array is empty\n");
                } else {
                    printf("Enter the element to be removed\n");
                    scanf("%d",&array[--size]);
                }
                break;

            case 3:
                printf("Array elements are:\n");
                for(int i=0;i<size;i++) {
                    printf("%d\n",array[i]);
                }
                break;

            case 0:
                printf("Exiting program\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}