#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_image(char *image_data, int width, int height) {
    char buffer[10];
    int r, c;

    for (r = 0; r < height; ++r) {
        for (c = 0; c < width; ++c) {
            printf("Enter RGB value (R B G): ");
            scanf("%s%s%s", buffer, buffer + 3, buffer + 6);

            // Process the RGB value here (for example, convert to grayscale)
            int rgb = (buffer[0] - '0') * 16 + (buffer[1] - '0') * 4 + (buffer[2] - '0');
            int gray = rgb * 0.34 + 51;

            image_data[(r * width + c) * 3 + 0] = gray < 16 ? gray + 10 : gray;
            image_data[(r * width + c) * 3 + 1] = gray < 16 ? gray + 10 : gray;
            image_data[(r * width + c) * 3 + 2] = gray < 16 ? gray + 10 : gray;
        }
    }
}

int main() {
    const int width = 10, height = 10;
    char image_data[width * height * 3];

    process_image(image_data, width, height);

    return 0;
}
