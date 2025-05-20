//FormAI DATASET v1.0 Category: Memory management ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr, *ptr2;
    int n;

    printf("Enter the number of integers you want to allocate: ");
    scanf("%d", &n);

    // allocating memory using malloc() function
    ptr = (int*)malloc(n * sizeof(int));
    if(ptr == NULL){
        printf("Memory allocation failed. Program terminated.\n");
        exit(0);
    }

    // storing values in memory
    printf("Enter integers:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", ptr + i);
    }

    printf("Values stored in memory:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", *(ptr + i));
    }

    // reallocating memory using realloc() function
    printf("\nEnter the new size of memory: ");
    int newSize;
    scanf("%d", &newSize);

    ptr2 = realloc(ptr, newSize * sizeof(int));
    if(ptr2 == NULL){
        printf("Memory reallocation failed. Program terminated.\n");
        exit(0);
    }
    else{
        ptr = ptr2;
    }

    // storing new values in memory
    printf("Enter new integers:\n");
    for(int i = 0; i < newSize; i++){
        scanf("%d", ptr + i);
    }

    printf("New values stored in memory:\n");
    for(int i = 0; i < newSize; i++){
        printf("%d ", *(ptr + i));
    }

    // deallocating memory using free() function
    free(ptr);
    printf("\nMemory deallocated successfully.\n");

    return 0;
}