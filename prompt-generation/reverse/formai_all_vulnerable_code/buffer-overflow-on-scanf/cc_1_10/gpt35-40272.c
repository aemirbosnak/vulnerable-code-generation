//FormAI DATASET v1.0 Category: File system simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

int blocks[MAX_BLOCKS];

// Function to initialize the file system
void initialize() {
    for(int i = 0; i < MAX_BLOCKS; i++) {
        blocks[i] = -1;
    }
}

// Function to allocate space for file
void allocate(int file_id, int size) {
    int block_no = rand() % MAX_BLOCKS;
    int blocks_allocated = 0;

    while(blocks_allocated < size) {
        if(blocks[block_no] == -1) {
            blocks[block_no] = file_id;
            blocks_allocated++;
        }
        block_no = rand() % MAX_BLOCKS;
    }
}

// Function to deallocate space for file
void deallocate(int file_id) {
    for(int i = 0; i < MAX_BLOCKS; i++) {
        if(blocks[i] == file_id) {
            blocks[i] = -1;
        }
    }
}

// Function to display the status of the file system
void display() {
    printf("Block No.\tFile ID\n");
    for(int i = 0; i < MAX_BLOCKS; i++) {
        printf("%d\t\t%d\n", i, blocks[i]);
    }
}

int main() {
    int file_count, file_id, size, choice;

    printf("Enter the number of files: ");
    scanf("%d", &file_count);

    initialize();

    for(int i = 0; i < file_count; i++) {
        printf("Enter the file ID for file %d: ", i + 1);
        scanf("%d", &file_id);
        printf("Enter the size of file %d: ", i + 1);
        scanf("%d", &size);

        allocate(file_id, size);
    }

    do {
        printf("Enter 1 to deallocate a file\nEnter 2 to display the status of the file system\nEnter 3 to exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the file ID to deallocate: ");
                scanf("%d", &file_id);
                deallocate(file_id);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}