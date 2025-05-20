#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int size;
} FileMetadata;

FileMetadata* metadata = NULL;
int allocated_size = 0;

void allocate_metadata(int size) {
    if (allocated_size >= size) return;
    metadata = realloc(metadata, size * sizeof(FileMetadata));
    if (!metadata) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    allocated_size = size;
}

void add_file(const char* name) {
    if (!metadata) {
        allocate_metadata(1);
    } else {
        int i = allocated_size - 1;
        while (i > 0 && strcmp(metadata[i].filename, "") != 0) i--;
        if (i == allocated_size - 1) {
            allocate_metadata(allocated_size + 1);
        }
    }
    strcpy(metadata[allocated_size - 1].filename, name);
    metadata[allocated_size - 1].size = strlen(name);
    metadata[allocated_size] = (FileMetadata){ "", 0 };
}

void remove_file(const char* name) {
    for (int i = 0; i < allocated_size; i++) {
        if (strcmp(metadata[i].filename, name) == 0) {
            strcpy(metadata[i].filename, "");
            metadata[i].size = 0;
            break;
        }
    }
}

void list_files() {
    for (int i = 0; i < allocated_size; i++) {
        if (strcmp(metadata[i].filename, "") != 0) {
            printf("File: %s, Size: %d\n", metadata[i].filename, metadata[i].size);
        }
    }
}

int main() {
    metadata = malloc(sizeof(FileMetadata));
    if (!metadata) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    add_file("example.txt");
    list_files();
    remove_file("example.txt");
    list_files();

    // Use-after-free vulnerability
    printf("%s\n", metadata->filename);

    free(metadata);
    metadata = NULL;

    // Trigger use-after-free
    printf("%s\n", metadata->filename); // Undefined behavior

    return 0;
}
