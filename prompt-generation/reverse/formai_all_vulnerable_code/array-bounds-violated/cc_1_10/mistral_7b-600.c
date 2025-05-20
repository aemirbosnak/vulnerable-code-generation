//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#define OFFSET_MAGIC 0xDEADBEEF
#define SIZE_MAGIC 0xDEADBABE

typedef struct {
    unsigned int offset;
    unsigned int size;
} metadata;

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int fd;
    char *file_map;
    unsigned int magic;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <binary_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) die("open");

    file_map = mmap(NULL, getpagesize(), PROT_READ, MAP_PRIVATE, fd, 0);
    if (file_map == MAP_FAILED) die("mmap");

    if (read(fd, &magic, sizeof(magic)) != sizeof(magic)) {
        fprintf(stderr, "Invalid magic number in file\n");
        exit(EXIT_FAILURE);
    }
    close(fd);

    if (magic != OFFSET_MAGIC) {
        fprintf(stderr, "Invalid metadata format\n");
        munmap(file_map, getpagesize());
        exit(EXIT_FAILURE);
    }

    printf("Structure metadata:\n");
    while (1) {
        metadata md;

        if (read(fileno(stdin), &md, sizeof(md)) != sizeof(md)) {
            if (feof(stdin)) break;
            die("read");
        }

        printf("Field name: ");
        char name[32];
        fgets(name, sizeof(name), stdin);
        name[strlen(name) - 1] = '\0';

        printf("Offset: 0x%x\n", md.offset);
        printf("Size: %d bytes\n", md.size);
        printf("Name: %s\n", name);
    }

    munmap(file_map, getpagesize());

    return EXIT_SUCCESS;
}