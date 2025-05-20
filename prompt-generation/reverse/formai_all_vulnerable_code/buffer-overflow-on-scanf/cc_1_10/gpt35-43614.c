//FormAI DATASET v1.0 Category: File system simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_FILE_COUNT 10

struct inode {
    char file_name[MAX_FILE_NAME_SIZE];
    int file_size;
    int block_address[10];
};

int disk_blocks[100] = {0};
struct inode files[MAX_FILE_COUNT] = {0};
int file_count = 0;

void file_create() {
    char file_name[MAX_FILE_NAME_SIZE];
    int file_size, block_req, index, valid, block_address[10];
    printf("Enter the name of the file to be created: ");
    scanf("%s", file_name);
    printf("Enter the size of the file in blocks(1 block = 1KB): ");
    scanf("%d", &file_size);

    block_req = file_size;
    if (block_req > 10) {
        printf("Error: File size too large. Maximum file size is 10 blocks.\n");
        return;
    }

    valid = 0;
    for (int i = 0; i < 100; i++) {
        if (disk_blocks[i] == 0) {
            block_address[valid++] = i;
            if (valid == block_req)
                break;
        }
    }

    if (valid < block_req) {
        printf("Error: Not enough free space on disk. Cannot create file.\n");
        return;
    }

    struct inode new_file;
    strcpy(new_file.file_name, file_name);
    new_file.file_size = file_size;
    for (int i = 0; i < block_req; i++)
        new_file.block_address[i] = block_address[i];
    files[file_count++] = new_file;

    printf("File created successfully!\n");
}

void file_delete() {
    char file_name[MAX_FILE_NAME_SIZE];
    printf("Enter the name of the file to be deleted: ");
    scanf("%s", file_name);

    int index = -1;
    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].file_name, file_name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: File not found.\n");
        return;
    }

    for (int i = 0; i < files[index].file_size; i++)
        disk_blocks[files[index].block_address[i]] = 0;

    for (int i = index; i < file_count - 1; i++)
        files[i] = files[i+1];

    file_count--;
    printf("File deleted successfully!\n");
}

void file_display() {
    if (file_count == 0) {
        printf("No files found.\n");
        return;
    }

    printf("File Name\tSize\tBlock Addresses\n");
    for (int i = 0; i < file_count; i++) {
        printf("%s\t\t%d\t[", files[i].file_name, files[i].file_size);
        for (int j = 0; j < files[i].file_size; j++) {
            printf("%d", files[i].block_address[j]);
            if (j != files[i].file_size-1)
                printf(", ");
        }
        printf("]\n");
    }
}

int main() {
    int choice;

    printf("\nC File System Simulation\n");
    printf("-------------------------\n");

    do {
        printf("\nChoose an option from the menu:\n");
        printf("1. Create a new file\n");
        printf("2. Delete an existing file\n");
        printf("3. Display all files\n");
        printf("4. Exit\n");
        printf("Option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                file_create();
                break;
            case 2:
                file_delete();
                break;
            case 3:
                file_display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}