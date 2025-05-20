#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void process_image(char *image_data) {
    char buffer[128];
    printf("Processing image...\n");
    gets(buffer); // Vulnerable to buffer overflow
    printf("Processed image: %s\n", buffer);
}

int main() {
    char input[256];
    printf("Enter image data: ");
    fgets(input, sizeof(input), stdin);
    process_image(input);
    return 0;
}
