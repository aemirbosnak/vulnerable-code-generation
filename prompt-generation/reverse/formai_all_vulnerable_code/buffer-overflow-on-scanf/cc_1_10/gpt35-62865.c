//FormAI DATASET v1.0 Category: File system simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F_NAME_LENGTH 20    // maximum length of file names
#define MAX_FILES 10        // maximum number of files
#define BLOCK_SIZE 512      // size of virtual block in bytes

typedef struct File {
    char name[F_NAME_LENGTH];   // name of the file
    int size;                   // size of the file in bytes
    int *blocks;                // virtual block numbers of the file
} File;

// function prototypes
void init_file_system();
void create_file(char*);
void delete_file(char*);
void write_file(char*, char*);
void read_file(char*);

// global variables
char *virtual_fs;               // virtual file system (array of bytes)
int *fs_blocks;                 // array of virtual block IDs
File file_table[MAX_FILES];     // table of files in the file system
int next_block;                 // next available virtual block ID
int num_files;                  // number of files in the file system

int main() {
    init_file_system();

    char option = ' ';
    while (option != 'Q') {
        printf("\nVirtual File System Menu:\n");
        printf("C - Create file\n");
        printf("D - Delete file\n");
        printf("W - Write to file\n");
        printf("R - Read from file\n");
        printf("Q - Quit\n");
        printf("Enter option: ");
        scanf(" %c", &option);

        char filename[F_NAME_LENGTH];
        switch (option) {
            case 'C':
                printf("Enter new file name: ");
                scanf("%s", filename);
                create_file(filename);
                break;
            case 'D':
                printf("Enter file name to delete: ");
                scanf("%s", filename);
                delete_file(filename);
                break;
            case 'W':
                printf("Enter file name to write to: ");
                scanf("%s", filename);
                char content[BLOCK_SIZE];
                printf("Enter content to write: ");
                scanf("%s", content);   // assumes content fits in one block
                write_file(filename, content);
                break;
            case 'R':
                printf("Enter file name to read from: ");
                scanf("%s", filename);
                read_file(filename);
                break;
            case 'Q':
                break;
            default:
                printf("Invalid option.\n");
        }
    }

    free(virtual_fs);
    free(fs_blocks);

    return 0;
}

void init_file_system() {
    num_files = 0;
    next_block = 0;
    fs_blocks = malloc(MAX_FILES * sizeof(int));

    // initialize file system with 10 blocks
    virtual_fs = malloc(BLOCK_SIZE * MAX_FILES);
    memset(virtual_fs, '\0', BLOCK_SIZE * MAX_FILES);
}

void create_file(char *filename) {
    if (num_files >= MAX_FILES) {
        printf("Error: file system is full.\n");
        return;
    }

    // check if file already exists
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_table[i].name, filename) == 0) {
            printf("Error: file already exists.\n");
            return;
        }
    }

    // create new file
    File new_file = { 0 };
    strcpy(new_file.name, filename);
    new_file.size = 0;
    new_file.blocks = malloc(sizeof(int));
    file_table[num_files] = new_file;
    num_files++;
}

void delete_file(char *filename) {
    int file_index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_table[i].name, filename) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        printf("Error: file not found.\n");
        return;
    }

    // free blocks allocated for file
    for (int i = 0; i < file_table[file_index].size; i++) {
        int block_id = file_table[file_index].blocks[i];
        fs_blocks[block_id] = 0;
        memset(&virtual_fs[block_id * BLOCK_SIZE], '\0', BLOCK_SIZE);
    }

    // remove file from file system
    free(file_table[file_index].blocks);
    for (int i = file_index; i < num_files - 1; i++) {
        file_table[i] = file_table[i + 1];
    }
    num_files--;
}

void write_file(char *filename, char *content) {
    int file_index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_table[i].name, filename) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        printf("Error: file not found.\n");
        return;
    }

    // calculate number of blocks needed for content
    int num_blocks = strlen(content) / BLOCK_SIZE + 1;
    if (strlen(content) % BLOCK_SIZE == 0) {
        num_blocks--;
    }

    // check if enough blocks are available in file system
    int count = 0;
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs_blocks[i] == 0) {
            count++;
            if (count >= num_blocks) {
                break;
            }
        }
    }
    if (count < num_blocks) {
        printf("Error: file system is full.\n");
        return;
    }

    // allocate blocks for file
    file_table[file_index].size = strlen(content);
    file_table[file_index].blocks = realloc(file_table[file_index].blocks,
                                            num_blocks * sizeof(int));
    int index = 0;
    for (int i = 0; i < MAX_FILES && index < num_blocks; i++) {
        if (fs_blocks[i] == 0) {
            file_table[file_index].blocks[index] = i;
            fs_blocks[i] = 1;
            memcpy(&virtual_fs[i * BLOCK_SIZE], content + (index * BLOCK_SIZE),
                   BLOCK_SIZE);
            index++;
        }
    }
}

void read_file(char *filename) {
    int file_index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_table[i].name, filename) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        printf("Error: file not found.\n");
        return;
    }

    printf("Content of %s:\n", filename);
    for (int i = 0; i < file_table[file_index].size; i++) {
        int block_id = file_table[file_index].blocks[i];
        printf("%.*s", BLOCK_SIZE, &virtual_fs[block_id * BLOCK_SIZE]);
    }
    printf("\n");
}