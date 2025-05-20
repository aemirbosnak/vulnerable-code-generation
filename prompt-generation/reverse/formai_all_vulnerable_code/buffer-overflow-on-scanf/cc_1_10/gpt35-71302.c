//FormAI DATASET v1.0 Category: File system simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 50
#define BLOCK_SIZE 512
#define MAX_SIZE MAX_FILES*BLOCK_SIZE

int free_blocks = MAX_FILES; //initialize number of free blocks to the max

typedef struct {
    char filename[20];
    int size;
    int blocks[10];
} File;

File files[MAX_FILES];
char disk[MAX_SIZE];

int get_block() {
    if (free_blocks == 0) {
        printf("ERROR: Disk is full!\n");
        return -1;
    }
    int i;
    for (i=0; i<MAX_FILES; i++) {
        if (files[i].size == 0) {
            free_blocks--;
            return i*BLOCK_SIZE; //return starting position of block
        }
    }
}

void write_to_disk(int block_number, char *data) {
    memcpy(disk + block_number, data, BLOCK_SIZE);
}

void read_from_disk(int block_number, char *data) {
    memcpy(data, disk + block_number, BLOCK_SIZE);
}

void create_file() {
    char filename[20];
    int size, block_num;
    printf("Enter file name: ");
    scanf("%s", filename);
    printf("Enter file size: ");
    scanf("%d", &size);
    block_num = size / BLOCK_SIZE;
    if (size % BLOCK_SIZE != 0) block_num += 1;
    if (block_num > free_blocks) {
        printf("ERROR: Disk space is not sufficient!\n");
        return;
    }
    int i , j;
    for (i=0; i<MAX_FILES; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            printf("ERROR: File already exists!\n");
            return;
        }
    }
    //populate file data structure
    int blocks[block_num];
    for (i=0; i<block_num; i++) {
        int block = get_block();
        if (block == -1) {
            printf("ERROR: Disk is full!\n");
            return;
        }
        blocks[i] = block;
    }
    File file;
    strcpy(file.filename, filename);
    file.size = size;
    memcpy(file.blocks, blocks, block_num * sizeof(int));
    //write file structure to disk
    write_to_disk(get_block(), (char *)&file);
}

void read_file() {
    char filename[20];
    printf("Enter file name: ");
    scanf("%s", filename);
    int i;
    for (i=0; i<MAX_FILES; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            char data[files[i].size];
            int j;
            for (j=0; j<files[i].size/BLOCK_SIZE; j++) {
                read_from_disk(files[i].blocks[j], data + j*BLOCK_SIZE);
            }
            if (files[i].size % BLOCK_SIZE != 0) { //if file size is not a multiple of block size
                read_from_disk(files[i].blocks[j], data + j*BLOCK_SIZE);
            }
            printf("File contents:\n%s\n", data);
            return;
        }
    }
    printf("ERROR: File not found!\n");
}

int main() {
    int option;
    printf("C File System Simulation\n");
    while (1) {
        printf("Select an option:\n1. Create File\n2. Read File\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                create_file();
                break;
            case 2:
                read_file();
                break;
            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}