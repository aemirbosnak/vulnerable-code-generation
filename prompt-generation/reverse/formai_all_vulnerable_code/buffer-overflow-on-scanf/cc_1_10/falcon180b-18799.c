//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BLOCK_SIZE 1024
#define MAX_FILE_SIZE (1024 * 1024)

struct file_header {
    char magic[8];
    int version;
    int num_blocks;
    int block_size;
};

struct block_header {
    int index;
    int size;
};

int read_block(int fd, int index, void *buffer) {
    struct block_header bh;
    lseek(fd, index * sizeof(struct block_header), SEEK_SET);
    read(fd, &bh, sizeof(struct block_header));
    lseek(fd, bh.index * bh.size, SEEK_SET);
    read(fd, buffer, bh.size);
    return bh.size;
}

int write_block(int fd, int index, void *buffer, int size) {
    struct block_header bh;
    bh.index = index;
    bh.size = size;
    lseek(fd, index * sizeof(struct block_header), SEEK_SET);
    write(fd, &bh, sizeof(struct block_header));
    lseek(fd, bh.index * bh.size, SEEK_SET);
    write(fd, buffer, bh.size);
    return bh.size;
}

int main() {
    int fd;
    char filename[32];
    printf("Enter the filename to recover: ");
    scanf("%s", filename);

    fd = open(filename, O_RDWR);
    if (fd == -1) {
        printf("Error opening file.\n");
        return 1;
    }

    struct file_header fh;
    read(fd, &fh, sizeof(struct file_header));

    if (strncmp(fh.magic, "CDFR", 4)!= 0) {
        printf("Invalid file format.\n");
        close(fd);
        return 1;
    }

    int num_blocks = fh.num_blocks;
    int block_size = fh.block_size;

    if (num_blocks > MAX_FILE_SIZE / block_size) {
        printf("File too large.\n");
        close(fd);
        return 1;
    }

    void *buffer = malloc(MAX_BLOCK_SIZE);

    for (int i = 0; i < num_blocks; i++) {
        int size = read_block(fd, i, buffer);
        if (size == -1) {
            printf("Error reading block.\n");
            free(buffer);
            close(fd);
            return 1;
        }
        if (size!= block_size) {
            printf("Invalid block size.\n");
            free(buffer);
            close(fd);
            return 1;
        }
    }

    free(buffer);
    close(fd);

    printf("File recovered successfully!\n");
    return 0;
}