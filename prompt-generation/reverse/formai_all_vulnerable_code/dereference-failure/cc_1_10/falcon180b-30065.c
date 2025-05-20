//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1 MB

typedef struct {
    char filename[256];
    char checksum[32];
} file_checksum_t;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("Error: file is too large (%ld bytes)\n", file_size);
        fclose(file);
        return 1;
    }

    fseek(file, 0, SEEK_SET);
    unsigned char buffer[1024];
    size_t bytes_read;

    file_checksum_t checksum;
    strcpy(checksum.filename, filename);

    unsigned char checksum_value = 0;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            checksum_value += buffer[i];
        }
    }

    sprintf(checksum.checksum, "%02X", checksum_value);

    printf("Checksum for file '%s': %s\n", filename, checksum.checksum);

    fclose(file);
    return 0;
}