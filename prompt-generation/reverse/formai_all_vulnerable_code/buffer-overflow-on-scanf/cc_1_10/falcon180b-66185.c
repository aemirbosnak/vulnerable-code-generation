//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to read a block of data from the disk
void readBlock(int blockNumber, char* buffer) {
    printf("Reading block %d...\n", blockNumber);
    for (int i = 0; i < 512; i++) {
        buffer[i] = getc(stdin);
    }
}

// Function to write a block of data to the disk
void writeBlock(int blockNumber, char* buffer) {
    printf("Writing block %d...\n", blockNumber);
    for (int i = 0; i < 512; i++) {
        putc(buffer[i], stdout);
    }
}

// Function to recover a deleted file
void recoverFile(char* filename) {
    int inodeNumber = 0;
    int blockNumber = 0;
    char buffer[512];

    // Search for the inode number of the deleted file
    printf("Searching for inode number of %s...\n", filename);
    while (inodeNumber == 0) {
        readBlock(blockNumber, buffer);
        for (int i = 0; i < 512; i++) {
            if (buffer[i] == 0) {
                inodeNumber = *(int*)(buffer + i + 4);
                break;
            }
        }
        blockNumber++;
    }

    // Recover the contents of the deleted file
    printf("Recovering %s...\n", filename);
    readBlock(inodeNumber, buffer);
    printf("Contents of %s:\n%s", filename, buffer);
}

int main() {
    char filename[100];
    printf("Enter the name of the deleted file: ");
    scanf("%s", filename);
    recoverFile(filename);
    return 0;
}