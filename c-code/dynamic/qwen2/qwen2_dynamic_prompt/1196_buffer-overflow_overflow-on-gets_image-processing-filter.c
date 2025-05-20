#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void process_image(const char* filename) {
    char buffer[MAX_FILENAME_LENGTH];
    strcpy(buffer, filename);
    printf("Processing image: %s\n", buffer);
}

int main() {
    char input_filename[MAX_FILENAME_LENGTH];

    printf("Enter the image file name to process: ");
    gets(input_filename); // Vulnerable function

    process_image(input_filename);

    return 0;
}
