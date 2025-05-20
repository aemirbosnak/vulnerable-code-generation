#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILTER_SIZE 10

void apply_filter(char *image, int size) {
    char buffer[MAX_FILTER_SIZE];
    gets(buffer); // Vulnerable to buffer overflow
    for (int i = 0; i < size; i++) {
        image[i] += buffer[i % MAX_FILTER_SIZE];
    }
}

int main() {
    char image[100];
    int size = 100;

    printf("Enter image data: ");
    fgets(image, sizeof(image), stdin);

    printf("Applying filter...\n");
    apply_filter(image, size);

    printf("Processed image data: %s\n", image);

    return 0;
}
