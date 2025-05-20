//FormAI DATASET v1.0 Category: File system simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME_LENGTH 20
#define MAX_BLOCKS 20
#define BLOCK_SIZE 256

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int startBlock;
    int endBlock;
    int size;
} File;

typedef struct {
    char data[BLOCK_SIZE];
    int nextBlock;
} Block;

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int blockNo;
} OpenFile;

File files[MAX_FILES];
Block blocks[MAX_BLOCKS];
OpenFile openFiles[MAX_FILES];

int freeBlocks[MAX_BLOCKS];
int numFreeBlocks = MAX_BLOCKS;

void initialize() {
    int i;
    for (i = 0; i < MAX_BLOCKS; i++) {
        freeBlocks[i] = i;
        blocks[i].nextBlock = -1;
        memset(blocks[i].data, '\0', BLOCK_SIZE);
    }
}

int findFreeBlock() {
    if (numFreeBlocks <= 0) return -1;
    numFreeBlocks--;
    return freeBlocks[numFreeBlocks];
}

void addFreeBlock(int blockNo) {
    freeBlocks[numFreeBlocks] = blockNo;
    numFreeBlocks++;
}

void createFile(char *name) {
    int i;
    if (strlen(name) > MAX_FILE_NAME_LENGTH) {
        printf("File name too long.\n");
        return;
    }

    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("File already exists.\n");
            return;
        }
    }

    int startBlock = findFreeBlock();
    if (startBlock == -1) {
        printf("No free blocks.\n");
        return;
    }

    files[i].startBlock = startBlock;
    strcpy(files[i].name, name);
    files[i].size = 0;
}

int openFile(char *name) {
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].name, name) == 0) break;
    }

    if (i == MAX_FILES) {
        printf("File not found.\n");
        return -1;
    }

    int j;
    for (j = 0; j < MAX_FILES; j++) {
        if (openFiles[j].name[0] == '\0') break;
    }

    if (j == MAX_FILES) {
        printf("Too many files open.\n");
        return -1;
    }

    openFiles[j].blockNo = files[i].startBlock;
    strcpy(openFiles[j].name, name);
    return j;
}

void closeFile(int fd) {
    openFiles[fd].name[0] = '\0';
}

void writeFile(int fd, char *data) {
    int blockNo = openFiles[fd].blockNo;
    while (blocks[blockNo].nextBlock != -1) blockNo = blocks[blockNo].nextBlock;

    files[fd].size += strlen(data);
    int dataSize = strlen(data);
    int bytesWritten = 0;

    while (dataSize > 0) {
        if (blockNo == -1) {
            blockNo = findFreeBlock();
            if (blockNo == -1) {
                printf("No free blocks.\n");
                return;
            }

            blocks[blockNo].nextBlock = -1;
        }

        int remainingSpace = BLOCK_SIZE - strlen(blocks[blockNo].data);
        if (remainingSpace >= dataSize) {
            strncat(blocks[blockNo].data, data, dataSize);
            bytesWritten += dataSize;
            dataSize = 0;
        } else {
            strncat(blocks[blockNo].data, data, remainingSpace);
            bytesWritten += remainingSpace;
            dataSize -= remainingSpace;
        }

        if (strlen(blocks[blockNo].data) == BLOCK_SIZE) {
            blockNo = findFreeBlock();
            if (blockNo == -1) {
                printf("No free blocks.\n");
                return;
            }

            blocks[blockNo].nextBlock = -1;
        }
    }

    openFiles[fd].blockNo = blockNo;
}

void readFile(int fd, char *buffer, int length) {
    int blockNo = openFiles[fd].blockNo;
    int bytesRead = 0;

    while (length > 0 && blockNo != -1) {
        int bytesToRead = length;
        int remainingBytes = strlen(blocks[blockNo].data) - bytesRead;

        if (bytesToRead >= remainingBytes) {
            strncat(buffer, blocks[blockNo].data + bytesRead, remainingBytes);
            length -= remainingBytes;
            bytesRead = 0;
            blockNo = blocks[blockNo].nextBlock;
        } else {
            strncat(buffer, blocks[blockNo].data + bytesRead, bytesToRead);
            bytesRead += bytesToRead;
        }
    }
}

int main() {
    initialize();

    int fd = openFile("example.txt");
    writeFile(fd, "This is a test file.\n");

    char buffer[256];
    memset(buffer, '\0', 256);
    readFile(fd, buffer, 256);

    printf("%s", buffer);

    closeFile(fd);

    return 0;
}