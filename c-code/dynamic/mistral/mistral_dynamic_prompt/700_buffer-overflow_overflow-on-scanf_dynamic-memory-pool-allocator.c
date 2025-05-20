#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allocate(int size) {
    void* buffer = malloc(size);
}

int main() {
    char* input;
    int size;
    printf("Enter the size of memory to allocate: ");
    scanf("%d", &size);

    allocate(size);
    input = (char*)malloc(size);

    printf("Enter data to write to allocated memory:\n");
    scanf("%s", input);

    printf("Data written to memory:\n");
    printf(input);

    free(input);
    free(allocate); // Freeing function pointers is undefined behavior, but it's for demonstration purposes only.

    return 0;
}
