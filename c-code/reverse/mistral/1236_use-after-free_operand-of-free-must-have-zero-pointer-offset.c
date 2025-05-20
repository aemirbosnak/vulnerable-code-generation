#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_data(char *data, size_t size) {
    char *temp = realloc(data, size * 2);
    if (!temp) {
        fprintf(stderr, "Failed to reallocate memory\n");
        exit(1);
    }

    data = temp;

    // Use-after-free vulnerability: free(data + size);
    free(data);

    // Additional malloc and free operations
    char *new_data = malloc(size * 3);
    if (!new_data) {
        fprintf(stderr, "Failed to allocate new memory\n");
        exit(1);
    }

    strcpy(new_data, "New data");

    free(data); // Free the rest of the memory

    // Accessing the freed memory before freeing the rest
    printf("Data: %s\n", data);
}

int main() {
    char *data = malloc(10);
    if (!data) {
        fprintf(stderr, "Failed to allocate initial memory\n");
        return 1;
    }

    strcpy(data, "Original data");

    process_data(data, strlen(data) + 1);

    free(data);

    return 0;
}
