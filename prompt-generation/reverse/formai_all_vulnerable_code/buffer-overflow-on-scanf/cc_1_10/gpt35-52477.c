//FormAI DATASET v1.0 Category: File system simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let's start by defining some constants
#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_COUNT 10
#define BLOCK_SIZE 512
#define DISK_SIZE 1048576 // 1MB disk

// We'll represent our virtual disk as an array of byte
char disk[DISK_SIZE];

// And we'll use this to map which blocks are free/used
int block_map[DISK_SIZE/BLOCK_SIZE];

// And we'll define our file structure
typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int size;
    int start_block;
} file_t;

// We'll use this to keep track of our files
file_t files[MAX_FILE_COUNT];
int file_count = 0;

int find_free_block() {
    for (int i = 0; i < DISK_SIZE/BLOCK_SIZE; i++) {
        if (!block_map[i]) {
            block_map[i] = 1;
            return i;
        }
    }
    return -1; // no free blocks
}

void create_file(char* name, int size) {
    if (strlen(name) > MAX_FILENAME_LENGTH) {
        printf("Filename is too long.\n");
        return;
    }
    if (file_count >= MAX_FILE_COUNT) {
        printf("Too many files.\n");
        return;
    }
    // find free blocks to allocate to the file
    int blocks_needed = size/BLOCK_SIZE + (size % BLOCK_SIZE != 0);
    int block[blocks_needed];
    for (int i = 0; i < blocks_needed; i++) {
        block[i] = find_free_block();
        if (block[i] == -1) {
            printf("Could not allocate enough space for the file.\n");
            return;
        }
    }
    // create the file
    file_t new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    new_file.start_block = block[0];
    files[file_count++] = new_file;
    // write data to disk
    int bytes_written = 0;
    for (int i = 0; i < blocks_needed; i++) {
        int target_block = block[i]*BLOCK_SIZE;
        int bytes_to_write = size - bytes_written;
        if (bytes_to_write > BLOCK_SIZE) {
            bytes_to_write = BLOCK_SIZE;
        }
        char data[bytes_to_write];
        memset(data, '!', bytes_to_write); // fill data with dummy characters
        memcpy(&disk[target_block], data, bytes_to_write);
        bytes_written += bytes_to_write;
    }
    printf("File successfully created.\n");
}

void list_files() {
    printf("Listing files:\n");
    for (int i = 0; i < file_count; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

void delete_file(char* name) {
    int index = -1;
    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("File not found.\n");
        return;
    }
    // free up blocks
    int blocks_needed = files[index].size/BLOCK_SIZE + (files[index].size % BLOCK_SIZE != 0);
    for (int i = 0; i < blocks_needed; i++) {
        int block = files[index].start_block + i;
        block_map[block] = 0;
    }
    // remove file from files array
    for (int i = index; i < file_count-1; i++) {
        files[i] = files[i+1];
    }
    file_count--;
    printf("File successfully deleted.\n");
}

int main() {
    printf("Welcome to the C File System simulation!\n");
    printf("Initializing disk...\n");
    memset(block_map, 0, DISK_SIZE/BLOCK_SIZE);
    printf("What would you like to do?\n");
    printf("1. Create a file\n");
    printf("2. List files\n");
    printf("3. Delete a file\n");
    printf("4. Quit\n");
    int choice;
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char name[MAX_FILENAME_LENGTH];
                int size;
                printf("Enter filename: ");
                scanf("%s", &name);
                printf("Enter size (in bytes): ");
                scanf("%d", &size);
                create_file(name, size);
                break;
            }
            case 2: {
                list_files();
                break;
            }
            case 3: {
                char name[MAX_FILENAME_LENGTH];
                printf("Enter filename: ");
                scanf("%s", &name);
                delete_file(name);
                break;
            }
            case 4: {
                printf("Goodbye!\n");
                return 0;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    } while (1);
}