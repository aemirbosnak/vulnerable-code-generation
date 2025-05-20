//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BLOCK_SIZE 512
#define MAX_BLOCKS 100

struct block {
    char data[BLOCK_SIZE];
    int next;
};

struct book {
    int num_blocks;
    struct block blocks[MAX_BLOCKS];
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <book file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        close(fd);
        return EXIT_FAILURE;
    }

    if (st.st_size % BLOCK_SIZE != 0) {
        fprintf(stderr, "Book file is not a multiple of block size\n");
        close(fd);
        return EXIT_FAILURE;
    }

    int num_blocks = st.st_size / BLOCK_SIZE;
    struct book book;
    book.num_blocks = num_blocks;

    for (int i = 0; i < num_blocks; i++) {
        if (read(fd, book.blocks[i].data, BLOCK_SIZE) != BLOCK_SIZE) {
            perror("read");
            close(fd);
            return EXIT_FAILURE;
        }
        book.blocks[i].next = i + 1;
    }

    close(fd);

    int current_block = 0;
    while (current_block != -1) {
        printf("%s", book.blocks[current_block].data);
        current_block = book.blocks[current_block].next;
    }

    return EXIT_SUCCESS;
}