//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    int size;
    int *array;
} MemoryBlock;

int main() {
    int numBlocks = 0;
    MemoryBlock blocks[MAX_SIZE];
    char choice;

    do {
        printf("\nRomeo and Juliet's RAM Usage Monitor\n");
        printf("-------------------------------------\n");
        printf("1. Allocate memory\n");
        printf("2. Deallocate memory\n");
        printf("3. Display memory blocks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter the size of the memory block: ");
                int size;
                scanf("%d", &size);
                if(numBlocks >= MAX_SIZE) {
                    printf("No more blocks available.\n");
                } else {
                    blocks[numBlocks].size = size;
                    blocks[numBlocks].array = (int *)malloc(size * sizeof(int));
                    if(blocks[numBlocks].array == NULL) {
                        printf("Memory allocation failed.\n");
                    } else {
                        strcpy(blocks[numBlocks].name, "Block");
                        sprintf(&blocks[numBlocks].name[5], "%d", numBlocks+1);
                        numBlocks++;
                    }
                }
                break;

            case '2':
                printf("Enter the name of the memory block to deallocate: ");
                char name[50];
                scanf("%s", name);
                int index;
                for(index = 0; index < numBlocks; index++) {
                    if(strcmp(name, blocks[index].name) == 0) {
                        free(blocks[index].array);
                        strcpy(blocks[index].name, "");
                        blocks[index].size = 0;
                        break;
                    }
                }
                if(index == numBlocks) {
                    printf("Memory block not found.\n");
                }
                break;

            case '3':
                printf("\nMemory blocks:\n");
                for(int i = 0; i < numBlocks; i++) {
                    if(blocks[i].size > 0) {
                        printf("%s (%d)\n", blocks[i].name, blocks[i].size);
                    }
                }
                break;

            case '4':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice!= '4');

    return 0;
}