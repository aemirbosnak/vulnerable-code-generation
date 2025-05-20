//FormAI DATASET v1.0 Category: Memory management ; Style: Linus Torvalds
/*
****  MEMORY MANAGEMENT PROGRAM  ****
            -    BY LINUS    -

The following program demonstrates an example of C Memory Management. 
The program utilizes dynamic memory allocation and free function from malloc.h library to allocate and deallocate 
memory from the heap. The program first takes input from the user for the size of the array to be dynamically 
allocated and continues to take input for each element of the array. 
When the program needs to free memory, it checks whether memory has been allocated previously and 
then frees it according to allocated memory.      

The program has been written in Linux Torvalds' style of programming - simple and elegant.
*/

#include <stdio.h>
#include <stdlib.h>

void getArray(int **ptr, int size) {
    printf("Enter the array elements: ");
    for(int i = 0; i < size; i++){
        scanf("%d", (*ptr + i));
    }
}

void printArray(int *arr, int size) {
    printf("The array elements are: ");
    for(int i = 0; i < size; i++){
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    printf("\n**** MEMORY MANAGEMENT PROGRAM ****\n");
    printf("\n***** BY LINUS *****\n\n");

    int *arr = NULL;
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = (int*)malloc(size * sizeof(int));   // dynamic memory allocation

    if(arr == NULL){    // checking if allocation was successful or not
        printf("Memory allocation failed!\n");
        exit(0);
    }
    else{
        printf("\nDynamic memory allocated successfully!\n\n");
    }

    getArray(&arr, size);   // function call to get array elements

    printArray(arr, size);  // function call to print array elements

    free(arr);  // deallocating the dynamically allocated memory

    printf("\nDynamic memory freed successfully!\n");

    return 0;
}