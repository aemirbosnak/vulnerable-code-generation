//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int size;
    int used;
} Block;

int main() {
    int numBlocks = 10;
    Block blocks[numBlocks];

    printf("Welcome to the RAM usage monitor!\n");
    printf("Please enter the name of the block: ");
    scanf("%s", blocks[0].name);
    printf("Enter the size of the block in bytes: ");
    scanf("%d", &blocks[0].size);

    int totalSize = blocks[0].size;
    int freeSize = blocks[0].size;

    for(int i = 1; i < numBlocks; i++) {
        printf("Enter the name of block %d: ", i);
        scanf("%s", blocks[i].name);
        printf("Enter the size of block %d in bytes: ", i);
        scanf("%d", &blocks[i].size);

        totalSize += blocks[i].size;
        freeSize += blocks[i].size;
    }

    printf("\nTotal RAM: %d bytes\n", totalSize);
    printf("Free RAM: %d bytes\n", freeSize);

    int choice;
    while(1) {
        printf("\nChoose an option:\n");
        printf("1. Allocate memory\n");
        printf("2. Free memory\n");
        printf("3. Display memory usage\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the block to allocate memory for: ");
                scanf("%s", blocks[0].name);
                printf("Enter the amount of memory to allocate in bytes: ");
                scanf("%d", &blocks[0].used);
                break;
            case 2:
                printf("Enter the name of the block to free memory for: ");
                scanf("%s", blocks[0].name);
                blocks[0].used = 0;
                break;
            case 3:
                printf("\nMemory usage:\n");
                for(int i = 0; i < numBlocks; i++) {
                    printf("Block %s: %d bytes used out of %d bytes\n", blocks[i].name, blocks[i].used, blocks[i].size);
                }
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}