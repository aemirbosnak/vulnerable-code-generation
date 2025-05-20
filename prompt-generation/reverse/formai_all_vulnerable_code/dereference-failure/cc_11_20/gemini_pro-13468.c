//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

typedef struct {
    char *name;
    off_t offset;
    size_t size;
} metadata_entry;

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) < 0) {
        perror("fstat");
        return 1;
    }

    char *map = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Scan the file for metadata entries.
    metadata_entry entries[100];
    int num_entries = 0;
    for (off_t offset = 0; offset < st.st_size;) {
        // Look for the start of a metadata entry.
        while (offset < st.st_size && map[offset] != '|') {
            offset++;
        }

        // Check if we reached the end of the file.
        if (offset == st.st_size) {
            break;
        }

        // Get the name of the metadata entry.
        char *name = &map[offset+1];
        while (offset < st.st_size && map[offset] != '|') {
            offset++;
        }
        map[offset] = '\0';

        // Get the offset of the metadata entry.
        offset++;
        off_t offset_num = 0;
        while (offset < st.st_size && map[offset] != '|') {
            offset_num *= 10;
            offset_num += map[offset] - '0';
            offset++;
        }

        // Get the size of the metadata entry.
        offset++;
        size_t size_num = 0;
        while (offset < st.st_size && map[offset] != '|') {
            size_num *= 10;
            size_num += map[offset] - '0';
            offset++;
        }

        // Add the metadata entry to the list.
        entries[num_entries].name = name;
        entries[num_entries].offset = offset_num;
        entries[num_entries].size = size_num;
        num_entries++;
    }

    // Print the metadata entries.
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %ld, %ld\n", entries[i].name, entries[i].offset, entries[i].size);
    }

    // Unmap the file.
    munmap(map, st.st_size);

    // Close the file.
    close(fd);

    return 0;
}