//FormAI DATASET v1.0 Category: File system simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#define MAX_FILES 100

// Structure to represent a file
typedef struct {
    char name[50];
    int size;
    int start_block;
} File;

// Structure to represent a block
typedef struct {
    int is_allocated;
} Block;

// Structure to represent the file system
typedef struct {
    File files[MAX_FILES];
    Block blocks[1000];
    int num_files;
} FileSystem;

int find_free_block(FileSystem fs) {
    for (int i = 0; i < 1000; i++) {
        if (fs.blocks[i].is_allocated == 0) {
            fs.blocks[i].is_allocated = 1;
            return i;
        }
    }
    return -1;
}

void create_file(FileSystem *fs, char name[], int size) {
    if (fs->num_files == MAX_FILES) {
        printf("Error: No more space to create file.\n");
        return;
    }
    int start_block = find_free_block(*fs);
    if (start_block == -1) {
        printf("Error: No more space in file system.\n");
        return;
    }
    File new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    new_file.start_block = start_block;
    fs->files[fs->num_files++] = new_file;
    printf("File %s created successfully.\n", name);
}

void delete_file(FileSystem *fs, char name[]) {
    int index = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: File %s not found.\n", name);
        return;
    }
    for (int i = fs->files[index].start_block; i < fs->files[index].start_block + fs->files[index].size; i++) {
        fs->blocks[i].is_allocated = 0;
    }
    for (int i = index; i < fs->num_files - 1; i++) {
        fs->files[i] = fs->files[i+1];
    }
    fs->num_files--;
    printf("File %s deleted successfully.\n", name);
}

void list_files(FileSystem fs) {
    printf("%-30s%-10s%-10s\n", "Name", "Size", "Start Block");
    for (int i = 0; i < fs.num_files; i++) {
        printf("%-30s%-10d%-10d\n", fs.files[i].name, fs.files[i].size, fs.files[i].start_block);
    }
}

int main() {
    FileSystem fs = { .num_files = 0 };
    char choice, name[50];
    int size;
    while (1) {
        printf("\n1. Create file\n");
        printf("2. Delete file\n");
        printf("3. List files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter file size in blocks: ");
                scanf("%d", &size);
                create_file(&fs, name, size);
                break;
            case '2':
                printf("Enter file name: ");
                scanf("%s", name);
                delete_file(&fs, name);
                break;
            case '3':
                list_files(fs);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}