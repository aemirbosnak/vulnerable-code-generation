#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void migrate_data(char *filename) {
    FILE *src, *dst;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    src = fopen(filename, "rb");
    if (!src) {
        printf("Error: Could not open source file.\n");
        return;
    }

    dst = fopen("output.txt", "wb");
    if (!dst) {
        printf("Error: Could not open destination file.\n");
        fclose(src);
        return;
    }

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        // This is where the vulnerability lies. No bounds checking before writing to 'buffer'.
        fwrite(buffer, bytes_read, 1, dst);
    }

    fclose(src);
    fclose(dst);

    printf("Data migration complete.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <source_file>\n", argv[0]);
        return 1;
    }

    migrate_data(argv[1]);

    return 0;
}
