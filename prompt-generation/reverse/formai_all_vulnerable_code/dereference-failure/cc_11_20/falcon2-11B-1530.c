//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    const char *ext = strrchr(filename, '.');
    if (ext == NULL || strcmp(ext, ".o")!= 0) {
        fprintf(stderr, "Not a valid object file.\n");
        return 1;
    }

    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    char *buf = NULL;
    size_t size = 0;
    off_t off = 0;

    int res = posix_fadvise(fd, 0, 0, POSIX_FADV_DONTNEED);
    if (res!= 0) {
        perror("posix_fadvise");
        return 1;
    }

    size = lseek(fd, 0, SEEK_END);
    if (size < 0) {
        perror("lseek");
        return 1;
    }

    buf = (char *)mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, off);
    if (buf == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    const char *metadata_start = strstr(buf, ".metadata");
    if (metadata_start == NULL) {
        fprintf(stderr, "Metadata not found.\n");
        return 1;
    }

    metadata_start += 9;
    const char *metadata_end = strstr(metadata_start, ".metadata");
    if (metadata_end == NULL) {
        fprintf(stderr, "Metadata not found.\n");
        return 1;
    }

    size_t metadata_size = metadata_end - metadata_start;
    if (metadata_size == 0) {
        fprintf(stderr, "Metadata not found.\n");
        return 1;
    }

    const char *metadata_data = metadata_start;

    printf("Metadata size: %zu bytes\n", metadata_size);
    printf("Metadata data:\n%s", metadata_data);

    munmap(buf, size);
    close(fd);
    return 0;
}