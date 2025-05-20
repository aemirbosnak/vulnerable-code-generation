//FormAI DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>

int main() {

    int *ptr1, *ptr2;

    //Allocate memory to ptr1 for 5 integers
    ptr1 = (int*)malloc(5*sizeof(int));
    if (ptr1 == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
        printf("Memory allocated for 5 integers.\n");
    }

    //Allocate memory to ptr2 for 10 integers
    ptr2 = (int*)calloc(10, sizeof(int));
    if (ptr2 == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
        printf("Memory allocated for 10 integers.\n");
    }

    printf("\nEnter 5 integers:\n");
    for(int i=0;i<5;i++) {
        scanf("%d", (ptr1+i));
    }

    printf("Entered integers are:\n");
    for(int i=0;i<5;i++) {
        printf("%d ", *(ptr1+i));
    }

    printf("\n\nEnter 10 integers:\n");
    for(int i=0;i<10;i++) {
        scanf("%d", (ptr2+i));
    }

    printf("Entered integers are:\n");
    for(int i=0;i<10;i++) {
        printf("%d ", *(ptr2+i));
    }

    //Reallocation of memory to ptr1 for 10 integers
    ptr1 = (int*)realloc(ptr1, 10*sizeof(int));
    if (ptr1 == NULL) {
        printf("\nMemory not re-allocated.\n");
        exit(0);
    }
    else {
        printf("\nMemory successfully re-allocated for 10 integers.\n");
    }

    printf("\nEnter 5 more integers:\n");
    for(int i=5;i<10;i++) {
        scanf("%d", (ptr1+i));
    }

    printf("Entered integers are:\n");
    for(int i=0;i<10;i++) {
        printf("%d ", *(ptr1+i));
    }

    //Deallocation of memory
    free(ptr1);
    free(ptr2);

    return 0;
}