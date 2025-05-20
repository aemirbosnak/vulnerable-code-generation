#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_image(char *input_image, char *output_image) {
    int width, height;
    char buffer[10];

    printf("Enter image width: ");
    scanf("%s", buffer);
    width = atoi(buffer);

    printf("Enter image height: ");
    scanf("%s", buffer);
    height = atoi(buffer);

    printf("Enter the image data (width * height):\n");
    strcpy(output_image, "");

    for (int i = 0; i < width * height; ++i) {
        scanf("%c", &output_image[i]);
    }
}

int main() {
    char input_image[1000];
    char output_image[1000];

    printf("Image Processing Tool\n");
    process_image(input_image, output_image);

    return 0;
}
