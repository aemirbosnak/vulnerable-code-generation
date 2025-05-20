#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
    size_t length;
} CompressedData;

CompressedData compress(const char *input) {
    CompressedData result;
    result.data = (char *)malloc(BUFFER_SIZE);
    if (!result.data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    result.length = strlen(input);
    strcpy(result.data, input);
    return result;
}

void decompress(CompressedData *cd) {
    printf("Decompressed: %s\n", cd->data);
    free(cd->data);
    cd->data = NULL; // Freeing the memory
}

int main() {
    const char *original = "This is a test string to demonstrate a use-after-free vulnerability.";
    CompressedData compressed = compress(original);

    // Use after free vulnerability
    printf("Original: %s\n", compressed.data); // This line should cause undefined behavior

    decompress(&compressed);

    // Attempt to access freed memory
    printf("After free: %s\n", compressed.data); // This line will likely crash the program

    return 0;
}
