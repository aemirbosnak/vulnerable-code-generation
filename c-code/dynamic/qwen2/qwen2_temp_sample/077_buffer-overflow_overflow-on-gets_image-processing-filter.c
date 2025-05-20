#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_image(char *image_data, int width, int height) {
    char buffer[1024];
    strcpy(buffer, image_data);
}

int main() {
    char input[2048];
    printf("Enter image data: ");
    gets(input); // Vulnerability here

    int width = 640;
    int height = 480;

    process_image(input, width, height);

    return 0;
}
