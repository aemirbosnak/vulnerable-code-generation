#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_image(char *image_data) {
    char buffer[1024];
    strcpy(buffer, image_data);
}

int main() {
    char input[2048];
    printf("Enter image data: ");
    gets(input); // Vulnerable to buffer overflow
    process_image(input);
    return 0;
}
