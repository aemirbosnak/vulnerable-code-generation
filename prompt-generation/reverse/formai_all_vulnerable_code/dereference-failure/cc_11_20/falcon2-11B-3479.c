//Falcon2-11B DATASET v1.0 Category: Error handling ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10;
    int* ptr = (int*)malloc(sizeof(int));
    
    if (ptr == NULL) {
        printf("Failed to allocate memory for ptr\n");
        return -1;
    }
    
    ptr = (int*)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Failed to allocate memory for ptr\n");
        return -1;
    }
    
    printf("Allocated memory for ptr successfully\n");
    
    for (int i = 0; i < n; i++) {
        ptr[i] = 0;
    }
    
    int* ptr2 = (int*)malloc(sizeof(int));
    if (ptr2 == NULL) {
        printf("Failed to allocate memory for ptr2\n");
        return -1;
    }
    
    printf("Allocated memory for ptr2 successfully\n");
    
    ptr2[n-1] = 1;
    
    int* ptr3 = (int*)malloc(sizeof(int));
    if (ptr3 == NULL) {
        printf("Failed to allocate memory for ptr3\n");
        return -1;
    }
    
    printf("Allocated memory for ptr3 successfully\n");
    
    ptr3 = (int*)malloc(sizeof(int));
    if (ptr3 == NULL) {
        printf("Failed to allocate memory for ptr3\n");
        return -1;
    }
    
    printf("Allocated memory for ptr3 successfully\n");
    
    for (int i = 0; i < n; i++) {
        ptr3[i] = 0;
    }
    
    printf("Copying values from ptr to ptr3\n");
    for (int i = 0; i < n; i++) {
        ptr3[i] = ptr[i];
    }
    
    printf("ptr3: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr3[i]);
    }
    
    printf("\nptr: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    
    printf("\nptr2: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr2[i]);
    }
    
    free(ptr);
    free(ptr2);
    free(ptr3);
    
    return 0;
}