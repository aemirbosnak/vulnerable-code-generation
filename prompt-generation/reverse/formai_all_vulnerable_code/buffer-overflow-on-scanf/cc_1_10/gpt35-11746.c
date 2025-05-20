//FormAI DATASET v1.0 Category: File system simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 1024
#define BLOCK_SIZE 1024
#define MAX_FILE_NAME 256

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
    int block_ptrs[10];
} file;

typedef struct {
    int file_count;
    file files[1024];
} file_system;

void create_file(file_system* fs) {
    char name[MAX_FILE_NAME];
    printf("Enter name of file: ");
    scanf("%s", &name);

    int size;
    printf("Enter size of file: ");
    scanf("%d", &size);

    int required_blocks = (int) ceil((float) size / BLOCK_SIZE);
    if (required_blocks > MAX_BLOCKS) {
        printf("File size exceeds maximum available storage.\n");
        return;
    }

    int block_ptrs[10];
    for (int i = 0; i < 10; i++) {
        block_ptrs[i] = -1;
    }

    int allocated_blocks = 0;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (fs->files[i].size == 0) {
            block_ptrs[allocated_blocks] = i;
            allocated_blocks++;
        }

        if (allocated_blocks == required_blocks) {
            break;
        }
    }

    if (allocated_blocks < required_blocks) {
        printf("Not enough free space available.\n");
        return;
    }

    file new_file = {
        .size = size
    };

    strncpy(new_file.name, name, MAX_FILE_NAME);

    memcpy(new_file.block_ptrs, block_ptrs, sizeof(block_ptrs));

    fs->files[fs->file_count] = new_file;
    fs->file_count++;
}

void delete_file(file_system* fs) {
    char name[MAX_FILE_NAME];
    printf("Enter name of file to delete: ");
    scanf("%s", &name);

    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            memset(&fs->files[i], 0, sizeof(file));
            fs->file_count--;
            printf("File %s deleted.\n", name);
            return;
        }
    }

    printf("File %s not found.\n", name);
}

void list_files(file_system* fs) {
    printf("Total files: %d\n", fs->file_count);
    for (int i = 0; i < fs->file_count; i++) {
        printf("%s (%d bytes)\n", fs->files[i].name, fs->files[i].size);
    }
}

int main() {
    file_system fs = {0};
    int choice;
    do {
        printf("Select an option:\n");
        printf("1. Create a file\n");
        printf("2. Delete a file\n");
        printf("3. List files\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_file(&fs);
                break;
            case 2:
                delete_file(&fs);
                break;
            case 3:
                list_files(&fs);
                break;
            case 4:
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}