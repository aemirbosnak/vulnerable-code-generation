//FormAI DATASET v1.0 Category: File system simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024
#define FILE_NAME_SIZE 64
#define MAX_FILES 100
#define MAX_BLOCKS 4096

typedef struct {
    char name[FILE_NAME_SIZE];
    int start_block;
    int num_blocks;
} inode;

typedef struct {
    char data[BLOCK_SIZE];
} block;

inode files[MAX_FILES];
block blocks[MAX_BLOCKS];

int num_files = 0;
int num_blocks = 0;

int find_free_block() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (blocks[i].data[0] == '\0') {
            return i;
        }
    }
    return -1;
}

int find_file(char *filename) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, filename) == 0) {
            return i;
        }
    }
    return -1;
}

void create_file(char *filename, int size) {
    if (num_files >= MAX_FILES) {
        printf("Maximum number of files reached\n");
        return;
    }

    if (find_file(filename) != -1) {
        printf("File already exists\n");
        return;
    }

    int num_blocks_needed = size / BLOCK_SIZE;
    if (size % BLOCK_SIZE != 0) {
        num_blocks_needed++;
    }

    if (num_blocks + num_blocks_needed >= MAX_BLOCKS) {
        printf("Disk space exceeded\n");
        return;
    }

    int start_block = find_free_block();
    if (start_block == -1) {
        printf("Disk space exceeded\n");
        return;
    }

    for (int i = 0; i < num_blocks_needed; i++) {
        int block_num = find_free_block();
        if (block_num == -1) {
            printf("Disk space exceeded\n");
            return;
        }
        blocks[block_num] = (block) {0};
        if (i == 0) {
            start_block = block_num;
        }
    }

    inode new_file = {.start_block = start_block, .num_blocks = num_blocks_needed};
    strcpy(new_file.name, filename);
    files[num_files++] = new_file;

    printf("File created successfully\n");
}

void read_file(char *filename) {
    int file_index = find_file(filename);
    if (file_index == -1) {
        printf("File not found\n");
        return;
    }

    inode file = files[file_index];
    int current_block = file.start_block;
    for (int i = 0; i < file.num_blocks; i++) {
        printf("%s", blocks[current_block].data);
        current_block++;
    }
}

void write_file(char *filename, char *data) {
    int file_index = find_file(filename);
    if (file_index == -1) {
        printf("File not found\n");
        return;
    }

    inode file = files[file_index];
    int current_block = file.start_block;

    for (int i = 0; i < file.num_blocks; i++) {
        strncpy(blocks[current_block].data, data, BLOCK_SIZE);
        data += BLOCK_SIZE;
        current_block++;
    }

    printf("File written successfully\n");
}

int main() {
    char command[16];

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            char filename[FILE_NAME_SIZE];
            int size;
            printf("Enter filename: ");
            scanf("%s", filename);
            printf("Enter file size: ");
            scanf("%d", &size);
            create_file(filename, size);
        } else if (strcmp(command, "read") == 0) {
            char filename[FILE_NAME_SIZE];
            printf("Enter filename: ");
            scanf("%s", filename);
            read_file(filename);
        } else if (strcmp(command, "write") == 0) {
            char filename[FILE_NAME_SIZE];
            printf("Enter filename: ");
            scanf("%s", filename);
            char data[BLOCK_SIZE * MAX_BLOCKS];
            printf("Enter file data: ");
            scanf("%s", data);
            write_file(filename, data);
        } else if (strcmp(command, "exit") == 0) {
            exit(0);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}