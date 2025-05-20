//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define BLOCK_SIZE 512

struct block {
    char data[BLOCK_SIZE];
    int is_valid;
};

int read_block(int fd, int block_num, struct block *block) {
    lseek(fd, block_num * BLOCK_SIZE, SEEK_SET);
    if (read(fd, block->data, BLOCK_SIZE)!= BLOCK_SIZE) {
        perror("read_block");
        return -1;
    }
    block->is_valid = 1;
    return 0;
}

int write_block(int fd, int block_num, struct block *block) {
    lseek(fd, block_num * BLOCK_SIZE, SEEK_SET);
    if (write(fd, block->data, BLOCK_SIZE)!= BLOCK_SIZE) {
        perror("write_block");
        return -1;
    }
    block->is_valid = 1;
    return 0;
}

int main() {
    int fd;
    char filename[64];
    printf("Enter the name of the file to recover: ");
    scanf("%s", filename);

    fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    printf("Recovering file...\n");
    struct block blocks[100];
    int num_blocks = 0;

    for (int i = 0; i < 100; i++) {
        if (read_block(fd, i, &blocks[i]) == -1) {
            printf("Error reading block %d\n", i);
            return 1;
        }
        if (!blocks[i].is_valid) {
            printf("Block %d is invalid\n", i);
            return 1;
        }
        num_blocks++;
    }

    printf("File recovery complete!\n");
    close(fd);
    return 0;
}