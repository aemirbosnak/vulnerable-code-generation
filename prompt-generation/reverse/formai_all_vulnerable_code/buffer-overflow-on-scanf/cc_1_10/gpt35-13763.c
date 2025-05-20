//FormAI DATASET v1.0 Category: Data recovery tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 100000 //maximum allowed file size in bytes
#define BLOCK_SIZE 512 //block size in bytes
#define MAX_FILE_NAME_LENGTH 100 //maximum allowed file name length

//structure to hold the partition info
struct partition_info {
    int start_block;
    int end_block;
};

//structure to hold file info
struct file_info {
    char name[MAX_FILE_NAME_LENGTH];
    int start_block;
    int end_block;
};

//prototype for function to recover files
void recover_files(char *disk_image_path);

int main() {
    char disk_image_path[100];

    printf("Enter the disk image path: ");
    scanf("%s", disk_image_path);

    recover_files(disk_image_path);

    printf("File recovery process completed successfully!");

    return 0;
}

void recover_files(char *disk_image_path) {
    //open the disk image file
    FILE *fp = fopen(disk_image_path, "rb");
    if (fp == NULL) {
        printf("Unable to open the disk image file\n");
        return;
    }

    //get the file size of the disk image file
    fseek(fp, 0L, SEEK_END);
    int disk_image_size = ftell(fp);
    rewind(fp);

    //check if the disk image is of valid size
    if (disk_image_size > MAX_FILE_SIZE) {
        printf("The disk image is too big to recover data from\n");
        return;
    }

    //read the first block to get the partition info
    char first_block[BLOCK_SIZE];
    fread(first_block, BLOCK_SIZE, 1, fp);
    struct partition_info pinfo;
    memcpy(&pinfo, first_block, sizeof(struct partition_info));

    //calculate the number of blocks in the partition
    int num_blocks = (pinfo.end_block - pinfo.start_block) + 1;

    //allocate memory to hold the partition data
    char *partition_data = (char *)malloc(num_blocks * BLOCK_SIZE);

    //read all the blocks of the partition into memory
    fseek(fp, pinfo.start_block * BLOCK_SIZE, SEEK_SET);
    fread(partition_data, BLOCK_SIZE, num_blocks, fp);

    //close the disk image file
    fclose(fp);

    //search for all the files in the partition
    int current_block = 0;
    int num_files = 0;
    struct file_info files[num_blocks];
    char *current_data = partition_data;

    while (current_block < num_blocks) {
        //if the current block is the start of a new file
        if (current_data[0] != 0x00 && current_data[0] != 0xe5) {
            //read the file name
            strncpy(files[num_files].name, current_data, 8);
            files[num_files].name[8] = '\0';

            //read the file extension
            strncat(files[num_files].name, ".", 1);
            strncat(files[num_files].name, current_data+8, 3);
            files[num_files].name[MAX_FILE_NAME_LENGTH-1] = '\0';

            //read the start and end block of the file
            files[num_files].start_block = (int)current_data[0x1a] + ((int)current_data[0x1b] * 256);
            files[num_files].end_block = (int)current_data[0x1c] + ((int)current_data[0x1d] * 256);

            //increment the number of files found
            num_files++;
        }

        //move the current block and data pointer to the next block
        current_block++;
        current_data += BLOCK_SIZE;
    }

    //create a directory to store the recovered files
    system("mkdir recovered_files");

    //recover each file from the partition data
    for (int i = 0; i < num_files; i++) {
        //create a file with the recovered file name
        char recovered_file_name[MAX_FILE_NAME_LENGTH + 50];
        sprintf(recovered_file_name, "recovered_files/%s", files[i].name);
        FILE *recovered_file = fopen(recovered_file_name, "wb");

        //write each block of the file to the recovered file
        char *file_data = partition_data + (files[i].start_block * BLOCK_SIZE);
        for (int j = files[i].start_block; j <= files[i].end_block; j++) {
            fwrite(file_data, BLOCK_SIZE, 1, recovered_file);
            file_data += BLOCK_SIZE;
        }

        //close the recovered file
        fclose(recovered_file);
    }

    //free the memory used by the partition data
    free(partition_data);
}