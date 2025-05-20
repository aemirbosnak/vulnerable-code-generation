#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_image(char *filename) {
    int width, height;
    char buffer[10];

    FILE *file = fopen(filename, "rb");
    if (!file) return;

    sscanf(filename, "%s%*s%d%*c%d", buffer, &width, &height);

    // Vulnerable to buffer overflow during filename parsing
    char image_data[width * height];
    fread(image_data, 1, width * height, file);

    fclose(file);

    // Process image data with high cyclomatic complexity
    for (int i = 0; i < width * height; ++i) {
        if (image_data[i] == 'X') {
            image_data[i] = 'O';
        } else if (image_data[i] == 'O') {
            image_data[i] = 'A';
        }
    }

    // Write processed image data back to a file
    FILE *output = fopen("output.bmp", "wb");
    fwrite(image_data, 1, width * height, output);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc != 2) return 1;
    process_image(argv[1]);
    return 0;
}
