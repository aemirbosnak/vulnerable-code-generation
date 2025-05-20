#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void process_image(char *image_data, int width, int height) {
    char buffer[128];
    printf("Enter filter parameters: ");
    gets(buffer); // Vulnerable to buffer overflow

    if (buffer[0] == 'g') {
        // Apply Gaussian blur
        printf("Applying Gaussian blur...\n");
    } else if (buffer[0] == 's') {
        // Apply sharpening filter
        printf("Applying sharpening filter...\n");
    } else {
        printf("Unknown filter type.\n");
    }
}

int main() {
    char image_data[1024];
    int width = 640;
    int height = 480;

    printf("Loading image data...\n");

    // Simulate loading image data
    for (int i = 0; i < sizeof(image_data); i++) {
        image_data[i] = rand() % 256;
    }

    process_image(image_data, width, height);

    return 0;
}
