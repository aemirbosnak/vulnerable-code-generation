#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256

void process_image(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    int width, height;
    fscanf(file, "%d %d", &width, &height);

    // Vulnerability: No bounds checking on width and height
    int pixels[width * height];

    for (int i = 0; i < width * height; i++) {
        fscanf(file, "%d", &pixels[i]);
    }

    fclose(file);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the image file name: ");
    fgets(filename, sizeof(filename), stdin);

    // Remove newline character from input
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }

    process_image(filename);

    return 0;
}
