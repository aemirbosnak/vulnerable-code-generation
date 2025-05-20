//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_FILE_SIZE 1048576

// Function to read a block from the disk
void read_block(char *buffer, int block_number) {
    FILE *disk_file;
    char filename[10];
    sprintf(filename, "block_%d", block_number);
    disk_file = fopen(filename, "rb");
    if (disk_file == NULL) {
        printf("Error: Failed to open block file.\n");
        exit(1);
    }
    fread(buffer, BLOCK_SIZE, 1, disk_file);
    fclose(disk_file);
}

// Function to write a block to the disk
void write_block(char *buffer, int block_number) {
    FILE *disk_file;
    char filename[10];
    sprintf(filename, "block_%d", block_number);
    disk_file = fopen(filename, "wb");
    if (disk_file == NULL) {
        printf("Error: Failed to open block file.\n");
        exit(1);
    }
    fwrite(buffer, BLOCK_SIZE, 1, disk_file);
    fclose(disk_file);
}

// Function to read a file from the disk
void read_file(char *filename, char *buffer) {
    FILE *disk_file;
    disk_file = fopen(filename, "rb");
    if (disk_file == NULL) {
        printf("Error: Failed to open file.\n");
        exit(1);
    }
    fread(buffer, MAX_FILE_SIZE, 1, disk_file);
    fclose(disk_file);
}

// Function to write a file to the disk
void write_file(char *filename, char *buffer) {
    FILE *disk_file;
    disk_file = fopen(filename, "wb");
    if (disk_file == NULL) {
        printf("Error: Failed to open file.\n");
        exit(1);
    }
    fwrite(buffer, MAX_FILE_SIZE, 1, disk_file);
    fclose(disk_file);
}

// Function to recover a deleted file
void recover_file(char *filename) {
    char buffer[MAX_FILE_SIZE];
    char block_buffer[BLOCK_SIZE];
    int block_number = 0;
    read_file(filename, buffer);
    int file_size = strlen(buffer);
    int block_count = (file_size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    for (int i = 0; i < block_count; i++) {
        memcpy(block_buffer, buffer + i * BLOCK_SIZE, BLOCK_SIZE);
        write_block(block_buffer, block_number);
        block_number++;
    }
}

// Main function
int main() {
    char filename[100];
    printf("Enter the name of the deleted file: ");
    scanf("%s", filename);
    recover_file(filename);
    printf("File recovery completed.\n");
    return 0;
}