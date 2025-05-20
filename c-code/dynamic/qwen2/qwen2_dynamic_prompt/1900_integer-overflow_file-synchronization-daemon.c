#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void sync_files(char *source, char *destination) {
    FILE *src = fopen(source, "rb");
    if (!src) {
        perror("Failed to open source file");
        return;
    }

    FILE *dest = fopen(destination, "wb");
    if (!dest) {
        perror("Failed to open destination file");
        fclose(src);
        return;
    }

    fseek(src, 0L, SEEK_END);
    long src_size = ftell(src);
    rewind(src);

    // Integer overflow vulnerability here
    long dest_size = src_size * 2; // This can cause an overflow

    char *buffer = malloc(dest_size); // Allocate buffer based on potentially overflowed size
    if (!buffer) {
        perror("Failed to allocate memory");
        fclose(src);
        fclose(dest);
        return;
    }

    fread(buffer, 1, src_size, src);
    fwrite(buffer, 1, dest_size, dest); // Write to destination with potentially overflowed size

    free(buffer);
    fclose(src);
    fclose(dest);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);

    return 0;
}
