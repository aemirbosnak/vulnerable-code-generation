//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct metadata {
    unsigned int magic;
    unsigned int version;
    unsigned int offset;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        return 1;
    }

    if (st.st_size < sizeof(struct metadata)) {
        fprintf(stderr, "File is too small to contain metadata\n");
        return 1;
    }

    struct metadata md;
    if (read(fd, &md, sizeof(md)) != sizeof(md)) {
        perror("read");
        return 1;
    }

    if (md.magic != 0x4D4D4D4D) {
        fprintf(stderr, "Invalid metadata magic number\n");
        return 1;
    }

    if (md.version != 1) {
        fprintf(stderr, "Unsupported metadata version\n");
        return 1;
    }

    if (md.offset >= st.st_size) {
        fprintf(stderr, "Invalid metadata offset\n");
        return 1;
    }

    char *data = malloc(st.st_size - md.offset);
    if (data == NULL) {
        perror("malloc");
        return 1;
    }

    if (lseek(fd, md.offset, SEEK_SET) == -1) {
        perror("lseek");
        return 1;
    }

    if (read(fd, data, st.st_size - md.offset) != st.st_size - md.offset) {
        perror("read");
        return 1;
    }

    printf("Metadata:\n");
    printf("  Magic: 0x%08X\n", md.magic);
    printf("  Version: %u\n", md.version);
    printf("  Offset: %u\n", md.offset);

    printf("Data:\n");
    printf("%s", data);

    free(data);
    close(fd);

    return 0;
}