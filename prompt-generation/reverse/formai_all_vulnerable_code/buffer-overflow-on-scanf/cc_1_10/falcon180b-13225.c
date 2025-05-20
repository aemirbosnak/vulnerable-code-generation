//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100 //maximum size of the array

int main(void) {
    int *ptr; //pointer to an integer
    int size; //size of the array
    int i; //counter variable

    //initialize the size of the array
    size = 0;

    //allocate memory for the array using malloc()
    ptr = (int *)malloc(MAX_SIZE * sizeof(int));

    //check if memory allocation was successful
    if(ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    //initialize the array with zeros
    for(i=0; i<MAX_SIZE; i++) {
        *(ptr+i) = 0;
    }

    //print the initial state of the array
    printf("Initial state of the array:\n");
    for(i=0; i<MAX_SIZE; i++) {
        printf("%d ", *(ptr+i));
    }
    printf("\n");

    //insert an element into the array
    printf("Enter the element to be inserted: ");
    scanf("%d", *(ptr+size));

    //increment the size of the array
    size++;

    //print the state of the array after inserting an element
    printf("State of the array after inserting an element:\n");
    for(i=0; i<MAX_SIZE; i++) {
        printf("%d ", *(ptr+i));
    }
    printf("\n");

    //delete the last element from the array
    if(size > 0) {
        size--;
        for(i=size; i<MAX_SIZE-1; i++) {
            *(ptr+i) = *(ptr+i+1);
        }
    }

    //print the state of the array after deleting an element
    printf("State of the array after deleting an element:\n");
    for(i=0; i<MAX_SIZE; i++) {
        printf("%d ", *(ptr+i));
    }
    printf("\n");

    //deallocate memory for the array using free()
    free(ptr);

    //print the final state of the array
    printf("Final state of the array:\n");
    for(i=0; i<MAX_SIZE; i++) {
        printf("%d ", *(ptr+i));
    }
    printf("\n");

    return 0;
}