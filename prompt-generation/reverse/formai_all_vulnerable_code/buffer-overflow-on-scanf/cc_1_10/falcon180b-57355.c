//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int size;
} block;

block *alloc(int size) {
    block *ptr = (block *)malloc(sizeof(block));
    if (ptr == NULL) {
        printf("Out of memory\n");
        exit(0);
    }
    ptr->id = rand();
    ptr->size = size;
    return ptr;
}

int main() {
    block *root = NULL;
    int choice, size;

    while (1) {
        printf("\nRAM Usage Monitor\n");
        printf("1. Allocate memory\n");
        printf("2. Free memory\n");
        printf("3. Print memory usage\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter block size: ");
            scanf("%d", &size);
            root = alloc(size);
            break;
        case 2:
            if (root == NULL) {
                printf("No blocks allocated\n");
            } else {
                free(root);
                root = NULL;
            }
            break;
        case 3:
            printf("Total memory allocated: %d bytes\n", root->size);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}