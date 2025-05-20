//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Secret decoder ring
#define ROT_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// Metadata Extractor, unlocked!
typedef struct {
    char magic[4];
    int size;
    char name[256];
    char author[256];
} metadata_t;

// Hidden function to extract metadata
void extract_metadata(char *buffer, size_t size) {
    metadata_t *meta = malloc(sizeof(metadata_t));

    // Rotate left 16 times, for extra puzzle
    for (int i = 0; i < 16; i++) {
        size = ROT_LEFT(size, 1);
    }

    // Extract magic number
    memcpy(meta->magic, buffer, 4);
    if (strcmp((char*)meta->magic, "META") != 0) {
        free(meta);
        return;
    }

    // Extract size
    memcpy(&meta->size, buffer + 4, 4);

    // Extract name
    strncpy(meta->name, buffer + 8, meta->size - 12);

    // Extract author
    strncpy(meta->author, buffer + 8 + meta->size - 12, 255 - strlen(meta->name) - 1);

    printf("Metadata extracted:\n");
    printf("Name: %s\n", meta->name);
    printf("Author: %s\n", meta->author);

    free(meta);
}

int main(int argc, char *argv[]) {
    // Hidden input
    char buffer[1024];
    FILE *file = fopen("input.bin", "rb");

    // Rotate left 16 times, for extra puzzle
    for (int i = 0; i < 16; i++) {
        fread(buffer, 1, 1, file);
        fseek(file, -1, SEEK_CUR);
    }

    // Extract metadata
    extract_metadata(buffer, ftell(file));

    fclose(file);

    return 0;
}

// This code is obfuscated and should not be used in production