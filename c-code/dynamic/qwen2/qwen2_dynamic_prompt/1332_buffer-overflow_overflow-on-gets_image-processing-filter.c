#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void process_image(char *image_data, int width, int height) {
    char buffer[1024];
    printf("Enter filter parameters: ");
    gets(buffer); // Vulnerable to buffer overflow

    if (buffer[0] == 'g') {
        // Apply Gaussian blur
        printf("Applying Gaussian blur...\n");
    } else if (buffer[0] == 's') {
        // Apply sharpening filter
        printf("Applying sharpening filter...\n");
    } else {
        printf("Unknown filter\n");
    }
}

int main() {
    char image_data[1024];
    int width = 800;
    int height = 600;

    printf("Loading image data...\n");

    process_image(image_data, width, height);

    return 0;
}
