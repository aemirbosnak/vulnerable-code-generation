//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>

#define BLOCK_SIZE 512
#define HEADER_SIZE 16
#define MAX_BLOCKS 1024

typedef struct {
    char name[HEADER_SIZE];
    int size;
    int blocks[MAX_BLOCKS];
} file_header;

typedef struct {
    char data[BLOCK_SIZE];
} data_block;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image file> <output directory> <recovery file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *image_file = argv[1];
    char *output_dir = argv[2];
    char *recovery_file = argv[3];

    int fd = open(image_file, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        exit(EXIT_FAILURE);
    }

    int num_blocks = st.st_size / BLOCK_SIZE;

    data_block *blocks = malloc(sizeof(data_block) * num_blocks);
    if (blocks == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_blocks; i++) {
        if (read(fd, blocks[i].data, BLOCK_SIZE) != BLOCK_SIZE) {
            perror("read");
            exit(EXIT_FAILURE);
        }
    }

    close(fd);

    mkdir(output_dir, 0755);

    FILE *fp = fopen(recovery_file, "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *name = strtok(line, ":");
        char *size_str = strtok(NULL, ":");
        char *blocks_str = strtok(NULL, "\n");

        int size = atoi(size_str);
        int *blocks_arr = malloc(sizeof(int) * size);
        if (blocks_arr == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        char *block_str = strtok(blocks_str, ",");
        for (int i = 0; i < size; i++) {
            blocks_arr[i] = atoi(block_str);
            block_str = strtok(NULL, ",");
        }

        FILE *out_fp = fopen(output_dir, "w");
        if (out_fp == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < size; i++) {
            fwrite(blocks[blocks_arr[i]].data, BLOCK_SIZE, 1, out_fp);
        }

        fclose(out_fp);
    }

    fclose(fp);

    free(blocks);

    return EXIT_SUCCESS;
}