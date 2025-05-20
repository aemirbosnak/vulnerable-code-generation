//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define CHUNK_SIZE 1024

typedef struct {
    int fd;
    char *filename;
    char *buffer;
    int buffer_size;
    int buffer_offset;
} file_t;

file_t *open_file(char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return NULL;
    }

    file_t *file = malloc(sizeof(file_t));
    file->fd = fd;
    file->filename = strdup(filename);
    file->buffer = malloc(CHUNK_SIZE);
    file->buffer_size = CHUNK_SIZE;
    file->buffer_offset = 0;

    return file;
}

int read_chunk(file_t *file) {
    int bytes_read = read(file->fd, file->buffer + file->buffer_offset, file->buffer_size - file->buffer_offset);
    if (bytes_read == -1) {
        perror("read");
        return -1;
    }

    if (bytes_read == 0) {
        return 0;
    }

    file->buffer_offset += bytes_read;
    return 1;
}

int recover_file(file_t *file) {
    int chunk_count = 0;
    while (read_chunk(file) == 1) {
        chunk_count++;
    }

    printf("Recovered %d chunks from %s.\n", chunk_count, file->filename);

    close(file->fd);
    free(file->filename);
    free(file->buffer);
    free(file);

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file_t *file = open_file(argv[1]);
    if (file == NULL) {
        return 1;
    }

    recover_file(file);

    return 0;
}