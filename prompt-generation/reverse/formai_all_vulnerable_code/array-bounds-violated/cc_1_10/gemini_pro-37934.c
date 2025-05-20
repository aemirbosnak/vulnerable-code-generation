//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_BLOCKS 1024
#define MAX_FILES 16

typedef struct {
    char name[32];
    int size;
    int blocks[MAX_BLOCKS];
} File;

typedef struct {
    File files[MAX_FILES];
    int num_files;
    char data[MAX_BLOCKS * BLOCK_SIZE];
} FileSystem;

FileSystem fs;

void init_fs() {
    fs.num_files = 0;
}

int create_file(char *name) {
    if (fs.num_files >= MAX_FILES) {
        return -1;
    }

    strcpy(fs.files[fs.num_files].name, name);
    fs.files[fs.num_files].size = 0;
    fs.files[fs.num_files].blocks[0] = -1;

    fs.num_files++;

    return 0;
}

int write_file(char *name, char *data, int size) {
    int i, j, k;
    int block_index;
    int num_blocks;

    for (i = 0; i < fs.num_files; i++) {
        if (strcmp(fs.files[i].name, name) == 0) {
            fs.files[i].size += size;
            num_blocks = (fs.files[i].size + BLOCK_SIZE - 1) / BLOCK_SIZE;

            if (num_blocks > MAX_BLOCKS) {
                return -1;
            }

            block_index = fs.files[i].blocks[num_blocks - 1];

            for (j = num_blocks - 1; j > 0; j--) {
                fs.files[i].blocks[j] = fs.files[i].blocks[j - 1];
            }

            fs.files[i].blocks[0] = block_index;

            for (k = 0; k < size; k++) {
                fs.data[block_index * BLOCK_SIZE + k] = data[k];
                block_index++;
            }

            return 0;
        }
    }

    return -1;
}

int read_file(char *name, char *data, int size) {
    int i, j, k;
    int block_index;
    int num_blocks;

    for (i = 0; i < fs.num_files; i++) {
        if (strcmp(fs.files[i].name, name) == 0) {
            num_blocks = (fs.files[i].size + BLOCK_SIZE - 1) / BLOCK_SIZE;

            if (size > fs.files[i].size) {
                return -1;
            }

            block_index = fs.files[i].blocks[0];

            for (j = 0; j < size; j++) {
                data[j] = fs.data[block_index * BLOCK_SIZE + j];
                block_index++;
            }

            return 0;
        }
    }

    return -1;
}

int delete_file(char *name) {
    int i, j;

    for (i = 0; i < fs.num_files; i++) {
        if (strcmp(fs.files[i].name, name) == 0) {
            for (j = 0; j < fs.files[i].size; j++) {
                fs.data[fs.files[i].blocks[j] * BLOCK_SIZE] = 0;
            }

            for (j = i; j < fs.num_files - 1; j++) {
                fs.files[j] = fs.files[j + 1];
            }

            fs.num_files--;

            return 0;
        }
    }

    return -1;
}

int main() {
    init_fs();

    create_file("file1");
    write_file("file1", "Hello, world!", 13);

    char data[BLOCK_SIZE];
    read_file("file1", data, BLOCK_SIZE);

    printf("%s\n", data);

    delete_file("file1");

    return 0;
}