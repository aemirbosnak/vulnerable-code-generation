//Falcon-180B DATASET v1.0 Category: Memory management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void* my_malloc(size_t size);
void my_free(void* ptr);

int main() {
    void* ptr;
    int choice, size;

    do {
        printf("Memory Management Example Program\n");
        printf("1. Allocate memory\n");
        printf("2. Free memory\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the size of memory to allocate: ");
                scanf("%d", &size);
                ptr = my_malloc(size);
                if(ptr!= NULL)
                    printf("Memory allocated successfully.\n");
                else
                    printf("Memory allocation failed.\n");
                break;
            case 2:
                printf("Enter the address of memory to free: ");
                scanf("%p", &ptr);
                my_free(ptr);
                printf("Memory freed successfully.\n");
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 3);

    return 0;
}

// Our own implementation of malloc()
void* my_malloc(size_t size) {
    void* ptr;
    ptr = malloc(size);
    if(ptr == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    return ptr;
}

// Our own implementation of free()
void my_free(void* ptr) {
    free(ptr);
}