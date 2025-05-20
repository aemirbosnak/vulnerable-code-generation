//FormAI DATASET v1.0 Category: Data recovery tool ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

#define BLOCK_SIZE 4096 // Block size set as 4KB

// Struct defined for file's metadata
typedef struct{
    char name[50];
    int size;
    int start_block;
    int num_blocks;
} FileMetadata;

void recover_file(char* disk_image, char* file_name){
    // Open the disk image file
    FILE *fp = fopen(disk_image, "rb");
    if(fp == NULL){
        printf("Unable to open disk image file!\n");
        return;
    }

    // Read the metadata block of the disk image
    FileMetadata metadata[100];
    fread(metadata, sizeof(FileMetadata), 100, fp);

    // Find the file with the given name
    int file_index = -1;
    for(int i = 0; i < 100; i++){
        if(strcmp(metadata[i].name, file_name) == 0){
            file_index = i;
            break;
        }
    }

    // If the file is not found, return an error message
    if(file_index == -1){
        printf("File not found on disk image!\n");
        return;
    }

    // Calculate the total number of blocks to read
    int total_blocks = metadata[file_index].num_blocks;

    // Calculate the start block and offset of the file data
    int starting_block = metadata[file_index].start_block;
    int data_offset = starting_block * BLOCK_SIZE;

    // Allocate memory for the file data
    char *file_data = (char*)malloc(total_blocks * BLOCK_SIZE);
    if(file_data == NULL){
        printf("Memory allocation error!\n");
        return;
    }

    // Read the file data from the disk image
    fseek(fp, data_offset, SEEK_SET);
    fread(file_data, BLOCK_SIZE, total_blocks, fp);

    // Write the file data to a new file with the same name
    FILE *new_fp = fopen(file_name, "wb");
    fwrite(file_data, BLOCK_SIZE, total_blocks, new_fp);

    // Free the allocated memory and close the files
    free(file_data);
    fclose(fp);
    fclose(new_fp);

    printf("File '%s' recovered successfully!\n", file_name);
}

int main(){
    char disk_image[50], file_name[50];

    printf("Enter the name of the disk image file: ");
    scanf("%s", disk_image);

    printf("Enter the name of the file to recover: ");
    scanf("%s", file_name);

    // Call the file recovery function
    recover_file(disk_image, file_name);

    return 0;
}