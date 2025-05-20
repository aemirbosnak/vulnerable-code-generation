//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a file's metadata
typedef struct {
    char *filename;
    unsigned int size;
    unsigned int start_block;
} file_metadata;

// Structure to store a block of data
typedef struct {
    char *data;
    unsigned int size;
} data_block;

// Function to read a file's metadata from a disk image
file_metadata *read_file_metadata(char *disk_image, char *filename) {
    // Open the disk image file
    FILE *disk_file = fopen(disk_image, "rb");
    if (disk_file == NULL) {
        printf("Error: Could not open disk image file '%s'.\n", disk_image);
        return NULL;
    }

    // Seek to the start of the file allocation table (FAT)
    fseek(disk_file, 0x200, SEEK_SET);

    // Read the FAT
    unsigned char *fat = malloc(512);
    fread(fat, 512, 1, disk_file);

    // Search the FAT for the first entry that matches the filename
    unsigned int cluster = 0;
    for (int i = 0; i < 512; i += 32) {
        char *entry_filename = fat + i;
        if (strcmp(entry_filename, filename) == 0) {
            cluster = (fat[i + 1] << 8) | fat[i + 2];
            break;
        }
    }

    // If the file was not found, return an error
    if (cluster == 0) {
        printf("Error: File '%s' not found in disk image.\n", filename);
        return NULL;
    }

    // Read the cluster size from the disk image
    fseek(disk_file, 0x1FC, SEEK_SET);
    unsigned int cluster_size = fgetc(disk_file);

    // Calculate the starting block of the file
    unsigned int start_block = cluster - 2;

    // Seek to the starting block of the file
    fseek(disk_file, start_block * cluster_size, SEEK_SET);

    // Read the file's size from the first block
    unsigned int size = fgetc(disk_file) << 8 | fgetc(disk_file);

    // Create a file metadata structure and populate it with the data we have read from the disk image
    file_metadata *metadata = malloc(sizeof(file_metadata));
    metadata->filename = strdup(filename);
    metadata->size = size;
    metadata->start_block = start_block;

    // Close the disk image file
    fclose(disk_file);

    // Return the file metadata structure
    return metadata;
}

// Function to read a data block from a disk image
data_block *read_data_block(char *disk_image, unsigned int block_number) {
    // Open the disk image file
    FILE *disk_file = fopen(disk_image, "rb");
    if (disk_file == NULL) {
        printf("Error: Could not open disk image file '%s'.\n", disk_image);
        return NULL;
    }

    // Seek to the start of the data block
    fseek(disk_file, 0x10 + block_number * 512, SEEK_SET);

    // Read the data block
    data_block *block = malloc(sizeof(data_block));
    block->data = malloc(512);
    fread(block->data, 512, 1, disk_file);
    block->size = 512;

    // Close the disk image file
    fclose(disk_file);

    // Return the data block
    return block;
}

// Function to write a data block to a disk image
void write_data_block(char *disk_image, unsigned int block_number, data_block *block) {
    // Open the disk image file
    FILE *disk_file = fopen(disk_image, "rb+");
    if (disk_file == NULL) {
        printf("Error: Could not open disk image file '%s'.\n", disk_image);
        return;
    }

    // Seek to the start of the data block
    fseek(disk_file, 0x10 + block_number * 512, SEEK_SET);

    // Write the data block
    fwrite(block->data, block->size, 1, disk_file);

    // Close the disk image file
    fclose(disk_file);
}

// Function to recover a file from a disk image
int recover_file(char *disk_image, char *filename, char *output_file) {
    // Read the file's metadata from the disk image
    file_metadata *metadata = read_file_metadata(disk_image, filename);
    if (metadata == NULL) {
        return -1;
    }

    // Create a file to store the recovered data
    FILE *output_file_stream = fopen(output_file, "wb");
    if (output_file_stream == NULL) {
        printf("Error: Could not open output file '%s'.\n", output_file);
        return -1;
    }

    // Read the data blocks from the disk image and write them to the output file
    for (unsigned int block_number = metadata->start_block; block_number < metadata->start_block + (metadata->size / 512) + 1; block_number++) {
        data_block *block = read_data_block(disk_image, block_number);
        if (block == NULL) {
            printf("Error: Could not read data block %u from disk image.\n", block_number);
            return -1;
        }

        fwrite(block->data, block->size, 1, output_file_stream);

        free(block->data);
        free(block);
    }

    // Close the output file
    fclose(output_file_stream);

    // Free the file metadata structure
    free(metadata->filename);
    free(metadata);

    // Return success
    return 0;
}

// Main function
int main(int argc, char **argv) {
    // Check that the correct number of arguments has been provided
    if (argc != 4) {
        printf("Usage: %s <disk image file> <filename> <output file>\n", argv[0]);
        return -1;
    }

    // Recover the file
    int result = recover_file(argv[1], argv[2], argv[3]);
    if (result == -1) {
        printf("Error: Could not recover file '%s' from disk image '%s'.\n", argv[2], argv[1]);
        return -1;
    }

    // Success
    printf("File '%s' recovered successfully to '%s'.\n", argv[2], argv[3]);
    return 0;
}