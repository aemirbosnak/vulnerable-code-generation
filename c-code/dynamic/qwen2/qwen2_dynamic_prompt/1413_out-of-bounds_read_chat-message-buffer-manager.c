#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

char buffer[BUFFER_SIZE];

void read_message(int index) {
    printf("Reading message at index %d: %s\n", index, &buffer[index]);
}

int main() {
    strcpy(buffer, "Hello, world!");

    // Simulate reading messages from an untrusted source
    int indices[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int num_indices = sizeof(indices) / sizeof(indices[0]);

    for (int i = 0; i < num_indices; i++) {
        read_message(indices[i]);
    }

    return 0;
}
