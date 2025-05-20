#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
} FileEntry;

void syncFiles(FileEntry *entries, int count) {
    for (int i = 0; i < count; i++) {
        // Simulate file processing
        printf("Processing file: %s\n", entries[i].data);
    }
}

int main() {
    FileEntry *entries = malloc(BUFFER_SIZE * sizeof(FileEntry));
    if (!entries) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Initialize file entries
    for (int i = 0; i < BUFFER_SIZE; i++) {
        entries[i].data = strdup("example.txt");
    }

    // Simulate file synchronization
    syncFiles(entries, BUFFER_SIZE);

    // Free allocated memory
    for (int i = 0; i < BUFFER_SIZE; i++) {
        free(entries[i].data);
    }

    // Use after free vulnerability
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%s\n", entries[i].data); // Access freed memory
    }

    free(entries);

    return EXIT_SUCCESS;
}
