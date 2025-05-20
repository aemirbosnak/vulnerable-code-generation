//FormAI DATASET v1.0 Category: Data recovery tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_DATA_BLOCK_SIZE 512

typedef struct {
    unsigned int blockNumber;
    char data[MAX_DATA_BLOCK_SIZE];
} Block;

Block recoverDataBlock(FILE *diskImage, unsigned int blockNumber) {
    Block recoveredBlock;
    fseek(diskImage, blockNumber*MAX_DATA_BLOCK_SIZE, SEEK_SET);
    fread(&recoveredBlock.data, sizeof(char), MAX_DATA_BLOCK_SIZE, diskImage);
    recoveredBlock.blockNumber = blockNumber;
    return recoveredBlock;
}

int main() {
    FILE *diskImage;
    char fileName[MAX_FILE_NAME_LENGTH];
    unsigned int blockCount;
    int i;

    printf("Enter the disk image file name: ");
    fgets(fileName, MAX_FILE_NAME_LENGTH, stdin);
    fileName[strcspn(fileName, "\n")] = 0;

    diskImage = fopen(fileName, "rb");
    if (!diskImage) {
        printf("Unable to open disk image file %s\n", fileName);
        return 1;
    }

    printf("Enter the number of data blocks to recover: ");
    scanf("%d", &blockCount);

    printf("Enter the block numbers to recover:\n");
    unsigned int blockNumbers[blockCount];
    for (i = 0; i < blockCount; i++) {
        scanf("%d", &blockNumbers[i]);
    }

    Block recoveredBlocks[blockCount];
    for (i = 0; i < blockCount; i++) {
        recoveredBlocks[i] = recoverDataBlock(diskImage, blockNumbers[i]);
    }

    fclose(diskImage);

    printf("Recovered data blocks:\n");
    for (i = 0; i < blockCount; i++) {
        printf("Block number: %d\nData: %s\n", recoveredBlocks[i].blockNumber, recoveredBlocks[i].data);
    }

    return 0;
}