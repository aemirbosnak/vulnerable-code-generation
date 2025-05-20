#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void sync_files(char *source, char *destination) {
    FILE *src_file = fopen(source, "r");
    if (!src_file) {
        perror("Failed to open source file");
        return;
    }

    FILE *dest_file = fopen(destination, "w");
    if (!dest_file) {
        perror("Failed to open destination file");
        fclose(src_file);
        return;
    }

    char buffer[1024];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);

    // Intentional invalid pointer dereference
    int *ptr = NULL;
    printf("%d\n", *ptr); // Dereferencing null pointer

    return 0;
}
