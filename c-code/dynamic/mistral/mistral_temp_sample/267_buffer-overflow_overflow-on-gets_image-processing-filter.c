#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

void process_image(char *image_data, int width, int height) {
    char input[MAX_INPUT_SIZE];
    char buffer[10];

    printf("Enter custom filter name (up to 10 characters):\n");
    gets(input);
    strcpy(buffer, input);

    // Simulate image processing with the user-provided filter
    // ...

    // Vulnerable code: buffer overflow
    strcpy(buffer, image_data);
}

int main() {
    char image_data[1024];
    printf("Enter image data (up to 1024 characters):\n");
    fgets(image_data, sizeof(image_data), stdin);

    process_image(image_data, 10, 10);

    return 0;
}
